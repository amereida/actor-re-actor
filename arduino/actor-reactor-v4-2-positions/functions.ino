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

boolean delta(int val) {
  if (abs(stepper.currentPosition() - target) > val) {
    return true;
  } else {
    return false;
  }
}

void calcTargetStep() {
  if (cm > minDist && cm < maxDist) {
    if (inverted) {
      target = map(cm, minDist, maxDist, maxSteps, minSteps);
    } else {
      target = map(cm, minDist, maxDist, minSteps, maxSteps);
    }
  }
}

void roll(int newPosition) {
  stepper.runToNewPosition(newPosition);
}

void roll() {
  if (int(stepper.targetPosition()) == maxSteps) {
    stepper.runToNewPosition(minSteps);
  } else {
    stepper.runToNewPosition(maxSteps);
  }
}

void buttons() {
  moving = false;
  delayMicroseconds(10);

  flag = true; // entering manual mode

  digitalWrite(led, HIGH); // led on

  R = digitalRead(cw);
  AR = digitalRead(ccw);

  if (AR == 0 && R == 0) {
    readSonar();
  } else if (AR == 0 && R == 1) {
    target += securitySteps; // * 800 is a whole turn
  } else if (AR == 1 && R == 0) {
    target -= securitySteps;
  }
  if (AR != R) { /* if buttons are differently pressed */
    // target = constrain(target, 0, maxSteps);
    roll(target);
  }
  R = digitalRead(cw); // button reading for cw (clockwise)
  AR = digitalRead(ccw);  // button reading for ccw (counter clockwise)
  mode = digitalRead(manual);
}

void printAuto() {
  Serial.print("cm = ");
  Serial.print(getSoft(true));
  Serial.print("\t\t");
  Serial.print(ptarget);
  Serial.print(" - ");
  Serial.print(target);
  Serial.print("\t");
  Serial.print("? = ");
  Serial.println(moving);
}

void printManual() {
  Serial.print("cm = ");
  Serial.print(getSoft(true));
  Serial.print("\t\t");
  Serial.print("current step ");
  Serial.println(stepper.currentPosition());
}
