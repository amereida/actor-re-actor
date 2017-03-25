#include <Stepper.h>
#include <AccelStepper.h>
/////////////////////// VARIBLES DE AJUSTE DE MEDIDAS (AJUSTAR) ////////////////////

int MINIMA_DISTANCIAcm=20;   //sensor de distancia 
int MAXIMA_DISTANCIAcm=600;  //sensor de distancia
int DIF_MIN_MEDIDAS =15;     //variacion minima que debe haber entre dos medidas consecutivas para que actue el motor

int full_dim=30;  // 5   maxima intensidad de luz
int empty_dim=110; //128  miniam intensidad de luz

float CORDON_cm= 10; 

int NUM_MAX_PASOS=22000;// <-------------------DEFINIR AL COMIENZO DEL MONTAJE, desde una posicion inicial, es el numero máximo de pasos

//////////////////////VARIABLES FIJAS DE CALCULO/////////////////////////////
int PPR=400;    //PASOS POR REVOLUCION
float PERIMETROmm= 188.49;  //PERIMETRO RUEDA P=2*R*PI.....por vuelta avanza esto    

int cordon_pasos;
int PASOS_DE_SEGURIDAD=50;
int MIN_PASOS_SEGUR= PASOS_DE_SEGURIDAD;
int MAX_PASOS_SEGUR= NUM_MAX_PASOS-PASOS_DE_SEGURIDAD;

int exact_cm_value1=0;
int exact_cm_value2=0;
int condicion=0;
int PASOS=0;
int MEDIDAS[]={0,0};

////////////////////////// VARIABLES DEL MOTOR ////////////////////////////////

const int stepsPerRevolution = 800;  // pasos por rev
Stepper myStepper(stepsPerRevolution, 8, 9); // initialize the stepper library on pins 8 through 11:
AccelStepper stepper(2, 9, 8);   //LIB ACCEL

///////////////////VARIABLES SENSOR DE DISTANCIA////////////////////////////////////
int pw_pin=7;   //PIN UTILIZADO
int arraysize = 5;  //N° DE DATOS EN EL VECTOR (prog orig 9 datos)
int array[] = { 0, 0, 0, 0, 0};
long inch;   //variable de almacenamiento de pulgadas
int exact_cm_value;   //variable de almacenamiento de valores en cm

//////////////////BOTONES MANUALES////////////////////
int reloj=11;  //pin boton para accionar en sentido reloj
int antireloj=12;  //pin boton para accionar en sentido antireloj
int manual=3;  // pin boton manual
int led=13;    //led de modo manual o automatico
int R;    //variable de almacenamiento del boton RELOJ
int AR;   //variable de almacenamiento del boton ANTIRELOJ
int pot=A0;  //pin donde va conectado el pot para controlar el dimmer

///////////////////VARIABLES DIMMER////////////////////
int AC_LOAD = 5;    // Output to Opto Triac pin
int dimming = 128;  // Dimming level (0-128)  0 = ON, 128 = OFF

////////////////////////////////////////////////////////////
void sensorRead()   //se hace una lectura cada 10 miliseg de cuando pasa de high a low y lo divide por un factor
{
  for(int i = 0; i < arraysize; i++)
  {
  inch = pulseIn(pw_pin, HIGH);
  array[i] = inch/58;
  delay(1);
  }
  array_arrangment(array,arraysize);
  exact_cm_value= filter(array,arraysize);  //VARIABLE EN CENTIMETROS DE LA DISTANCIA
}
//////////////////////////////////////////////////////////////
void array_arrangment(int *a,int n)
{
  for (int i = 1; i < n; ++i)
    {
      int j = a[i];
      int k;
      for (k = i - 1; (k >= 0) && (j < a[k]); k--)
        {
        a[k + 1] = a[k];
        }
      a[k + 1] = j;
    }
}
//////////////////////////////////////////////////////////////
int filter(int *a,int n)
{
    int i = 0;
    int count = 0;
    int maxCount = 0;
    int filter = 0;
    int median;
    int prevCount = 0;
    while(i<(n-1))
    {
        prevCount=count;
        count=0;
        while(a[i]==a[i+1])
          {
          count++;
          i++;
          }
        if(count>prevCount && count>maxCount)
          {
          filter=a[i];
          maxCount=count;
          median=0;
          }
        if(count==0)
          {
          i++;
          }
        if(count==maxCount)
          {//If the dataset has 2 or more modes.
          median=1;
          }
        if(filter==0||median==1)
          {//Return the median if there is no mode.
          filter=a[(n/2)];
          }        
        return filter;    
    }
}
///////////////////////// DIMMER ////////////////////////////////////////

