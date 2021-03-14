#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN D1
#define DHTTYPE DHT11
char ssid[]="aparanji";
char pass[]="aparanji@123";
char auth[]="zvjS2D9HEiFmi0YrwfWO8QH7Mr-GpAtR";
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sensorData()
{
  int x=analogRead(A0);
  float volt=3.3*x/1023;
  float temp=dht.readTemperature();
  float humid=dht.readHumidity();
  Blynk.virtualWrite(V1,volt);
  Serial.println(volt);
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth,ssid,pass);
dht.begin();
timer.setInterval(1000L,sensorData);
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
timer.run();
}
