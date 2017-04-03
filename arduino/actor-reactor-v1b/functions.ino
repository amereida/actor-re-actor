void readSonar() {

  delayMicroseconds(10);

  sensorValue = analogRead(sonarPin);
  Inch = (sensorValue * 0.497);
  cm = Inch * 2.54;

  // add cm value to the buffer array
  buf[count] = cm;

  count ++;
  count %= b;
}

long getSoft(boolean realtime) {
  if (realtime) {
    readSonar();
  }
  long val = 0;
  for (int i = 0; i < b; i++) {
    val += buf[i];
  }
  soft = val / b;
  return soft;
}

boolean delta() {
  if (abs(stepper.currentPosition() - targetStep) > 1) {
    return true;
  } else {
    return false;
  }
}

void calcTargetStep() {
  if (cm > minDist && cm < maxDist) {
    targetStep = map(cm, minDist, maxDist, 0, maxSteps);
  }
}

void roll(int newPosition) {
  delayMicroseconds(10);
  stepper.runToNewPosition(newPosition);
}

void buttons() {
  delayMicroseconds(10);

  flag = true; // entering manual mode

  digitalWrite(led, HIGH); // led on

  R = digitalRead(cw);
  AR = digitalRead(ccw);

  if (AR == 0 && R == 0) {
    getSoft(true);
  } else if (AR == 0 && R == 1) {
    targetStep += securitySteps; // * 40 is a whole turn
  } else if (AR == 1 && R == 0) {
    targetStep -= securitySteps;
  }
  if (AR != R) { /* if buttons are differently pressed */
    targetStep = constrain(targetStep, 0, maxSteps);
    roll(targetStep);
    printValues();
  }
  R = digitalRead(cw); // button reading for cw (clockwise)
  AR = digitalRead(ccw);  // button reading for ccw (counter clockwise)
  mode = digitalRead(manual);
}

void printValues() {
  Serial.print("d = ");
  Serial.print(cm);
  Serial.print("\t");
  Serial.print("s = ");
  Serial.print(soft);
  Serial.print("\t");
  Serial.print("c = ");
  Serial.print(stepper.currentPosition());
  Serial.print("\t");
  Serial.print("t = ");
  Serial.print(targetStep);
  Serial.print("\t");
  Serial.print("d = ");
  Serial.println(delta());
}
