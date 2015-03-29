int whiteWalk2 = 8;
int redWalk2 = 9;
int greenDrive2 = 10;
int yellowDrive2 = 11;
int redDrive2 = 12;
int crossButton = 5;
int redWalk1 = 6;
int whiteWalk1 = 7;
int greenDrive1 = 4;
int yellowDrive1 = 3;
int redDrive1 = 2;
bool buttonState = digitalRead(crossButton);

void setup() {
 pinMode(redDrive1, OUTPUT);
  pinMode(yellowDrive1, OUTPUT);
  pinMode(greenDrive1, OUTPUT);
  pinMode(crossButton, INPUT);
  pinMode(redWalk1, OUTPUT);
  pinMode(whiteWalk1, OUTPUT);
  pinMode(whiteWalk2, OUTPUT);
  pinMode(redWalk2, OUTPUT);
  pinMode(greenDrive2, OUTPUT);
  pinMode(yellowDrive2, OUTPUT);
  pinMode(redDrive2, OUTPUT);
}


void light (int lightPin, bool state) {
    if (state) {
    digitalWrite(lightPin, HIGH);
  } else {
    digitalWrite(lightPin, LOW);
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

void Side1Stop () {
  light(redWalk1, true);
  light(redDrive1, true);
  light(whiteWalk1, false);
  light(yellowDrive1, false);
  light(greenDrive1, false);
}

void Side2Go () {
  light(greenDrive2, true);
  light(whiteWalk2, true);
  light(redWalk2, false);
  light(redDrive2, false);
  light(yellowDrive2, false);
}

void Side1Go () {
  light(greenDrive1, true);
  light(whiteWalk1, true);
  light(redWalk1, false);
  light(redDrive1, false);
  light(yellowDrive1, false);
}

void Side2Stop () {
  light(redWalk2, true);
  light(redDrive2, true);
  light(greenDrive2, false);
  light(yellowDrive2, false);
  light(whiteWalk2, false);
}

void transition (int side) {
  if (side == 1) {
    light(whiteWalk1, false);
    blink(redWalk1, 6);
    light(greenDrive1, false);
    light(yellowDrive1, true);
    blink(redWalk1, 2);
    Side1Stop();  
    Side2Go();  
  } else {
    light(whiteWalk2, false);
    blink(redWalk2, 6);
    light(greenDrive2, false);
    light(yellowDrive2, true);
    blink(redWalk2, 2);
    Side2Stop();  
    Side1Go();
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(crossButton);
  
  while (buttonState == LOW) {
      buttonState = digitalRead(crossButton);
      Side2Stop();
      Side1Go();
  }
  
  transition(1);
  buttonState = digitalRead(crossButton);

  while (buttonState == LOW) {
    buttonState = digitalRead(crossButton);
    Side1Stop();
    Side2Go();    
  }
 
 transition(2);
  
}
