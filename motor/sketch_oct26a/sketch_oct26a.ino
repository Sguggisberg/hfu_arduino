
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int s1Pin = 10;
const int s2Pin = 11;
const int directionSwitchPin = 4;
const int onOffSwicthStateSwitchPin = 5;
const int potPin = A0;


int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;  // 1= opening, 0= closing
int s1 = 0;
int s2 = 0;


void setup() {
  Serial.begin(9600);
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwicthStateSwitchPin, INPUT);
  pinMode(s1Pin, INPUT);
  pinMode(s2Pin, INPUT);

  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  s1 = digitalRead(s1Pin);
  s2 = digitalRead(s2Pin);
}

void open() {
  if (s1 == LOW) {
    // open
  }
  if (s2 == HIGH) {
    // error (is open)
  }
}

void doOpen() {
  motorDirection = 1;
  motorEnabled = 1;
}

void doClose() {
  motorDirection = 0;
  motorEnabled = 1;
}

bool isClosing() {
  return motorDirection == 0;
}

bool isOpenin() {
  return motorDirection == 1;
}

bool isClosed() {
  return s2 == HIGH;
}

bool isOpen() {
  return s1 == HIGH;
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwicthStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;
  if (onOffSwitchState != previousOnOffSwitchState) {
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }
  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);

  }

  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);

  } else {
    analogWrite(enablePin, 0);
  }
  delay(500);
  s1 = digitalRead(s1Pin);
  //Serial.println(s1);
  Serial.print("Richtung: ");
  Serial.println(motorDirection);
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
