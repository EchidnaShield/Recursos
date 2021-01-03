// Xabier Rosas 2020-2021 para Echidna
// Medidor analoxico de agulla en pantalla OLED SSD1306 128 X 64

#include "config_S.h" // Definición de todolos recursos de Echidna Shield "S",  White "W" ou Black "B"

#include <OLED_I2C.h> //Copyright (C)2015-2019 Rinky-Dink Electronics, Henning Karlsen.CC BY-NC-SA 3.0 license.
OLED  myOLED(4, A4);  //establece os pines de comunicacións I2C OLED

//******** Establece a entrada de sinal a medir *******

#define Entrada Joy_X
//*****************************************************


// Fontes de textos e numeros
extern uint8_t TinyFont[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


// Modificando os seguintes parametros podese cambiar de posicion e de tamaño a reprentacion analoxica.

const int Radio =   90;   //Radio da semicircunferencia do cuadrante (valor clave). Por defecto 90.
const int Radiop =  65;   //Radio da semicircunferencia pequena onde comenza a agulla para evitar o Nº.
const int Xcentro = 62;   //coordenada centro X do cuadrante. Por defecto 62.
const int Ycentro = 100;  //coordenada centro Y do cuadrante. Por defecto 90.
const int AngMin =  45;   //Angulo minimo para a liña da escala.
const int AngMax =  135;  //Angulo maximo para a liña da escala.
const int Nmarcas = 4;    //Nº de marcas que queremos por.

//****************************************************************************************************


// variables para os puntos da escala
int dotX;
int dotY;

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

// Variable comun
int i;

//Valor de Pi para calcular angulos de grados en radians
const float Pi = 3.1415927;


float Alfa; // angulo no cuadrante expresado en radians

float AlfaMin = (AngMin - 180) * ( Pi / 180);
float AlfaMax = (AngMax - 180) * ( Pi / 180);
float Paso = (AlfaMax - AlfaMin) / Nmarcas;        // calcula o paso entre os angulos minimo e maximo.


//**************************************************
float Marca [Nmarcas];

//Ollo por os valores como maximo de "Nmarcas"

char const *valores [] = { "", "256", "512", "768", ""}; // textos a representar no cuadrante
const int despra[] { 0, 10, 0, 10, 0};                    // Desprazamento X para mostrar os valores no cuadrante

//******************************************************************************************************

void setup()
{

  myOLED.begin(SSD1306_128X64);  //inicializa o visualizador OLED 128x64

  //myOLED.rotateDisplay(true); //invirte o display para adaptalo a algunha carcasa

  Serial.begin(9600);         // Inicializa a comunicación serie

  //analogReference(INTERNAL);    // Cambia a referencia do conversor analoxico - dixital

  //https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/

  //**** calculamos os angulos onde representar as marcas e os valores das mesmas
  Alfa = AlfaMin;
  for (i = 0; i < (Nmarcas); i++) {
    Marca[i]  = Alfa;
    Alfa = Alfa + Paso;
  }
}


void loop () {

  //************** Lee a entrada analoxica ***********************
  int Medida = analogRead(Entrada);

  //************** Envia o valor via serie ***********************
  Serial.println (Medida);

  //************** Pinta a medida no centro inferior do visualizador ***********************

  myOLED.setFont(BigNumbers);
  myOLED.printNumI(Medida, CENTER, 40); //visualiza o valor da entrada analogica

  //************** pinta o texto no cuadrante ****************************
  Pint_text();

  //************** Debuxa os circulos do cuadrante ***********************
  DibuCirc();

  //************** Debuxa as marcas do cuadrante *************************
  PintMarcas();

  //************** Debuxa as marcas do cuadrante *************************
  PintValores();

  //*************** Pasa da media o angulo alfa  *************************

  int MedidaM = map(Medida, 0, 1023, 45, 135); // Mapea a medida a un máx de 180º
  Alfa = (MedidaM - 180) * ( Pi / 180);        // calcula o angulo da medida


  //*************** Debuxa a agulla no cuadrante ************************

  Xini = Radiop * cos (Alfa) + Xcentro;     // Calcula os puntos de inicio
  Yini = Radiop * sin (Alfa) + Ycentro;

  Xfin = Radio * cos (Alfa) + Xcentro;      // Calcula os puntos de fin
  Yfin = Radio * sin (Alfa) + Ycentro;

  myOLED.drawLine(Xini, Yini, Xfin, Yfin);  // Debuxa a liña que representa a agulla


  //************** Presenta toda a información que ten a memoria do OLED ***********************
  myOLED.update();
  delay(1);
  //**************  Borra o contido do visualizador ***********************
  myOLED.clrScr();
}

//************************************************************************************


//************** Pintando os puntos da escala ******************

void DibuCirc() {

  for (float F = AlfaMin; F < AlfaMax; F = F + 0.04) {
    dotX = (Radio - 5) * cos (F) + Xcentro; // calcula o punto X e Y cun Radio - 5 puntos menor que o radio
    dotY = (Radio - 5) * sin (F) + Ycentro;
    myOLED.setPixel(dotX, dotY);
  }
}

//************** Pintando os valores ***********************

void PintValores() {
  for (i = 0; i < Nmarcas; i++) {
    myOLED.setFont(SmallFont);
    marXfin = (Radio + despra[i] ) * cos (Marca[i]) + Xcentro - 10;
    marYfin = (Radio ) * sin (Marca[i]) + Ycentro - 5;
    myOLED.print(valores[i], marXfin, marYfin);
  }
}


//************** Debuxa as marcas do cuadrante ***********************
void PintMarcas() {

  for (float F = AlfaMin; F < AlfaMax; F = F + Paso) {
    marXini = (Radio - 10) * cos (F) + Xcentro;    // Comenza a 10 puntos menos que o Radio seleccionado
    marYini = (Radio - 10) * sin (F) + Ycentro;
    marXfin = Radio * cos (F) + Xcentro;           // Finaliza a 5 puntos por riva do circulo debuxado
    marYfin = Radio * sin (F) + Ycentro;
    myOLED.drawLine(marXini, marYini, marXfin, marYfin);  // Debuxa as marcas
  }
}

//************** Pinta os textos ***********************

void Pint_text() {
  myOLED.setFont(SmallFont);         // Fonte pequena
  myOLED.print("Echidna", LEFT, 55);
  myOLED.print("STEAM", RIGHT, 55);
}
