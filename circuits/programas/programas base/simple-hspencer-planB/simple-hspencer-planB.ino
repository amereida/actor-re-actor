/*
    Plan B
    Move stepper motor according to distance read
    from ultrasound
*/

#include <AccelStepper.h>

float Inch = 0.00;
float cm = 0.00;
int SonarPin = A0;
int sensorValue;
float val = 0.0;

////////////////////////// VARIABLES DEL MOTOR ////////////////////////////////

const int stepsPerRevolution = 200;  // pasos por rev
AccelStepper stepper(2, 9, 8);   // LIB ACCEL


//////////////////////////////////////////////////////////////////
/////////////// el número que hay que modificar //////////////////
//////////////////////////////////////////////////////////////////

int maxSteps = 1850;

//////////////////////////////////////////////////////////////////
///////////// rango máximo de pasos para el motor ////////////////
//////////////////////////////////////////////////////////////////

boolean test = true;

/* Variables de suavizado */

long soft;
int b = 200;   // estos 2 numeros deben ser iguales
int buf[200];  // buffer de suavizado
int count;

void setup() {
  
  // Stepper
  stepper.setSpeed(30);
  stepper.setMaxSpeed(300);
  stepper.setAcceleration(2000);
  
/*
  // UltraSound
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode
  digitalWrite(7, LOW);  // GND mode
*/

pinMode(SonarPin, INPUT);
  // if test init serial
  if (test) Serial.begin(9600);

  count = 0;
}

void loop() {
  // get the sensor value
  sensorValue = analogRead(SonarPin);
  Inch = (sensorValue * 0.497);
  cm = Inch * 2.54;
  
  buf[count] = cm;
  count ++;
  count %= b;
  long val = 0;

  for (int i = 0; i < b; i++) {
    val += buf[i];
  }

  soft = val / b;

  // int steps = round(map(distance, 0, 172, maxSteps, 0));

  int steps = round(map(soft, 10, 150, maxSteps, 0));
  steps = constrain(steps, 0, maxSteps);

  // Set stepper to mapped steps
  stepper.moveTo(steps);
  stepper.runSpeedToPosition();

  // if test then print values to serial
  if (test) {
    Serial.print(soft);
    Serial.print("cm   ");
    Serial.println(steps);
  }
}
