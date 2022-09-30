/* NeoPixel_I
 * Cores o chou nun Neopixel
 */
#include <Adafruit_NeoPixel.h> //Libreria 
#define PIN A4 //Pin conectado o NeoPixel
#define NUMPIXELS 1 //Numero de NeoPixeles
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define Retardo 100 //Tempo de actualización

void setup() {
 pixels.begin(); //Inicializa o NeoPixel
 pixels.clear(); //Apaga o NeoPixel
}

void loop() {
//Eliximos cores o chou
 int Red = random(64);
 int Gre = random(64);
 int Blu = random(64);

 pixels.setPixelColor(0, pixels.Color(Red, Gre, Blu)); //Nº NeoPixel e cor
 pixels.show(); //Envia os datos o NeoPixel
 delay(Retardo); //Pausa entre envíos
}
