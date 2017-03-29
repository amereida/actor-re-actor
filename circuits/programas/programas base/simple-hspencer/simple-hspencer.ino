#include <Stepper.h>

float Inch = 0.00;
float cm = 0.00;
int SonarPin = A0;
int sensorValue;
float val = 0.0;

// change this to the number of steps on your motor
#define STEPS 800

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
// Stepper(steps, pin1, pin2, pin3, pin4) or
// Stepper(steps, pin1, pin2)
Stepper stepper(STEPS, 8, 9, 10, 11); ////////////// check!
// Stepper stepper(STEPS, 5, 8, 9, 10); ////////////// check!

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
  pinMode(SonarPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // get the sensor value
  sensorValue = analogRead(SonarPin);

  Inch = (sensorValue * 0.497);
  cm = Inch * 2.54;
  Serial.print(cm);
  Serial.println("cm");

  //   map sensor  min, max to motor min, max
  val = map(cm, 10, 400, 0, 2000);
  // val = (sin(millis() / 9999) * 2000) + 1000;

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  delay(20);
  
  // remember the previous value of the sensor
  previous = val;
}


