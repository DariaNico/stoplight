void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);xs
  pinMode(7, OUTPUT);
}

void redDrive (bool state) {
  if (state) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

void yellowDrive (bool state) {
  if (state) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}

void greenDrive (bool state) {
  if (state) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
}

void whiteWalk (bool state) {
  if (state) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }
}

void redWalk (bool state) {
  if (state) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
}

void blink(int light, int secs) {
  for(secs; secs >= 0; secs--) {
    digitalWrite(light, HIGH);
    delay(250);
    digitalWrite(light, LOW);
    delay(250);
    digitalWrite(light, HIGH);
    delay(250);
    digitalWrite(light, LOW);
    delay(250);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = digitalRead(5);

while (buttonState == LOW) {
  whiteWalk(true);
  redDrive(true);
  redWalk(false);
  greenDrive(false);
  yellowDrive(false);
  buttonState = digitalRead(5);
}

  delay(3000);
  redDrive(false);
  whiteWalk(false);
  greenDrive(true);
  redWalk(true);
  
  // keep walk light on for 2 secs
  delay(2000);
  whiteWalk(false);
  blink(6,6);
  greenDrive(false);
  yellowDrive(true);
  blink(6,2);
  
  redWalk(true);
  yellowDrive(false);
  redDrive(true);
  buttonState = digitalRead(5);
  
  // start blinking red walk for 8 seconds before solid red
  
  // after 8 sec of green, turn yellow for 2 secs before red

}
