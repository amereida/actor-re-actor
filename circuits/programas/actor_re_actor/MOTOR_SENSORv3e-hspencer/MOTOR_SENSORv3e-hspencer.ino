/*
 *  Actor - Reactor
 *  
 *  amereida
 *  phalène
 *  latin
 *  america
 *  
 *  documenta14 ~ 2017
 *  no dimmer
 */


#include <AccelStepper.h>

/////////////////////// VARIBLES DE AJUSTE DE MEDIDAS (AJUSTAR) ////////////////////

int minDist = 100;   // minima distancia para medir en centímetros
int maxDist = 500;  // máxima distancia para medir en centímetros
int maxSteps = 2500; // <---- DEFINIR AL COMIENZO DEL MONTAJE, es el número máximo de pasos entre una posicion inicial y una final
// int x = 0; // manual target

////////////////////// VARIABLES FIJAS DE CALCULO /////////////////////////////
int securitySteps = 20;  // holgura de pasos para la cantidad minima de pasos y la maxima
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int currentStep = 0;  //variable calculada mapeando la distancia con el rango de pasos permitidos
int sonarMinDifference = 30; // variacion minima que debe existir entre dos medidas consecutivas para que actue el motor

////////////////////////// VARIABLES DEL MOTOR ////////////////////////////////

AccelStepper stepper(2, 9, 8);   // LIB ACCEL

/////////////////// VARIABLES SENSOR DE DISTANCIA ////////////////////////////////////

float Inch        = 0.00;
int   cm          = 0;
int   cmPrev      = 0;
int   sonarPin    = A0;
int   sensorValue;

////////////////// BOTONES MANUALES ////////////////////

int cw          = 11;   // pin boton para accionar en sentido cw
int ccw         = 12;   // pin boton para accionar en sentido ccw
int manual      = 3;    // pin boton manual
int led         = 13;   // led de modo manual o automatico
int R;                  // variable de almacenamiento del boton cw
int AR;                 // variable de almacenamiento del boton ccw
boolean modo;

////////////////// VARIABLES DIMMER //////////////////
/*
int AC_LOAD     = 5;    // Output to Opto Triac pin
int full_dim    = 35;   // 5   maxima intensidad de luz
int empty_dim   = 95;   // 128  miniam intensidad de luz
int dimming     = 128;  // Dimming level (0-128)  0 = ON, 128 = OFF
int A           = full_dim;   //todo
int B           = empty_dim;  //nada
int C           = 5;
int DIMMER      = 0;
int dimtime;
*/
///////////////////////////////////////////////////////////

/* Variables de suavizado */

long soft;     // valor suavizado del sensor
int b = 100;   // estos 2 numeros deben ser iguales
int buf[100];  // buffer de suavizado (100)
int count;     // contador auxiliar

///////////////////////////////////////////////////////////

void readSonar(){
  sensorValue = analogRead(sonarPin);
  Inch = (sensorValue * 0.497);
  cm = Inch * 2.54;

  // soften value
  buf[count] = cm;
  count ++;
  count %= b;
  long val = 0;
  
  for (int i = 0; i < b; i++) {
    val += buf[i];
  }
  
  soft = val / b;
}

///////////////////////// DIMMER ////////////////////////////////////////
// function to be fired at the zero crossing to dim the light
/*
void zero_crosss_int(){ 
  delayMicroseconds(dimtime);    // Wait till firing the TRIAC    
  digitalWrite(AC_LOAD, HIGH);   // Fire the TRIAC
  delayMicroseconds(10);         // triac On propogation delay 
  digitalWrite(AC_LOAD, LOW);    // No longer trigger the TRIAC (the next zero crossing will swith it off) TRIAC
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// interrupción externa para el boton manual

void BOTON_MANUAL(){  
  // detachInterrupt(0);     // desactiva la interrupcion attach
  digitalWrite(led,HIGH); // enciende el led para indicar modo manual
  delayMicroseconds(50);
  R = digitalRead(cw);    // lectura boton cw
  AR = digitalRead(ccw);  // lectura boton ccw   

  if (AR == 0 && R == 0){
    detachInterrupt(0);
    delayMicroseconds(50);
    readSonar();
    Serial.print(cm);
    Serial.println(" cm ");
  } else if (AR == 0 && R == 1){
    currentStep += securitySteps; // * 40 es una vuelta entera
  }
  else if (AR == 1 && R == 0){
    currentStep -= securitySteps;
  }

  delayMicroseconds(10);

  if (AR != R){
    stepper.runToNewPosition(currentStep);
    soft = currentStep; // para que no salte al volver a modo automático
  }
  
  R = digitalRead(cw); // button reading for cw (clockwise)
  AR = digitalRead(ccw);  // button reading for ccw (counter clockwise)
  modo = digitalRead(manual);
}

///////////////////////////////////////////////////////////////////////////////////
// A = full_dim    B = empty_dim     C = 5
/*
void RANGO_DIM(){
  unsigned long CERO = 0;
  /*
  if     (35<=DIMMER && DIMMER<45){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=2625;}} 
  else if(45<=DIMMER && DIMMER<55){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=3375;}}
  else if(55<=DIMMER && DIMMER<65){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=4150;}}
  else if(65<=DIMMER && DIMMER<75){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=4875;}}
  else if(75<=DIMMER && DIMMER<85){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=5625;}}
  else if(85<=DIMMER && DIMMER<95){unsigned long tiempo=millis();if((unsigned long)(tiempo-CERO)>=10){dimtime=6375;}}
  
  dimtime = round(map(DIMMER, 35, 95, 2625, 6375));
}
*/
///////////////////////////////////////////////////////////////////////////////////

void setup(){  
  pinMode(sonarPin,INPUT);
  Serial.begin(9600);  
  pinMode(cw,INPUT);
  pinMode(ccw,INPUT);
  pinMode(manual,INPUT);
  pinMode(led,OUTPUT);
  // pinMode(AC_LOAD, OUTPUT); // Set AC Load pin as output

  stepper.setMaxSpeed(6000.0);
  stepper.setSpeed(5000.0);
  stepper.setAcceleration(5000.0);

  // counter used for soft value
  count = 0;

  // softened value is the sonar's first reading
  readSonar();
  soft = cm;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void loop(){                                   
  modo = digitalRead(manual);

  // MODO AUTOMATICO
  if (modo == 0){                    
   digitalWrite(led,LOW);
   readSonar();                  
   
   // mientras el sensor esté dentro de la distancia
   if(cm >= minDist && cm <= maxDist){   
     
     //si la diferencia entre los ultimas 2 lecturas es mayor a sonarMinDifference mostrarra cambio en motor y luz
     if(abs(cmPrev - soft) >= sonarMinDifference){
          unsigned long CERO = 0; 
          
          // dimmer
          // DIMMER = map(cm,minDist,maxDist,full_dim,empty_dim); 
          // RANGO_DIM(); 

          // extrapola distancia con pasos
          currentStep = map(soft, minDist, maxDist, maxSecuritySteps, minSecuritySteps); 
          unsigned long tiempo = millis();
          
          stepper.runToNewPosition(currentStep);    
       }
    }
    cmPrev = cm;     
    Serial.print(cm);
    Serial.print("\t");
    Serial.println(soft);
       
  } else if(modo == 1) {
     BOTON_MANUAL(); 
    }                
}


