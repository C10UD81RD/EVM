void setup() {
  pinMode(D0, OUTPUT);
}

void loop() {
  if ((!digitalRead(D3))==HIGH) {
    digitalWrite(D0, HIGH);
  }
  else{
    digitalWrite(D0, LOW);
  }
}




