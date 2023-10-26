#include <SPI.h>
#include <AmperkaFET.h>
#include <string> 
#include <sstream> 

FET mosfet(D17, 2);
uint32_t pin,key,stat; 

void setup() 
{
  mosfet.begin(); 
  Serial.begin(); 
}

void loop() 
{
  if (Serial.available() > 0)
  { 
  
    std::stringstream input; 
    input << Serial.readString().c_str(); 
    input >> pin >> key >> stat; 
  
    if (pin > 1) 
    { 
      pin = 255; 
    } 
    if(key > 8) 
    { 
      key = 255; 
    } 
    if(stat>0) 
    { 
      stat = 1; 
    } 
    mosfet.digitalWrite(pin, key, stat); 
  }
}