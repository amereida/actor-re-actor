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
    no dimmer
*/

/* manual swith is wrong */
boolean manualMode = false;

#include <AccelStepper.h>

/////////////////////// VARIBLES DE AJUSTE DE MEDIDAS (AJUSTAR) ////////////////////

int minDist = 30;   // minima distancia para medir en centímetros
int maxDist = 220;  // máxima distancia para medir en centímetros
int maxSteps = -1000; // <---- DEFINIR AL COMIENZO DEL MONTAJE, es el número máximo de pasos entre una posicion inicial y una final
// int x = 0; // manual target

int counter = 0;
int waitTime = 1000;

////////////////////// VARIABLES FIJAS DE CALCULO /////////////////////////////
int securitySteps = 200;  // holgura de pasos para la cantidad minima de pasos y la maxima
int minSecuritySteps = securitySteps;
int maxSecuritySteps = maxSteps - securitySteps;
int currentStep = 0;  //variable calculada mapeando la distancia con el rango de pasos permitidos
int sonarMinDifference = 40; // variacion minima que debe existir entre dos medidas consecutivas para que actue el motor

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

/* Variables de suavizado */

long soft;     // valor suavizado del sensor
int b = 100;   // estos 2 numeros deben ser iguales
int buf[100];  // buffer de suavizado (100)
int count;     // contador auxiliar

///////////////////////////////////////////////////////////
void setup() {
  pinMode(sonarPin, INPUT);
  Serial.begin(9600);
  pinMode(cw, INPUT);
  pinMode(ccw, INPUT);
  pinMode(manual, INPUT);
  pinMode(led, OUTPUT);
  // pinMode(AC_LOAD, OUTPUT); // Set AC Load pin as output

  stepper.setMaxSpeed(1500.0);
  stepper.setSpeed(120.0);
  stepper.setAcceleration(2000.0);

  // counter used for soft value
  count = 0;

  // softened value is the sonar's first reading
  readSonar();
  soft = cm;

  // soften value
  buf[count] = cm;
  count ++;
  count %= b;
  long val = 0;

  for (int i = 0; i < b; i++) {
    buf[i] = cm;
  }

  soft = val / b;
}

void readSonar() {
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

void BOTON_MANUAL() {
  
  // detachInterrupt(0);     // desactiva la interrupcion attach
  digitalWrite(led, HIGH); // enciende el led para indicar modo manual
  delayMicroseconds(50);
  R = digitalRead(cw);    // lectura boton cw
  AR = digitalRead(ccw);  // lectura boton ccw

  if (AR == 0 && R == 0) {
    
    detachInterrupt(0);
    delayMicroseconds(50);
    readSonar();
    
    Serial.print(cm);
    Serial.println(" cm ");
    
  } else if (AR == 0 && R == 1) {
    currentStep += securitySteps; // * 40 es una vuelta entera
  }
  else if (AR == 1 && R == 0) {
    currentStep -= securitySteps;
  }

  delayMicroseconds(10);

  Serial.println("\t\t");
  Serial.println(stepper.currentPosition());
  
  if (AR != R) {
    stepper.runToNewPosition(currentStep);


    // soften value
    buf[count] = cm;
    count ++;
    count %= b;
    long val = 0;

    for (int i = 0; i < b; i++) {
      buf[i] = cm;
    }

    soft = val / b;
    soft = currentStep; // para que no salte al volver a modo automático
  }

  R = digitalRead(cw); // button reading for cw (clockwise)
  AR = digitalRead(ccw);  // button reading for ccw (counter clockwise)
  modo = digitalRead(manual);
}

void loop() {
  modo = digitalRead(manual);

  // MODO AUTOMATICO
  if (/*modo == 0*/ !manualMode) {
    digitalWrite(led, LOW);
    readSonar();

    // mientras el sensor esté dentro de la distancia
    if (cm >= minDist && cm <= maxDist) {

      //si la diferencia entre los ultimas 2 lecturas es mayor a sonarMinDifference mostrarra cambio en motor y luz
      if (abs(cmPrev - soft) >= sonarMinDifference) {
        unsigned long CERO = 0;

        // extrapola distancia con pasos
        currentStep = map(soft, minDist, maxDist, maxSecuritySteps, minSecuritySteps);
        unsigned long tiempo = millis();

        counter = 0;
        stepper.runToNewPosition(currentStep);
      }
    }

    counter++;

    if (counter > waitTime) {
      Serial.println("returning to origin...");
      stepper.runToNewPosition(0);
    }


    cmPrev = cm;

    Serial.print(cm);
    Serial.print("\t");
    Serial.println(soft);

  } else if (/* modo == 1*/ manualMode) {
    BOTON_MANUAL();
  }
}


