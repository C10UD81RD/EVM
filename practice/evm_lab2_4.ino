#include <TroykaIMU.h>
#include <TroykaMeteoSensor.h>

Barometer barometer;
TroykaMeteoSensor meteoSensor;
 
void setup() {
  Serial.begin(115200);
  while(!Serial) {
  }
  //Serial.println("Иницилизация serial-порта в порядке");
  meteoSensor.begin();
  //Serial.println("Иницилизация метеосенсора в порядке");
  delay(1000);
  Serial.begin(9600);
  //Serial.println("Начало IMU");
  barometer.begin();
  //Serial.println("Инициализация барометра в порядке");
  delay(1000);
}
 
void loop() {
  // считываем данные с датчика
  int stateSensor = meteoSensor.read();
  // проверяем состояние данных
  switch (stateSensor) {
    case SHT_OK:
  // выводим показания влажности и температуры
      Serial.print("Температура = ");
      Serial.print(meteoSensor.getTemperatureC());
      Serial.print(" C \n");
      Serial.print("Влажность = ");
      Serial.print(meteoSensor.getHumidity());
      Serial.print(" %\n");
      break;

    // ошибка контрольной суммы
    case SHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
  }
  // Выводим значения атмосферного давления в мм рт.ст.
  Serial.print("Давление = ");
  Serial.print(barometer.readPressureMillimetersHg());
  Serial.print("мм рт.ст.\n");
  // Выводим значения высоты над уровнем море
  Serial.print("Высота над уровнем моря = ");
  Serial.print(barometer.readAltitude());
  Serial.print("мм\n");
  // Выводим значения температуры окружающей среды
  Serial.print("Температура окружающей среды = ");
  Serial.print(barometer.readTemperatureC());
  Serial.print(" C \n");
  Serial.println();
  delay(5000);
}