// Xabier rosas
// Medidor analoxico de agulla en pantalla OLED 128 x 64
#include <OLED_I2C.h> //Copyright (C)2015-2019 Rinky-Dink Electronics, Henning Karlsen.CC BY-NC-SA 3.0 license.


#include "config_B.h" // Definición de todolos recursos de Echidna Shield "S",  White "W" ou Black "B"

// Fontes de textos e numeros
extern uint8_t TinyFont[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


// Modificando os seguintes parámetros podese cambiar de posicion e de tamaño da reprentación analoxica.

int radio = 62;     //radio da semicircunferencia do cuadrante (valor clave). Por defecto 62
int radiop = 27;    //radio da semicircunferencia pequena onde se presentan o dato numerico. Por defecto 27
int Xcentro = 62;   //coordenada centro X do cuadrante. Por defecto 62
int Ycentro = 62;   //coordenada centro Y do cuadrante. Por defecto 62

// variables de inicio e final das marcas no cuadrante
int marXini;
int marYini;
int marXfin;
int marYfin;

// variables de inicio e final da agulla
int Xini;
int Yini;
int Xfin;
int Yfin;



const float pi = 3.1415927; //Pi para calcular angulos de grados en radians


float alfa; // angulo da aguja no cuadrante

// Angulos en radians nos que queremos poñer as marcas
//-3.14 => 0, -2.76 => 128, -2.36 => 256, -1.97 => 384, -1.57 => 512, -1.19 => 640, -0.79 => 768, -0.40 => 896, 0 => 1023
float marca [] = { -3.14, -2.76, -2.36, -1.97, -1.57, -1.19, -0.79, -0.40, 0}; // as marcas en radians

char *valores [] = { "", "", "256", "", "512", "", "768", "", ""}; // textos a representar no cuadrante
int despra[] { 0, 0, 10, 0, 0, 0, 15, 0, 0}; // Desprazamento X para mostrar os valores no cuadrante

int i;


void setup()
{

  myOLED.begin(SSD1306_128X64);  //inicializa o visualizador OLED 128x64

  //myOLED.rotateDisplay(true); //invirte o display para adaptalo a algunha carcasa

  //Serial.begin(9600);

  //analogReference(INTERNAL);


}
void loop () {

  int medida = analogRead(A0);


  //************** Pinta a medida no centro inferior do visualizador ***********************

  myOLED.setFont(MediumNumbers);
  myOLED.printNumI(medida,Xcentro-16 , Ycentro - 14); // Imprime o valor da entrada analogica


  //************** Debuxa os circulos do cuadrante ***********************

  myOLED.drawCircle(Xcentro, Ycentro, radio - 5 ); // Circulo con 5 puntos menos que o radio seleccionado
  myOLED.drawCircle(Xcentro, Ycentro, radiop);     // Circulo pequeno para deixar sitio o valor numerico


  //*************** Pasa da media o angulo alfa  ************************

  int medidam = map(medida, 0, 1023, 0, 180); // Mapea a medida a un máx de 180º
  alfa = (medidam - 180) * ( pi / 180);       // calcula o angulo da medida


  //*************** Debuxa a agulla no cuadrante ************************

  Xini = radiop * cos (alfa) + Xcentro; // Calcula os puntos de inicio
  Yini = radiop * sin (alfa) + Ycentro;

  Xfin = radio * cos (alfa) + Xcentro;  // Calcula os puntos de fin
  Yfin = radio * sin (alfa) + Ycentro;

  myOLED.drawLine(Xini, Yini, Xfin, Yfin);         // Debuxa a agulla
  myOLED.drawLine(Xini - 1, Yini - 1, Xfin, Yfin); // Debuxa o lado esquerdo da agulla
  myOLED.drawLine(Xini + 1, Yini + 1, Xfin, Yfin); // Debuxa o lado dereito da agulla


  //************** Debuxa as marcas do cuadrante ***********************

  for (i = 0; i < 9; i = i + 1) {
    marXini = (radio - 10) * cos (marca[i]) + Xcentro;    // Comenza a 10 puntos menos que o radio seleccionado
    marYini = (radio - 10) * sin (marca[i]) + Ycentro;
    marXfin = radio * cos (marca[i]) + Xcentro;           // Finaliza a 5 puntos por riva do circulo debuxado
    marYfin = radio * sin (marca[i]) + Ycentro;

    myOLED.drawLine(marXini, marYini, marXfin, marYfin);  // Debuxa as marcas

    Pint_valores(); // Chama a rutina que pinta valores nas marcas do cuadrante

  }

  Pint_text(); // Chama a rutina que pinta o texto

  myOLED.update();    // Pinta todo o que ten na memora do visualizador
  delay(100);         // Retardo entre medidas e visualizacións
  myOLED.clrScr();    // Borra o contido do visualizador.
}




//************** Pintando os valores ***********************

void Pint_valores() {
  myOLED.setFont(SmallFont);
  marXfin = (radio + despra[i] ) * cos (marca[i]) + Xcentro - 10;
  marYfin = (radio ) * sin (marca[i]) + Ycentro;
  myOLED.print(valores[i], marXfin, marYfin);
}


//************** pintando os textos ***********************

void Pint_text() {
  myOLED.setFont(TinyFont);         // Fonte pequena
  myOLED.print("Echidna", LEFT, 0);
  myOLED.print("STEAM", RIGHT, 0);
}
