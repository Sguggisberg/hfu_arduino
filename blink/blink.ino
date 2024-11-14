const int latchPin = 10;
const int clockPin = 13;
const int dataPin = 11;
const int enableOutputModule = 9;
bool a = 0;

void setup() {
  Serial.begin(9600);
  setupPings();
  setupTimer(); 
}

void loop() {
 
  if (a == 0) {
    disableLedData();
    digitalWrite(dataPin, HIGH);  // sets the digital pin 13 on
    delay(1000);                  // waits for a second
    digitalWrite(dataPin, LOW);   // sets the digital pin 13 off
    delay(1000);
    digitalWrite(dataPin, HIGH);  // sets the digital pin 13 on
    delay(1000);                  // waits for a second
    digitalWrite(dataPin, LOW);   // sets the digital pin 13 off
    delay(1000);
    enableLedData();  // waits for a second
    a = 1;
  }
}

void enableLedData() {
  digitalWrite(enableOutputModule, HIGH);
}

void disableLedData() {
  digitalWrite(enableOutputModule, LOW);
}

ISR(TIMER1_COMPA_vect) {
  PORTD ^= (1 << PD7);  // toggle Pin 7
}

void setupTimer() {
  TCCR1A = 0x00;                                      // OC2A and OC2B disconnected; Wave Form Generator: Normal Mode
  TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);  // CTC-Mode 4, prescaler = 1024;
  TIMSK1 = (1 << OCIE1A);                             // interrupt on OCR1A match
  OCR1A = 249;
  DDRD |= (1 << PD7);  // pinMode(7, OUTPUT);
}

void setupPings() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}