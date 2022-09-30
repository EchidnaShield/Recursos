/* Oled_Cadro_JOY
 * Debuxa un cadro limite do joystick
 */
#include <OLED_I2C.h> //(C)Rinky-Dink Electronics
OLED myOLED(4, A4); //establece os pines de comunicación I2C OLED A4 e D4
//******** Establece as entradas da sinal a medir *****
#define EntradaX A0
#define EntradaY A1
//******** Establece os valores mínimos e máximos
const int VXmin = 0;
const int VXmax = 1023;
const int VYmin = 0;
const int VYmax = 1023;
const int Radio = 15; //Radio da circunferencia
int PosX = 64; //coordenada centro X 
int PosY = 32; //coordenada centro Y
int MedidaX; //variable para a lectura do valor X
int MedidaY; //variable para a lectura do valor Y
int i; // Variable común
void setup()
{
  myOLED.begin(); //inicializa o visualizador OLED 128x64
  Serial.begin(115200); // Inicializa a comunicación serie
  }
void loop () {
  //************** Lee a entrada analóxica ***********************
  int MedidaX = analogRead(EntradaX);
  int MedidaY = analogRead(EntradaY);
  //************** Envía o valor vía serie ***********************
  Serial.print (MedidaX);
  Serial.print ("\t");
  Serial.println (MedidaY);
  //************** Escalamos os valores X e Y o tamaño da pantalla 
  PosX = map( MedidaX, VXmin, VXmax, 0+Radio , 128-Radio );
  PosY = map( MedidaY, VYmin, VYmax, 64-Radio , 0+Radio );
  //************** Debuxa o rectángulo ***********************
  myOLED.drawRect(0, 0, 127, 63); // coordenadas inicio x,y fin x,y
  //************** Debuxa o circulo na posición dada polo joystick ********
  myOLED.drawCircle( PosX, PosY, Radio); 
  //************** Presenta toda a información que ten na memoria OLED **
  myOLED.update();
  delay(1);
  //************** Borra o visualizador ***********************
  myOLED.clrScr();
}
