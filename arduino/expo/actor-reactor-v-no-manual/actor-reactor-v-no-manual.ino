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

int minDist = 0;    // (cm) minimum sensitivity
int maxDist = 600;   // (cm) max sensitivity - sensor max is 640
int minSteps = 20;
int maxSteps = 2300; // **ADJUST** stepper maximum range (1mt = 5092)
int variation = 40;  // minimal distance variation for activating the motor


// inverted = more distance, less pull
boolean inverted = true;

////////////////////////// CALCULATIONS /////////////////////////////////

int securitySteps = 100;  // minimum security steps
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int target  = 0;
int ptarget = 0;
boolean flag; // manual flag
int count;    // counter
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

  stepper.setMaxSpeed(200.0);
  stepper.setSpeed(10.0);
  stepper.setAcceleration(5600.0);

  ///////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////

  readSonar();
  flag = false; // for returning to automatic mode and equilizing values
  moving = false; // not moving yet
  count = 0;
}


void loop() {

  // check mode, read switch
  mode = digitalRead(manual);

  // automatic mode: moving from sonar input


  digitalWrite(led, LOW); // turn off led light

  if (flag) {
    // when returning to auto mode recalibrate distances
    Serial.println("Recalibrating limits ................");
    float adjusted;
    if (inverted) {
      adjusted = map(stepper.currentPosition(), 0, maxSteps, maxDist, minDist);
    } else {
      adjusted = map(stepper.currentPosition(), 0, maxSteps, minDist, maxDist);
    }

    flag = false; // remove this flag so only do it once

    // recalibrate program
    minSteps = stepper.currentPosition();
    maxSteps += minSteps;

    maxDist = cm;

    // define targets
    ptarget = target;
    target = stepper.currentPosition();

    Serial.print(minSteps);
    Serial.print("\t");
    Serial.println(minSteps);

    Serial.print(minDist);
    Serial.print("\t");
    Serial.println(maxDist);

  }

  readSonar();

  if (!moving) {
    count++;
    if (count > 1000) {
      count = 0;
      Serial.println("returning to zero");
      stepper.runToNewPosition(0);
    }
    calcTargetStep();
    if (abs(target - ptarget) > variation) {
      moving = true;
      Serial.print("going to ");
      Serial.println(target);
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
