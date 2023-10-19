//Силовой ключ и вентилятор (4-pin) подключены к пинам D0 и D1 управляются ШИМ на частоте 25КГц.
//Скважность ШИМ регулируется поворотом потенциометра подключенного к пину A0.
#include <AmperikaFET.h>
#include <SPI.h>
#include <stream>
#include <iostream>

void setup() {
  Serial.begin(9600);
  
}

void loop() {

}
