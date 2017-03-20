#include <AccelStepper.h>


AccelStepper stepper(2, 9, 8); // 2 = Driver Mode, Step = pin 9, Direction = pin 8
int i;
int pasos= 3000;

void setup()
{
stepper.setMaxSpeed(3000.0); //pasos por segundo
stepper.setSpeed(3000.0); //pasos por segundo
}

void loop()
{
stepper.setAcceleration(300.0); //step por segundo

stepper.runToNewPosition(pasos);
delay(1000);
stepper.runToNewPosition(-pasos);


}


