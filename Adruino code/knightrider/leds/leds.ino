
void setup() {
  Serial.begin(9600);
  for (uint8_t thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
if (Serial.available() > 0) {
  uint8_t inByte = Serial.read();
  switch (inByte) {
    case 'a':
    digitalWrite(2, HIGH);
    break;
    
    case 'b':
    digitalWrite(3, HIGH);
    break;
    
    case 'c':
    digitalWrite(4, HIGH);
    break;
    
    case 'd':
    digitalWrite(5, HIGH);
    break;

    case 'e':
    digitalWrite(6, HIGH);
    break;
    default: 
    delay(500);
      for(int thisPin=2; thisPin < 7; thisPin++) {
        digitalWrite(thisPin, LOW);
      }
    }
  }
}
