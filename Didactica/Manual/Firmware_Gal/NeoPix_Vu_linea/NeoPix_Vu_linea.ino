/* NeoPix_Vu_linea
   Vúmetro dunha tira de 10 NeoPixeles
*/

#include <Adafruit_NeoPixel.h> //librería
#define PIN A4  //Pin onde se conecta a tira de NeoPixeles
#define NUM_LEDS 300 //Numero de pixeles
#define Mic A7   //Entrada conectada o micrófono

int Son = 0;   //Variable de lectura do son
word amp = 150;//35;   //factor de amplificación
int A = 0;         //Variable de amplituse do son.

word mostras = 20; //numero de mostras (máx. 255)
double mSon = 0;   //variable de mostras de son

word retardo = 15; //Retardo entre ciclos

word Red;   //Variables para as cores
word Gre;
word Blu;
word Y;   //variable exixo Y
//Crea o obxecto co nº de LEDes, o pin, a secuencia de cores e a frecuencia de comunicación
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  analogReference(INTERNAL); //Axustamos a referencia interna a 1.1V
  pixels.begin(); //Inicia a comunicación con NeoPixeles
  pixels.clear(); //Borra todos pixeles
  pixels.show(); //Envía os datos
}

void loop() {
  //Media aritmética da entrada de son
  for (int i = 0; i < mostras; i++) {
    Son = analogRead(Mic) * amp;
    if (Son > 1023) {  //comproba que non superamos o máximo
      Son = 1023;
    }
    mSon = mSon + Son;
  }
  mSon = mSon / mostras;  //Realiza a media aritmética

  // mapea o valor do son o nº de leds
  A = map(mSon, 0, 1023, 0, NUM_LEDS );

  //Axuste da cor en funcion dos NeoPixeles accesos entre cero e o valor máximo
  for ( Y = 0; Y <= A ; Y++) {
    if (Y >= (NUM_LEDS * 4 / 5 )) { // 4/5 do total de NeoPixeles en vermello
      Red = 16;
      Gre = 0;
      Blu = 0;
    }
    if (Y > (NUM_LEDS / 2) and Y < (NUM_LEDS * 4 / 5)) { //NeoPixeles en laranxa.
      Red = 16;
      Gre = 8;
      Blu = 0;
    }

    if (Y < (NUM_LEDS / 2)) { //A metade de NeoPixeles en verde
      Red = 0;
      Gre = 8;
      Blu = 0;
    }
    pixels.setPixelColor(Y, pixels.Color(Red, Gre, Blu));
  }

  //Borra pixels superiores entre o valor máximo e o total de NeoPixeles
  for (Y = A + 1; Y < NUM_LEDS; Y++) {
    pixels.setPixelColor(Y, pixels.Color(0, 0, 0));
  }

  pixels.show(); //Envía os datos aos NeoPixeles
  delay(retardo);  //Pequeno retardo para deixar ver os Neopixeles
}
