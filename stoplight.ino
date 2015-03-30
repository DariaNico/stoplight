int whiteWalk2 = 8;
int redWalk2 = 9;
int greenDrive2 = 10;
int yellowDrive2 = 11;
int redDrive2 = 12;
int crossButton = 2;
int redWalk1 = 6;
int whiteWalk1 = 7;
int greenDrive1 = 5;
int yellowDrive1 = 4;
int redDrive1 = 3;
int buttonState = 0;
int timeRemaining = 40;
int state = 1;
int newState = 2;

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

void walkButton () {
  if  (timeRemaining > 12) {
     timeRemaining = 12;
   }
}
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
  Side1Go();
  Side2Stop();
  Serial.begin(9600);
  attachInterrupt(0, walkButton, HIGH);
}

void loop() {
  if (timeRemaining < 4) {
    Serial.println();
    Serial.println();
    Serial.println();

    switch(state) {
    case 1:
      newState = 2;
      timeRemaining = 8;
      light(greenDrive1, false);
      light(yellowDrive1, true);  
      break;
    case 2:
      newState = 3;
      timeRemaining = 40;
      Side1Stop();
      Side2Go();    
      break;
    case 3:
      newState = 4;
      timeRemaining = 8;
      light(greenDrive2, false);
      light(yellowDrive2, true);
      break; 
    case 4:
      newState = 1;
      timeRemaining = 40;
      Side1Go();
      Side2Stop(); 
    }
    state = newState;
    
   
  }
  
  if ((state == 3) && (timeRemaining < 20)) {
    light(whiteWalk2, false);
    if (timeRemaining%2) {
      light(redWalk2, true);
    } else {
      light(redWalk2, false);
    }
  }
  
    if ((state == 1) && (timeRemaining < 20)) {
    light(whiteWalk1, false);
    if (timeRemaining%2) {
      light(redWalk1, true);
    } else {
      light(redWalk1, false);
    }
  }
  
  buttonState = digitalRead(crossButton);
  Serial.print("button: ");
  Serial.println(buttonState);
  timeRemaining--;
  Serial.print("This is the state: ");
  Serial.print(state);
  Serial.print("\t Time remaining: ");
  Serial.println(timeRemaining);
  delay(250);
}
