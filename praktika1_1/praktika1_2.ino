void setup() {

pinMode(led, OUTPUT);

pinMode(button, INPUT);

}

void loop(){

if (digitalRead(button) == HIGH) {

digitalWrite(led, HIGH);

}

else {

digitalWrite(led, LOW);

}

}