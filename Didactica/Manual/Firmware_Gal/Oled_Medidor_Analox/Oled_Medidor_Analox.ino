/* Oled_Medidor_Analox
*Medidor analáxico de agulla en pantalla OLED SSD1306 128 X 64
*XDeSIG
*/ 
#include <OLED_I2C.h>   //(C)Rinky-Dink Electronics,BY-NC-SA 3.0
OLED myOLED(4, A4);   //establece os pines de comunicacións I2C OLED
#define Entrada A5 // A entrada de sinal a medir 
extern uint8_t TinyFont[];  // Fontes de textos e nÃºmeros
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
// Modificando os seguintes parámetros pódese cambiar de 
// posición e de tamaño a representación analóxica.
//Radio da semicircunferencia do cuadrante (valor clave). 
const int Radio = 90; // por defecto 90.
const int Radiop = 65; //radio da semicircunferencia pequena onde comenza a agulla para evitar o Nº.(65)
const int Xcentro = 62; //coordenada centro X do cuadrante. (62)
const int Ycentro = 100; //coordenada centro Y do cuadrante. (100)
const int AngMin = 45; //Angulo mánimo para a liña da escala. (45)
const int AngMax = 135; //Angulo máximo para a liÃ±a da escala. (135)
const int Nmarcas = 4; //Nº de marcas que queremos por. (4)
//**********************************************************************
int dotX; // variables para os puntos da escala
int dotY;
int marXini; // variables de inicio e final das marcas no cuadrante
int marYini;
int marXfin;
int marYfin;
int Xini; // variables de inicio e final da agulla
int Yini;
int Xfin;
int Yfin;
int i; // Variable común 

const float Pi = 3.1415927; //Pi para calcular ángulos de grados en radiáns.
float Alfa; // ángulo no cuadrante expresado en radiáns
float AlfaMin = (AngMin - 180) * ( Pi / 180);
float AlfaMax = (AngMax - 180) * ( Pi / 180);
// calcula o paso entre os ángulos mínimo e máximo.
float Paso = (AlfaMax - AlfaMin) / Nmarcas; 
float Marca [Nmarcas]; //establece a matriz para as marcas
//Ollo por os valores como maximo de "Nmarcas"
// textos a representar no cuadrante
char const *valores [] = { "", "256", "512", "768", ""}; 
const int despra[] { 0, 10, 0, 10, 0}; // Desprazamento X para mostrar os valores no cuadrante

void setup(){
 myOLED.begin(); //inicializa o visualizador OLED 128x64
 //myOLED.invert(true); //inverte o display
  Serial.begin(115200); // inicializa a comunicación serie
  Serial.println("Inicializando");
  myOLED.setFont(SmallFont); // fonte de letra pequena
  myOLED.print("Iniciando", CENTER, 05);
  myOLED.update();
  // calculamos os ángulos onde representar as marcas e os valores das mesmas
  Alfa = AlfaMin;
  for (i = 0; i < (Nmarcas); i++) {
    Marca[i] = Alfa;
    Alfa = Alfa + Paso; // incremento ou decrecemento para adaptalo os textos
  }
}
void loop () {
 int Medida = analogRead(Entrada);  // lee a entrada analáxica
 Serial.println (Medida); // envía o valor vía serie
 myOLED.setFont(BigNumbers); 
 myOLED.printNumI(Medida, CENTER, 40); //visualiza o valor da entrada analóxica
 Pint_text();   // pinta o texto no cuadrante
 DibuCirc();  // debuxa o círculo do cuadrante
 PintMarcas();    // debuxa as marcas do cuadrante
 PintValores(); // debuxa os valores
 //*************** Pasa a media o ángulo alfa
 int MedidaM = map(Medida, 0, 1023, 45, 135); // medida a un máx de 180º
 Alfa = (MedidaM - 180) * ( Pi / 180);  // calcula o ángulo da medida
 //*************** Debuxa a agulla no cuadrante
 Xini = Radiop * cos (Alfa) + Xcentro; // calcula os puntos de inicio
 Yini = Radiop * sin (Alfa) + Ycentro;
 Xfin = Radio * cos (Alfa) + Xcentro; // calcula os puntos de fin
 Yfin = Radio * sin (Alfa) + Ycentro;
 myOLED.drawLine(Xini, Yini, Xfin, Yfin); // Debuxa a liña da agulla
 
 myOLED.update();  // presenta toda a información que ten a memoria o OLED 
 delay(1);
 myOLED.clrScr(); // borra o contido do visualizador
}

//************** Pintando os puntos da escala ******************
void DibuCirc() {
 for (float F = AlfaMin; F < AlfaMax; F = F + 0.04) {
 dotX = (Radio - 5) * cos (F) + Xcentro; // calcula os puntos X e Y
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
//************** Debuxa as marcas do cuadrante **************
void PintMarcas() {
 for (float F = AlfaMin; F < AlfaMax; F = F + Paso) {
   // Comenza a 10 puntos menos do radio para non empastelar
   marXini = (Radio - 10) * cos (F) + Xcentro; 
   marYini = (Radio - 10) * sin (F) + Ycentro;
   // Finaliza a 5 puntos por riba do circulo debuxado
   marXfin = Radio * cos (F) + Xcentro; 
   marYfin = Radio * sin (F) + Ycentro;
   myOLED.drawLine(marXini, marYini, marXfin, marYfin); // Debuxa as marcas
  }
}

//************** Pinta os textos  Echidna STEAM  **********
void Pint_text() {
  myOLED.setFont(SmallFont); // Fonte pequena
  myOLED.print("Echidna", LEFT, 55);
  myOLED.print("STEAM", RIGHT, 55);
}
