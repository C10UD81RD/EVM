uint8_t CrrentD3 = 0;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, INPUT);
  attachInterrupt(D3, hend, FALLING);
}

void loop() {}

void hend(){
  if (digitalRead(D3)==LOW) {
    if (CrrentD3 == 0){
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    CrrentD3 = 1;
    }
    else{
      if (CrrentD3 == 1){
        digitalWrite(D0, LOW);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, LOW);
        CrrentD3 = 2;
      }
      else{
        if (CrrentD3 == 2){
          digitalWrite(D0, LOW);
          digitalWrite(D1, LOW);
          digitalWrite(D2, HIGH);
          CrrentD3 = 3;
        }
        else{
          digitalWrite(D0, LOW);
          digitalWrite(D1, LOW);
          digitalWrite(D2, LOW);
          CrrentD3 = 0;
        }
      }
    }
    delay(200);
  }
}




