// Xabier Rosas 2020-2021 para Echidna
// Mover un circulo na pantalla OLED SSD1306 128 X 64

#include "config_S.h" // Definición de todolos recursos de Echidna Shield "S",  White "W" ou Black "B"

#include <OLED_I2C.h> //Copyright (C)2015-2019 Rinky-Dink Electronics, Henning Karlsen.CC BY-NC-SA 3.0 license.
OLED  myOLED(4, A4);  //establece os pines de comunicacións I2C OLED


//******** Establece as entradas de sinal a medir *****

#define EntradaX Joy_X
#define EntradaY Joy_Y

//******** Establece los valores minimos y maximos 
//para adapartlos a los valores de las entradas.
const int VXmin = 0;
const int VXmax = 1023;
const int VYmin = 0;
const int VYmax = 1023;

//*****************************************************


const int Radio =   15;   //Radio da semicircunferencia do cuadrante (valor clave). Por defecto 90.
int PosX = 64; //coordenada centro X do cuadrante. Por defecto 62.
int PosY = 32; //coordenada centro Y do cuadrante. Por defecto 32.



//*************************************************************************************
int MedidaX; // variable para a lectura do valor X
int MedidaY;

// Variable comun
int i;

//******************************************************************************************************

void setup()
{

  myOLED.begin(SSD1306_128X64);  //inicializa o visualizador OLED 128x64

  //myOLED.rotateDisplay(true); //invirte o display para adaptalo a algunha carcasa

  Serial.begin(9600);         // Inicializa a comunicación serie

  //analogReference(INTERNAL);    // Cambia a referencia do conversor analoxico - dixital

  //https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/

}


void loop () {

  //************** Lee a entrada analoxica ***********************
  int MedidaX = analogRead(EntradaX);
  int MedidaY = analogRead(EntradaY);

  //************** Envia o valor via serie ***********************
  Serial.print (MedidaX);
  Serial.print ("\t");
  Serial.println (MedidaY);


  PosX = map( MedidaX, VXmin, VXmax, 0 , 128 );
  PosY = map( MedidaY, VYmin, VYmax, 64 , 0 );

  //************** Dibuja un rectangulo ***********************
  myOLED.drawRect(0, 0, 127, 63); // coordenadas inicio x,y fin x,y

  //************** Debuxa o circulo ***********************
  myOLED.drawCircle( PosX, PosY, Radio); 

  //************** Presenta toda a información que ten a memoria do OLED **
  myOLED.update();
  delay(1);
  //**************  Borra o contido do visualizador ***********************
  myOLED.clrScr();
}
