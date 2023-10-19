void setup() { 
  myservo.attach(D0);
} 
 
void loop() { 
  map(analogRead(A0), 0, 1023, 0, 180);
  myservo.write(potVal);
  delay(15);
} 