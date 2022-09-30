/* IR_Emisor
 Un mando a distancia para o equipo de audio.
 O pulsador SR envía comandos de subir volume, SL baixara.
*/
#define IR_SEND_PIN 4   //pin do emisor de Ir
#include <IRremote.hpp>
#define L_Red 13    //LED para indicar que emite
#define SR 2    //Pulsador para enviar subir volume
#define SL 3    //Pulsador para baixar volume
int enderezo = 0x0;   //enderezo do mando-receptor
byte subeVol = 0x19;  //comando subir volume
byte vaixaVol = 0x16;   //comando baixar volume
byte comando ;

void setup() {
 pinMode(L_Red, OUTPUT); // LED
 Serial.begin(9600);
 IrSender.begin(); //inicializa o envío de datos Ir
 Serial.print("Listo para enviar comandos vía Ir, no pin ");
 Serial.println(IR_SEND_PIN);
}

void loop() {
 if ((digitalRead (SR)) == 1) { //si SR está pulsado sube volume
  comando = subeVol; 
  envia();    //chama a función enviar datos 
 }
 if ((digitalRead (SL)) == 1) { //si SR está pulsado baixa volume
  comando = vaixaVol;
  envia();
 }
}
// función para presentar datos vía serie e envialos vía Ir
void envia() {
 Serial.println();
 Serial.print("Enviando: enderezo=0x");
 Serial.print(enderezo, HEX);
 Serial.print(" comando=0x");
 Serial.print(comando, HEX);
 Serial.println();
 IrSender.sendNEC(enderezo, comando,0); //envía datos Ir
 delay(200);
}
