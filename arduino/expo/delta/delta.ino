///////////////////////////////////////////////////////////
//                                                       //
//  WARNING: this machine has the manual switch broken   //
//                                                       //
///////////////////////////////////////////////////////////

/*
    Actor - Reactor

    amereida
    phalène
    latin
    america

    documenta14 ~ 2017

*/


#include <AccelStepper.h>

/////////////////////// MEASUREMENTS TO ADJUST ////////////////////

int minDist = 100;      // (cm) minimum sensitivity
int maxDist = 420;      // (cm) max sensitivity - sensor max is 640
int minSteps = 0;       // minimal run
int maxSteps = 1900;    // **ADJUST** stepper maximum range (1mt = 5092)
int variation = 50;     // minimal distance variation for activating the motor
int waitingTime = 1500; // loop count for returning to zero

// inverted = less distance to sensor, more pull of the cable
boolean inverted = true;

////////////////////////// CALCULATIONS /////////////////////////////////

int securitySteps = 100;                  // minimum security steps
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int target  = 0;                          // current target
int ptarget = 0;                          // previous target
boolean flag;                             // manual flag
int count;                                // counter

////////////////////////// STEPPER MOTOR ////////////////////////////////

AccelStepper stepper(2, 9, 8);   // LIB ACCEL

/////////////////// DINSTANCE ///////////////////////////////////////////

float Inch        = 0.00;
int   cm          = 0;
int   pcm         = cm; // previous reading in centimetres
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
  stepper.setSpeed(100.0);
  stepper.setAcceleration(3000.0);

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

  // if (mode == 0) {
  modeAutomatic();
  // }

  //else if (mode == 1) {
  // manual mode, setting up mottor with buttons
  // modeManual();
  //}
}

