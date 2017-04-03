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

int minDist = 50;   // (cm) minimum sensitivity
int maxDist = 600;   // (cm) max sensitivity - sensor max is 640
int maxSteps = 2500; // **ADJUST** stepper maximum range


////////////////////// CALCULATIONS /////////////////////////////

int securitySteps = 20;  // minimum security steps
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int currentStep = 0;
int targetStep = 0;
int sonarMinDifference = 30; // minimal sensing variation to act.
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

  stepper.setMaxSpeed(6000.0);
  stepper.setSpeed(3000.0);
  stepper.setAcceleration(5000.0);

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
    
    if (flag) {
      
      // we need to make the soft value equal to what we manually define, so it doesn't jump
      Serial.println("equilizing values...........");
      long val = 0;
      float adjustedReading = map(stepper.currentPosition(), minSecuritySteps, maxSecuritySteps, minDist, maxDist);
      for (int i = 0; i < b; i++) {
        buf[i] = adjustedReading;
      }
      flag = false;
      soft = adjustedReading;
      delayMicroseconds(10);

      // also we need to reset the motor position
      stepper.setCurrentPosition(0);
    }
    digitalWrite(led, LOW);

    getSoft(true);
    
    calcTargetStep();
    if (abs(stepper.currentPosition() - soft) > sonarMinDifference) {
      roll(targetStep);
    }else{
      Serial.println("---------------------------");
    }
    
    printValues();
  } else if (mode == 1) {
    // manual mode, setting up mottor with buttons
    buttons();
  }
}


