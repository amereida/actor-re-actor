// #include <Stepper.h>
#include <AccelStepper.h>

/////////////////////// VARIBLES DE AJUSTE DE MEDIDAS (AJUSTAR) ////////////////////

int MINIMA_DISTANCIAcm = 10;   //100minima distancia para medir
int MAXIMA_DISTANCIAcm = 420;  //700maxima distancia para medir
int NUM_MAX_PASOS = 5000; //23000 <-------------------DEFINIR AL COMIENZO DEL MONTAJE, es el número máximo de pasos entre una posicion inicial y una final
int x = 0; // ¿para qué es?

////////////////////// VARIABLES FIJAS DE CALCULO /////////////////////////////
int PPR = 400; // ¿para qué es?
int PASOS_DE_SEGURIDAD = 20;  // holgura de pasos para la cantidad minima de pasos y la maxima
int MIN_PASOS_SEGUR = PASOS_DE_SEGURIDAD;
int MAX_PASOS_SEGUR = NUM_MAX_PASOS - PASOS_DE_SEGURIDAD;
int PASS = 0; // ¿para qué es?
int PASOS = 0;  //variable calculada mapeando la distancia con el rango de pasos permitidos
int DIF_MIN_MEDIDAS = 50; // variacion minima que debe existir entre dos medidas consecutivas para que actue el motor


////////////////////////// VARIABLES DEL MOTOR ////////////////////////////////

AccelStepper stepper(2, 9, 8);   // LIB ACCEL

///////////////////VARIABLES SENSOR DE DISTANCIA////////////////////////////////////

float Inch      = 0.00;
int cm          = 0;
int cm_anterior = 0;
int SonarPin    = A0;
int sensorValue;

//////////////////BOTONES MANUALES////////////////////

int reloj       = 11;   //pin boton para accionar en sentido reloj
int antireloj   = 12;   //pin boton para accionar en sentido antireloj
int manual      = 3;    // pin boton manual
int led         = 13;   //led de modo manual o automatico
int R;                  //variable de almacenamiento del boton RELOJ
int AR;                 //variable de almacenamiento del boton ANTIRELOJ
boolean modo;

///////////////////VARIABLES DIMMER////////////////////

int AC_LOAD     = 5;    // Output to Opto Triac pin
int full_dim    = 35;   // 5   maxima intensidad de luz
int empty_dim   = 95;   //128  miniam intensidad de luz
int dimming     = 128;  // Dimming level (0-128)  0 = ON, 128 = OFF
int A           = full_dim;   //todo
int B           = empty_dim;  //nada
int C           = 5;
int DIMMER      = 0;
int dimtime;

///////////////////////////////////////////////////////////

int VAR=0,DISTANCIA_CUERDA=0;
int RESULTADO=0;

///////////////////////////////////////////////////////////

void medicion(){
   sensorValue = analogRead(SonarPin);
   Inch = (sensorValue*0.497);
   cm = Inch*2.54;
}