//the interrupt function must take no parameters and return nothing
  // Firing angle calculation : 1 full 50Hz wave =1/50=20ms 
  // Every zerocrossing thus: (50Hz)-> 10ms (1/2 Cycle) 
  // For 60Hz => 8.33ms (10.000/120)
  // 10ms=10000us
  // (10000us - 10us) / 128 = 75 (Approx) For 60Hz =>65
  
void zero_crosss_int()  //function to be fired at the zero crossing to dim the light
{
  int dimtime = (75*dimming);    // For 60Hz =>65    
  delayMicroseconds(dimtime);    // Wait till firing the TRIAC    
  digitalWrite(AC_LOAD, HIGH);   // Fire the TRIAC
  delayMicroseconds(10);         // triac On propogation delay 
         // (for 60Hz use 8.33) Some Triacs need a longer period
  digitalWrite(AC_LOAD, LOW);    // No longer trigger the TRIAC (the next zero crossing will swith it off) TRIAC
}

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
void setup() 
{  
  myStepper.setSpeed(200); // set the speed at 60 rpm:
  pinMode(pw_pin, INPUT);  //definición del pin sensor
  Serial.begin(9600);
  stepper.setMaxSpeed(6000.0);  //LIB ACCEL
  stepper.setAcceleration(6000.0);  //LIB ACCEL
  
  pinMode(reloj,INPUT);
  pinMode(antireloj,INPUT);
  pinMode(manual,INPUT);
  pinMode(led,OUTPUT);

  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);  // Choose the zero cross interrupt # from the table above
  cordon_pasos= (CORDON_cm*PPR)/(PERIMETROmm*10) ; // CALCULO dependiendo de los centrimetros ingresados en CORDON_cm calcula la cantidad de pasos
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void loop() 
{                                      
 if(digitalRead(manual)==0)
  {                              
   digitalWrite(led,LOW);
   exact_cm_value1=0;
   exact_cm_value2=0;
   sensorRead();
                               
   if(MINIMA_DISTANCIAcm<exact_cm_value && MAXIMA_DISTANCIAcm>exact_cm_value)  //mientras el sensor esté dentro de la distancia
    {                                                                  
     for(int a=0;a<2;a++)  //sirve para guardar 2 mediciones, una actual y la anterior a esta
      {
       MEDIDAS[a]=exact_cm_value; 
       sensorRead();
       }
   
     Serial.print(MEDIDAS[1]); //"exact_cm_value" es la distancia en cm                                  
     Serial.print(" - ");
     Serial.println(MEDIDAS[2]); //"exact_cm_value" es la distancia en cm 
   
     if(abs(MEDIDAS[1]-MEDIDAS[2])>=DIF_MIN_MEDIDAS) //si la diferencia entre los ultimas 2 lecturas es mayor a DIF_MIN_MEDIDAS mostrarra cambio en motor y luz
        {                                    
          
          PASOS=map(exact_cm_value,MINIMA_DISTANCIAcm,MAXIMA_DISTANCIAcm,MAX_PASOS_SEGUR,MIN_PASOS_SEGUR);  //extrapola distancia con pasos
          stepper.runToNewPosition(PASOS);  //ejecuta la cantidad de pasos
                                          
        }
     if((MAXIMA_DISTANCIAcm+10 >= MEDIDAS[1] && MEDIDAS[1] >= MAXIMA_DISTANCIAcm-10) || (MAXIMA_DISTANCIAcm+10 >= MEDIDAS[2] && MEDIDAS[2] >= MAXIMA_DISTANCIAcm-10))
        {                               // si se define un maximo x y la lectura es x+5 o x-5 vuelve a la posicion inicial
         stepper.runToNewPosition(0);                                            
         }
                                
      }
    }
  if(digitalRead(manual)==1)
   {
     interrupts();  //activa la interrupcion attach
     digitalWrite(led,HIGH); //enciende el led para indicar modo manual
     delay(50);
     R=digitalRead(reloj); //lectura boton reloj
     AR=digitalRead(antireloj);  //lectura boton antireloj                   
                             
     //----------------ajuste manual del motor-----------------          
     if(R==1 && AR==0)  
      {
        //  Serial.println("clockwise");  // step one revolution  in one direction:
        myStepper.step(50); //control por pasos
        //delay(400);
       }
     R=digitalRead(reloj); //lectura boton reloj
     AR=digitalRead(antireloj);  //lectura boton antireloj  
     
      if(AR==1 && R==0)
      {      
       Serial.println("counterclockwise");  // step one revolution in the other direction:
       myStepper.step(-50);  //control por pasos
       delay(400); 
      }
  
   }
                          
                       
}

