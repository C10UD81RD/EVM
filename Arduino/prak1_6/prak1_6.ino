void setup(){
  pinMode(D0, OUTPUT);
  pinMode(A0, INPUT);
}
 
void loop(){
  int rotat, brightn;  
 
  rotat = analogRead(A0);

  brightn = rotat / 4;
 
  analogWrite(D0, brightn);
}