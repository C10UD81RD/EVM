int valpot = 0;
int angleServo = 0; 

void setup() {
  analogWriteFreq(25000);
}

void loop() {    
  valpot = analogRead(A0);
  angleServo=map(valpot, 0,4095, 0, 255);
  analogWrite(D0, angleServo);
  analogWrite(D1, angleServo);
}
