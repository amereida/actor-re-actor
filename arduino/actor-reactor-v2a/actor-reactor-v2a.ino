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

int minDist = 10;    // (cm) minimum sensitivity
int maxDist = 300;   // (cm) max sensitivity - sensor max is 640
int minSteps = 20;
int maxSteps = 3200; // **ADJUST** stepper maximum range
int variation = 40;  // minimal distance variation for activating the motor
boolean inverted = false;

////////////////////// CALCULATIONS /////////////////////////////

int securitySteps = 800;  // minimum security steps
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int target  = 0;
int ptarget = 0;
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
boolean moving;

////////////////// SOFTENED VALUES ////////////////////////////
/*
  long soft;     // valor suavizado del sensor
  int b = 100;   // estos 2 numeros deben ser iguales
  int buf[100];  // buffer de suavizado (100)
  int count;     // contador auxiliar
*/

void setup() {
  pinMode(sonarPin, INPUT);
  Serial.begin(9600);
  pinMode(cw, INPUT);
  pinMode(ccw, INPUT);
  pinMode(manual, INPUT);
  pinMode(led, OUTPUT);

///////////////////////////////////////////////////////////////////
///////////////////////  MOTOR SETUP  /////////////////////////////
///////////////////////////////////////////////////////////////////

  stepper.setMaxSpeed(5000.0);
  stepper.setSpeed(400.0);
  stepper.setAcceleration(3000.0);

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

  readSonar();
  flag = false; // for returning to automatic mode and equilizing values
  moving = false; // not moving yet
}


void loop() {

  // check mode, read switch
  mode = digitalRead(manual);

  // automatic mode: moving from sonar input
  if (mode == 0) {

    digitalWrite(led, LOW); // turn off led light

    /*
        if its returning from manual we need to
        make the target step value equal to current step
        so it doesn't jump
    */

    if (flag) {

      ptarget = target;

      Serial.println("equalizing values................");
      float adjusted;
      if (inverted) {
        adjusted = map(stepper.currentPosition(), 0, maxSteps, maxDist, minDist);
        } else {
        adjusted = map(stepper.currentPosition(), 0, maxSteps, minDist, maxDist);
      }
      flag = false; // remove this flag so only do it once
      delayMicroseconds(10);
      target = stepper.currentPosition();

      // also we need to reset the motor position
      stepper.setCurrentPosition(0); // ???? do this?
    }

    readSonar();

    if (!moving) {

      calcTargetStep();
      if (abs(target - ptarget) > variation) {
        moving = true;
        stepper.runToNewPosition(target);
        ptarget = target;
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
  
}


