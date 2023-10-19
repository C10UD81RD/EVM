int flag = 0;

void setup() {
pinMode(D0, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D3, INPUT);
}

void loop(){

  if(digitalRead(D3)==HIGH&&flag==0){
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    flag=1;
  }
  
  if (digitalRead(D3)==LOW&&flag==1){
    flag=2;
  }

  if(digitalRead(D3)==HIGH&&flag==2){
    digitalWrite(D0,LOW);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
    flag=3;
  }

  if (digitalRead(D3)==LOW&&flag==3){
    flag=4;
  }

  if(digitalRead(D3)==HIGH&&flag==4){
    digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
    flag=5;
  }

  if (digitalRead(D3)==LOW&&flag==5){
    flag=0;
  }

}
