/* Neo_espectro
  * Visualizador de espectro de son de cinco bandas
  * Usando a pantalla de 25 Neopixeles 
  * Transformada rápida de Fourier (FFT). Autor: Dimitrios P. Bouras, mantida         
  * por Enrique Condes
  * XDeSIG 2021
*/
#include <Adafruit_NeoPixel.h>
#define PIN_NEO A4
#define NUM_LEDS 25
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN_NEO, NEO_GRB + NEO_KHZ800);

#include <fix_fft.h>  // biblioteca para calcular FFT
char re[128], im[128]; // Matrices de mostras / resultados da FFT
byte i; // índice
int dat; // variable da amplitude da frecuencia
int F[5] = {2, 3, 6, 9, 15}; // Frecuencias a mostrar en pantalla *73,8Hz
#define MIC A7   // Entrada de Audio (Micrófono)
int amp = 25;   // Valor amplificación
int Y;  // Variable de resultados (eixo Y) mapeados para mostrar na pantalla
int X;  // variable para recorer o eixo x
int A;  // Amplitude en NeoPixeles
int Pix;  // Variable de pixel a mostrar (pix = x + y*5)
int Red;  // Variable da cor vermella
int Gre;  // Variable da cor verde
int Blu;  // Variable da cor azul

void setup() {
 analogReference(INTERNAL); // Ref. Analóxica/dixital a 1.1Volts
 pixels.begin();      // Inicializamos os NeoPixeles
}

void loop() {
 // Lectura de son e calculo da amplitude por frecuencia.
 for (i = 0; i < 128; i++) { // Tomamos 128 mostras da entrada analóxica (micro)
  int sample = amp * (analogRead(MIC));
  re[i] = sample / 4 - 128; //Escalamos para axustar a un carácter de -128 a 127
  im[i] = 0; //Agora non temos valores imaxinarios e facemos todos iguais a cero
  }
  fix_fft(re, im, 7, 0); // Enviamos as mostras para a conversión FFT,      
  // devolvendo os resultados reais/imaxinarios nas mesmas matrices
 for (X = 0; X < 5; X++) { // Recorremos o eixo X da pantalla
 dat = sqrt(re[F[X]] * re[F[X]] + im[F[X]] * im[F[X]]); // A magnitude da   
 // frecuencia é a raíz cadrada da suma dos cadrados das partes real e imaxinaria 
 // dos vectores. Só recuperamos os valores das frecuencias elixidas F[x]

 // Mapeamos os valores de amplitude de cada frecuencia os píxeles verticais
 A = map(dat, 0, 25, 4, 0); 

 for (Y = 5; Y >= A ; Y--) { // Acendemos os NeoPixeles Verticais
  Pix = X + Y * 5; // Calcula as coordenadas X e Y a liña de pixeles.

 if (Y == 0) { // Axustamos a cor a cada liña
  Red = 32;
  Gre = 0;
  Blu= 0;
  }
 if (Y == 1) {
  Red = 32;
  Gre = 16;
  Blu = 0;
  }
 if (Y == 2) {
  Red = 16;
  Gre = 8;
  Blu = 0;
  }
 if (Y == 3) {
  Red = 4;
  Gre = 16;
  Blu = 0;
  }
 if (Y == 4) {
  Red = 0;
  Gre = 4;
  Blu = 2;
  }
pixels.setPixelColor(Pix, pixels.Color(Red, Gre, Blu)); // Cada NeoPixel ca sua cor
 }
for (int Y = 0; Y < A ; Y++) {  // Comprobamos que NeoPixel apagar
 Pix = X + Y * 5 ;
 pixels.setPixelColor(Pix, pixels.Color(0, 0, 0)); 
 }
 pixels.show(); // Enviamos os datos a pantalla de NeoPixeles
 }
}
