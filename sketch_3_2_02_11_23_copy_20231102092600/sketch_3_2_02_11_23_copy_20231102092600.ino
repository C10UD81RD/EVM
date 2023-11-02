#include <SPI.h>
#include <WiFi.h>
#include "Adafruit_SHT31.h"
#include "Adafruit_LPS25HB.h"

char ssid[] = "ASOIU";    // your network SSID (name)
char pass[] = "kaf.asoiu.48"; // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) 
  {
    Serial.println("WiFi shield не найден");
    while(true);  // don't continue
  }

  WiFi.config(ip);

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) 
  {
    Serial.print("Подключение к: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }

  // print your WiFi shield's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
    
  float h = dht.readHumidity();
  float t = dht.readTemperature();

    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");

  EthernetClient client = server.available();
 
  client.println ("<!DOCTYPE HTML>");
  client.println ("<html>");
  client.println ("<body>");
  client.println ("Humidity: ");
  client.println (h);
  client.println (" %");
  client.println ("Temperature: ");
  client.println (t);
  client.println (" *C");
  client.println ("<meta http-equiv= refresh  content=5;>");
  client.println ("</body>");
  client.println ("</html>");
  client.stop();
}