#include "DHT.h"

// define DHT22
#define DHTTYPE DHT22
// define pin on DHT22
#define DHTPIN8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  // reading temperature and humidity about 250 ms
  // delay time for sensor readings up to 2 seconds
  float h = dht.readHumidity();

  // read temperature as Celcius (the default)
  float t = dht.readTemperature();

  // check if any reads failed and exit early (try again)
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor");
  }

  // compute heat index in celcius (isFahrenheit = false)
  float hic = dht.computeHeatIndex(t,h,false);

  Serial.print("Humidity : ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.print(" *C\t"); 
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
}
