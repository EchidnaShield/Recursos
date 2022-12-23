/* NeoPix_Vu_linea_Pant
 * Visualizador da amplitude de audio de cinco bandas
 * Usando a pantalla de 5 x 5 Neopixeles 
 * "https://github.com/xdesig/5x5_NeoPixel_2020"
*/

#include <Adafruit_NeoPixel.h>
#define PIN_NEO A4
word Col = 5;   //columnas
word Fil = 5;   //Filas

int NUM_LEDS = Col * Fil;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN_NEO, NEO_GRB + NEO_KHZ800);

#define MIC 7    // Entrada de Audio (Microfono)
#define SR 2    // Pulsador para subir a amplificacion
#define SL 3    // Pulsador para bajar a amplificacion

int Amp = 25;     // Valor amplificacion
int Son;      // Volume de audio
int A;      // Amplitude en leds

int Y;  // Variable de resultados (eixo Y) mapeados para mostrar na pantalla
int X;      // variable para recorer o eixo x
int Pix;      // Variable de pixel a mostrar (pix = x + y*5)
int Retardo = 1;   // Retardo en milisegundos entre ciclos 

int Red;      // Variable da cor vermella
int Gre;      // Variable da cor verde
int Blu;      // Variable da cor azul

void setup() {
 analogReference(INTERNAL);   //Ref. do conversor analóxico/dixital a 1.1Volts
  pinMode(SR, INPUT);     // Definimos o rol de cada pin
  pinMode(SL, INPUT);
  pixels.begin();     // Inicializamos os NeoPixeles
}
void loop() {

 for (X = 0; X < Col; X++) {    // Percorremos a pantalla no eixo X
 // Lemos a entrada de son e a multiplicamos por Amp
 Son = (analogRead(MIC) * Amp); 
  if (Son>=1023){   // comprobamos que non superamos o valor máximo
   Son = 1023;
   }
// Mapeamos os valores de amplitude (filas) e os invertemos 
// para iluminalos dende abaixo arriba
 A = map(Son, 0, 1023, Fil, 0);  
 Red = random (16,32); //eliximos as cores de cada Ciclo “colores o chou”
 Gre = random (4,32);
 Blu = random (4,32);

 for (Y = Fil; Y >= A ; Y--) {  // Acendemos os NeoPixeles Verticais
 Pix = X + Y * Col; // Pasamos as coordenadas X e Y a linea de pixeles
 // Acendemos cada pixel ca sua cor
 pixels.setPixelColor(Pix, pixels.Color(Red, Gre, Blu)); 
 }
// Apagando os pixeles superiores o valor máximo medido de cada columna
// Usamos “A-1” para non apagar os Neopixeles inferiores
 for (int Y = 0; Y < A-1; Y++) { 
  Pix = X + Y * Col ;
  pixels.setPixelColor(Pix, pixels.Color(0, 0, 0)); 
  }
 pixels.show(); // Enviamos os datos a pantalla de NeoPixeles
 }
 delay(Retardo); // un pequeno retardo entre ciclos
}
