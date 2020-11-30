# DHT11 Sensörü Kullanımı
[![Version0](https://api.travis-ci.org/dwyl/esta.svg?branch=master&status=passed)](https://github.com/yunusemreaydinli/DHT11) 
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![Open Source? Yes!](https://badgen.net/badge/Open%20Source%20%3F/Yes%21/blue?icon=github)](https://github.com/yunusemreaydinli/DHT11/)
##

DHT11'in nasıl kullanıldığını, nasıl bağlantılarının yapıldığını, nasıl kodladığını görüceksiniz. Meraklı ve sabırlı olmanızı diliyor ve bir sözle başlamak istiyorum.

> Merak öğrenme mumunun fitilidir. W. Arthur Ward

## 
- İlk önce DHT11 Kütüphanesini kuralım. [Buraya tıklayarak](https://www.arduino.cc/reference/en/libraries/dht-sensor-library/) ‘Releases’ bölümünden en son sürümü indirin. 
DHT11 Kütüphanemiz indiğine göre artık Arduino’ya kütüphanemizi yükleyelim.
Nasıl yüklemeniz gerektiğini bilmiyor iseniz [buraya tıklayarak](https://www.robimek.com/arduinoya-kutuphane-nasil-eklenir/) nasıl Arduino’ya yükleyeceğinizi görseller ile görebilirsiniz!
Kütüphanemizi de eklediğimize göre artık kodlamaya geçebiliriz.

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

- Sensörü 5V ile çalıştırın ve toprağı toprağa bağlayın.

- Veri pimini _(DATA’yı)_ bir dijital pime 2 bağlayın.

![sema](https://github.com/yunusemreaydinli/DHT11/blob/main/sema.png)
