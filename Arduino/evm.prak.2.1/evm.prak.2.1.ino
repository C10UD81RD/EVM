#include "Servo.h" 
Servo servo;  

void setup() {
   servo.attach(D0);        
   pinMode(A0, INPUT); 
}
void loop() {
   int val = analogRead(A0);          
   val = map(val, 0, 1023, 0, 180); 
   servo.write(val);    
}                     
