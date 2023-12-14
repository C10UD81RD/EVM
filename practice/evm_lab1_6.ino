#define LED D0
int pin_size = A0;

void setup() {
  analogWriteFreq(120);
}

void loop() {
  analogWrite(LED, map(analogRead(pin_size), 0, 4095, 0, 255));
}




