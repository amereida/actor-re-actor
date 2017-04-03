/*
    Actor - Reactor

    amereida
    phalène
    latin
    america

    documenta14 ~ 2017

*/


#include <AccelStepper.h>

/////////////////////// MEASUREMENTS ////////////////////

int minDist = 000;   // (cm) minimum sensitivity
int maxDist = 400;   // (cm) max sensitivity - sensor max is 640
int maxSteps = 3200; // **ADJUST** stepper maximum range


////////////////////// CALCULATIONS /////////////////////////////

int securitySteps = 800;  // minimum security steps
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int targetStep = 0;
boolean flag; // manual flag


////////////////////////// STEPPER MOTOR ////////////////////////////////

AccelStepper stepper(2, 9, 8);   // LIB ACCEL

/////////////////// DINSTANCE ////////////////////////////////////

float Inch        = 0.00;
int   cm          = 0;
int   cmPrev      = 0;
int   sonarPin    = A0;
int   sensorValue;

////////////////// BUTTONS ////////////////////

int cw          = 11;   // pin boton para accionar en sentido cw
int ccw         = 12;   // pin boton para accionar en sentido ccw
int manual      = 3;    // pin boton manual
int led         = 13;   // led de modo manual o automatico
int R;                  // variable de almacenamiento del boton cw
int AR;                 // variable de almacenamiento del boton ccw
boolean mode;

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
  // pinMode(AC_LOAD, OUTPUT); // Set AC Load pin as output

  stepper.setMaxSpeed(2000.0);
  stepper.setSpeed(200.0);
  stepper.setAcceleration(1000.0);

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

  soft = val / b;
  flag = false; // not moving yet
}


void loop() {

  // check mode, read switch
  mode = digitalRead(manual);

  // automatic mode: moving from sonar input
  if (mode == 0) {

    /* 
     *  if its returning from manual we need to
     *  make the target step value equal to current step
     *  so it doesn't jump
    */
    if (flag) {
      
      Serial.println("equalizing values................");
      
      float adjusted = map(stepper.currentPosition(), 0, maxSteps, minDist, maxDist);
      for (int i = 0; i < b; i++) {
        buf[i] = adjusted;
      }
      
      flag = false; // remove this flag so only do it once
      soft = adjusted;
      delayMicroseconds(10);

      targetStep = stepper.currentPosition();
      
      // also we need to reset the motor position
      stepper.setCurrentPosition(0); // ???? do this?
    }
    digitalWrite(led, LOW);

    getSoft(true);
    calcTargetStep();
    
    if (delta()) {
      roll(targetStep);
      printValues();
    }else{
      Serial.println("-------------------------------------------");
    }
  } else if (mode == 1) {
    // manual mode, setting up mottor with buttons
    buttons();
  }
}


