# DHT11 Sensörü Kullanımı
> Sensörü 5V ile çalıştırın ve toprağı toprağa bağlayın.

> Veri pimini _(DATA’yı)_ bir dijital pime 2 bağlayın.
```c
#include "DHT.h"  //DHT11 Kütüphanesi

#define DHTPIN 2  //DHT11 data pini

DHT dht(DHTPIN, DHT11);

void setup() {
  Serial.begin(9600); //Seri haberleşme başlatılır
  dht.begin();        //dht başlatılır
}

void loop() {
  delay(2000);        //Her okuma arasında 2sn beklenir

  float nem = dht.readHumidity();          //Nem bilgisi alınır
  float sicaklik = dht.readTemperature();  //Sıcaklık bilgisi alınır

  //Okunan değerler seri porttan gönderilir
  Serial.print("Nem ");
  Serial.print(nem  );
  Serial.print(" %\t");
  Serial.print("Sıcaklık: ");
  Serial.print(sicaklik);
  Serial.println(" *C ");
}
```
## Bağlantı Şeması

![sema](https://github.com/yunusemreaydinli/DHT11/blob/main/sema.png)
