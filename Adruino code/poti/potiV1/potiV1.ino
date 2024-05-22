void setup() {
Serial.begin(9600);

}

void loop() {
  uint16_t sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1); 
}
