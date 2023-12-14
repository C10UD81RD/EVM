#include <SPI.h>
#include <WiFi.h>
#include <string>
std::string ssid = "ASOIU";     
std::string pass = "kaf.asoiu.48";   
int status = WL_IDLE_STATUS;  
int pingResult;

void setup() {
  Serial.begin(9600); // Инициализируем вывод данных на серийный порт со скоростью 9600 бод
  while (!Serial) {
	  // ждём, пока не откроется монитор последовательного порта для того, чтобы отследить все события в программе
    continue;
  }
  //проверка существования модуля
  if (WiFi.status() == WL_NO_SHIELD){
    Serial.println("WiFi module not present");
    //если модуля нет, то не продолжать работу далее
    while (true);
  } 
  //попытка подключения к wifi сети
  while (status != WL_CONNECTED){
    Serial.print("Attempting to connect to WPA SSID: "); //вывод надписи о попытке подключения
    Serial.println(ssid.c_str()); //вывод названия сети
    //подключение к сети, используя имя и пароль
    status = WiFi.begin(ssid.c_str(), pass.c_str());// Инициализируем подключение к указанной вайфай сети
    delay(500);
  }
  Serial.print(WiFi.localIP());
}

void loop() {
  if (Serial.available())
  {
    std::string hostname;
    hostname = Serial.readString().c_str();
    Serial.print("Pinging ");
    Serial.print(hostname.substr(0, hostname.size() - 1).c_str());
    Serial.print(": ");
    pingResult = WiFi.ping(hostname.substr(0, hostname.size() - 1).c_str());
    if (pingResult >= 0) {
      Serial.print("SUCCESS! RTT = ");
      Serial.print(pingResult);
      Serial.print(" ms");

    } 
    else {
      Serial.print("FAILED! Error code: ");
      Serial.println(pingResult);
    }
    delay(5000);
  }
}
