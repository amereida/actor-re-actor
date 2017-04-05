/*
    Actor - Reactor

    amereida
    phalène
    latin
    america

    documenta14 ~ 2017

    this version uses the variables: 
    'minSteps' and 'maxSteps' 
    as 2 positions to alternate if disturbed

*/


#include <AccelStepper.h>

/////////////////////// MEASUREMENTS ////////////////////

int minDist = 200;   // (cm) minimum sensitivity
int maxDist = 640;   // (cm) max sensitivity - sensor max is 640
int minSteps = 0;
int maxSteps = 3000; // **ADJUST** stepper maximum range (1mt = 5092)
int variation = 50;  // minimal distance variation for activating the motor

int prev;            // previous distance measurement

// inverted = more distance, less pull
boolean inverted = true;

////////////////////////// CALCULATIONS /////////////////////////////////

int securitySteps = 800;  // minimum security steps
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int target  = 0;
int ptarget = 0;
boolean flag; // manual flag

////////////////////////// STEPPER MOTOR ////////////////////////////////

AccelStepper stepper(2, 9, 8);   // LIB ACCEL

/////////////////// DINSTANCE ///////////////////////////////////////////

float Inch        = 0.00;
int   cm          = 0;
int   cmPrev      = 0;
int   sonarPin    = A0;
int   sensorValue;

////////////////// BUTTONS //////////////////////////////////////////////

int cw          = 11;   // pin boton para accionar en sentido cw
int ccw         = 12;   // pin boton para accionar en sentido ccw
int manual      = 3;    // pin boton manual
int led         = 13;   // led de modo manual o automatico
int R;                  // variable de almacenamiento del boton cw
int AR;                 // variable de almacenamiento del boton ccw
boolean mode;
boolean moving;

////////////////// SOFTENED VALUES ////////////////////////////

long soft;     // valor suavizado del sensor
int b = 100;   // estos 2 numeros deben ser iguales
int buf[100];  // buffer de suavizado (100)
int count;     // contador auxiliar


void setup() {
  pinMode(sonarPin, INPUT);
  Serial.begin(9600);
  pinMode(cw, INPUT);
  pinMode(ccw, INPUT);
  pinMode(manual, INPUT);
  pinMode(led, OUTPUT);

////////////////////////////////////////////////////////////////////////
//////////////////////////  MOTOR SETUP  ///////////////////////////////
////////////////////////////////////////////////////////////////////////

  stepper.setMaxSpeed(2000.0);
  stepper.setSpeed(1000.0);
  stepper.setAcceleration(5600.0);

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
  
  // counter used for soft value
  count = 0;

  // softened value is the sonar's first reading
  readSonar();

  // soften value
  buf[count] = cm;
  count ++;
  count %= b;
  long val = 0;

  for (int i = 0; i < b; i++) {
    buf[i] = cm;
  }

  prev = soft;

  flag = false; // for returning to automatic mode and equilizing values
  
  moving = false; // not moving yet
}


void loop() {

  // check mode, read switch
  mode = digitalRead(manual);

  readSonar();
  
  // automatic mode: moving from sonar input
  if (mode == 0) {

    if(flag){
      maxSteps = stepper.currentPosition();
      Serial.println("Values have been modified");
      flag = false;
    }

    digitalWrite(led, LOW); // turn off led light

    if (!moving) {

      if (abs(soft - prev) > variation) {
        moving = true;
        roll();
        
      } else {
        moving = false;
      }
    } else {
      if (!stepper.run()) {
        moving = false;
      }
    }
    printAuto();
  }
  else if (mode == 1) {
    // manual mode, setting up mottor with buttons
    buttons();
    printManual();
  }
  prev = soft;
}
