void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);
}

void loop() {
  digitalWrite(D0, HIGH);
  delay(500);
  digitalRead(D0, LOW);
  delay(500);
}
