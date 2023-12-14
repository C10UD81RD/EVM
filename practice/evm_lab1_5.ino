uint8_t CrrentD3 = 0;
unsigned int timerCount; 
int step = 0;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  if ((millis() - timerCount) > 500){
    timerCount = millis();
    if (step == 0){
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
    }
    else if (step == 1){
      digitalWrite(D0, LOW);
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
    }
    else if (step == 2){
      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
    }
    ++step;
    if (step >= 3) step = 0;
  }
}





