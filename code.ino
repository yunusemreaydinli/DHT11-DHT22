#include "DHT.h"  //DHT11 Library

#define DHTPIN 2  //DHT11 data pin

DHT dht(DHTPIN, DHT11);

void setup() {
  Serial.begin(9600); //Serial communication is started
  dht.begin();        //dht is initialized
}

void loop() {
  delay(2000);        //Wait 2 seconds between each reading

  float nem = dht.readHumidity();          //Humidity information is obtained
  float sicaklik = dht.readTemperature();  //Temperature information is received

  //Read values are sent from serial port
  Serial.print("Humidity ");
  Serial.print(nem  );
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(sicaklik);
  Serial.println(" *F ");
}