///////////////////////// DIMMER ////////////////////////////////////////
//function to be fired at the zero crossing to dim the light
void zero_crosss_int(){ 
  delayMicroseconds(dimtime);    // Wait till firing the TRIAC    
  digitalWrite(AC_LOAD, HIGH);   // Fire the TRIAC
  delayMicroseconds(10);         // triac On propogation delay 
  // (for 60Hz use 8.33) Some Triacs need a longer period
  digitalWrite(AC_LOAD, LOW);    // No longer trigger the TRIAC (the next zero crossing will swith it off) TRIAC
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//interrupcion externa para el boton manual

void BOTON_MANUAL(){  
  detachInterrupt(0);  //desactiva la interrupcion attach
  digitalWrite(led,HIGH); //enciende el led para indicar modo manual
  delayMicroseconds(50);
  R = digitalRead(reloj); //lectura boton reloj
  AR = digitalRead(antireloj);  //lectura boton antireloj   

 
  if (AR == 0 && R == 0){
    detachInterrupt(0);
    delay(100);
    medicion();
    Serial.print(cm);
    Serial.println(" cm ");
  } else if (AR == 0 && R == 1){
    x += PASOS_DE_SEGURIDAD * 10;
  }
  else if (AR == 1 && R == 0){
    x -= PASOS_DE_SEGURIDAD * 10;
  }

  stepper.setMaxSpeed(1000.0); // pasos por segundo
  stepper.setSpeed(500.0);     // pasos por segundo
  delayMicroseconds(500);

  if ( AR != R){
    stepper.runToNewPosition(x);
  }
  
  R = digitalRead(reloj); //lectura boton reloj
  AR = digitalRead(antireloj);  //lectura boton antireloj
  modo = digitalRead(manual);
}

///////////////////////////////////////////////////////////////////////////////////
// A = full_dim    B = empty_dim     C = 5
void RANGO_DIM(){
  unsigned long CERO = 0;
  if     (35<=DIMMER && DIMMER<45){unsigned long tiempo=millis();if((unsigned long)(tiempo-0)>=10){dimtime=2625;}} 
 // else if(40<=DIMMER && DIMMER<45){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=3000;}}
  else if(45<=DIMMER && DIMMER<55){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=3375;}}
 // else if(50<=DIMMER && DIMMER<55){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=3750;}}
  else if(55<=DIMMER && DIMMER<65){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=4150;}}
 // else if(60<=DIMMER && DIMMER<65){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=4500;}}
  else if(65<=DIMMER && DIMMER<75){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=4875;}}
 // else if(70<=DIMMER && DIMMER<75){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=5250;}}
  else if(75<=DIMMER && DIMMER<85){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=5625;}}
 // else if(80<=DIMMER && DIMMER<85){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=6000;}}
  else if(85<=DIMMER && DIMMER<95){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=6375;}}
 // else if(90<=DIMMER && DIMMER<95){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=6750;}}
  
}
///////////////////////////////////////////////////////////////////////////////////
void setup(){  
  pinMode(SonarPin,INPUT);
  Serial.begin(9600);
  stepper.setMaxSpeed(2000.0);  //LIB ACCEL
  stepper.setAcceleration(300.0);  //LIB ACCEL    
  pinMode(reloj,INPUT);
  pinMode(antireloj,INPUT);
  pinMode(manual,INPUT);
  pinMode(led,OUTPUT);
  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void loop(){ 
                                     
  modo = digitalRead(manual);

  // MODO AUTOMATICO
  if (modo == 0){ 
   attachInterrupt(0, zero_crosss_int, RISING);                           
   digitalWrite(led,LOW);
   medicion();                  
   if(MINIMA_DISTANCIAcm<=cm && MAXIMA_DISTANCIAcm>=cm)  //mientras el sensor esté dentro de la distancia
    {     
     if(abs(cm_anterior-cm)>=DIF_MIN_MEDIDAS) //si la diferencia entre los ultimas 2 lecturas es mayor a DIF_MIN_MEDIDAS mostrarra cambio en motor y luz
        { 
          unsigned long CERO=0; 
          DIMMER=map(cm,MINIMA_DISTANCIAcm,MAXIMA_DISTANCIAcm,full_dim,empty_dim); 
          RANGO_DIM(); 
          PASOS=map(cm,MINIMA_DISTANCIAcm,MAXIMA_DISTANCIAcm,MAX_PASOS_SEGUR,MIN_PASOS_SEGUR);  //extrapola distancia con pasos
          unsigned long tiempo=millis();
          if((unsigned long)(tiempo-CERO)>=10)
           { 
           // myStepper.setSpeed(5000);
           stepper.setAcceleration(5000.0);        
           stepper.runToNewPosition(PASOS);  //ejecuta la cantidad de pasos
           }   
                        
        }
    
     else if(MAXIMA_DISTANCIAcm+20 >= cm && cm >= MAXIMA_DISTANCIAcm-20 || MAXIMA_DISTANCIAcm+20 >= cm && cm >= MAXIMA_DISTANCIAcm-20)
            {
              unsigned long CERO=0; 
              dimtime=6750;
              unsigned long tiempo=millis();
              if((unsigned long)(tiempo-CERO)>=10)
                 {
                 attachInterrupt(0, zero_crosss_int, RISING); 
                 // myStepper.setSpeed(5000);
                 stepper.setAcceleration(5000.0);        
                 stepper.runToNewPosition(0);  //ejecuta la cantidad de pasos
                 }                    
            }  
        }
       cm_anterior=cm;     
      // Serial.println(cm_anterior);
       
  } else if(modo==1) {
     BOTON_MANUAL(); 
     modo=digitalRead(manual); 
    }                
  modo=digitalRead(manual);
}


