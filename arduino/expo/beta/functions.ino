void readSonar() {
  pcm = cm;
  sensorValue = analogRead(sonarPin);
  Inch = (sensorValue * 0.497);
  cm = Inch * 2.54;
}

boolean delta(int val) {
  if (abs(stepper.currentPosition() - target) > val) {
    return true;
  } else {
    return false;
  }
}

boolean disrrupted() {
  if (abs(cm - pcm) > variation) {
    return true;
  } else {
    return false;
  }
}

void calcTargetStep() {
  if (!inverted) {
    target = map(cm, minDist, maxDist, maxSteps, minSteps);
  } else {
    target = map(cm, minDist, maxDist, minSteps, maxSteps);
  }
  target = constrain(target, minSteps, maxSteps);
}

void roll(int newPosition) {
  stepper.runToNewPosition(newPosition);
}

void modeAutomatic() {

  digitalWrite(led, LOW); // turn off led light

  readSonar();

  if (flag) {
    // when returning to auto mode recalibrate distances
    Serial.println("Recalibrating limit and returning to zero................");

    flag = false; // remove this flag so only do it once

    // recalibrate program
    maxSteps = stepper.currentPosition();
    stepper.runToNewPosition(0);

    // define targets
    ptarget = target;
    target = stepper.currentPosition();
  }

  if (!moving) {

    count++;
    if (count > waitingTime) {
      count = 0;
      Serial.println("************ zzzzzz ************");
      Serial.println("returning to zero");
      stepper.runToNewPosition(0);
    }

    calcTargetStep();

    if (disrrupted()) {
      moving = true;
      Serial.println("************* tilt! ************");
      Serial.print("going to ");
      Serial.println(target);
      stepper.runToNewPosition(target);
    } else {
      moving = false;
    }
  } else {
    if (!stepper.run()) {
      moving = false;
    }
  }
  printAuto(); // print to Serial for debugging
}

void modeManual() {
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
  mode = digitalRead(manual);
  printManual();
}

void printAuto() {
  Serial.print("cm = ");
  Serial.print(cm);
  Serial.print("\t target = ");
  Serial.println(target);
}

void printManual() {
  Serial.print("distance = ");
  Serial.print(cm);
  Serial.print(" cm \t");
  Serial.print("step = ");
  Serial.print(stepper.currentPosition());
  Serial.println("\t (in manual mode)");
}
