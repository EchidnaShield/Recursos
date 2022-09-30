/* DHT_HT
   Lectura da %de humidade e temperatura co sensor DHT11
   Baseado nno programa escrtito por ladyada de Adafruit
   Precisamos as librerias DHT-sensor-library e Adafruit_Sensor
*/
#include "DHT.h"
#define Sensor DHT11  // tipo de sensor, tamén podemos usar o DHT22 que é mellor
#define Pin_Sen 4     // pin onde conectamos o sensor
DHT dht(Pin_Sen, Sensor); //Sensor conectado en D4 e o modelo DHT11
int h;  //variable para almacenar %da humidade
int t;  //variable para almacenar a temperatura

void setup() {
  Serial.begin(9600); // inicia as comunicacións
  Serial.println("Test DHT11!");
  dht.begin();        // comenzan as medidas
  pinMode (Pin_Sen, INPUT_PULLUP);    //Activamos a resistencia interna Pull up)
}

void loop() {
  delay(2000);   //Esperamos dous segundos entre medidas, é un sensor moi lento
  int h = dht.readHumidity();   // Leemos a %de humidade
  int t = dht.readTemperature(); // Leemos a temperatura

  // Check if any reads failed and exit early (to try again).
  // Chequeamos si algunha medida falla e tentalo outa vez
  if (isnan(h) || isnan(t)) {
    Serial.println("Faio de lectura do DHT!");
    return;
  }
  int hic = dht.computeHeatIndex(t, h, false); // Devolta o valor en ºC (Fahreheit = false)

  Serial.print(F("Humidade: "));    // envia os valores vía serie
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C "));
}
