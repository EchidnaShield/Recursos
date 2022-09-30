



#define IR_SEND_PIN         4 //pin do emisor de Ir
#include <IRremote.hpp>

#define L_Red 13//LED para indicar que emite
#define SR 2  //Pulsador para enviar subir volume
#define SL 3  //Pulsador para baixar volume

uint16_t enderezo = 0x0;  //enderezo do mando-receptor
uint8_t subeVol = 0x19;   //comando subir volume
uint8_t vaixaVol = 0x16;  //comando baixar volume
uint8_t comando = 0x44;

void setup() {
  pinMode(L_Red, OUTPUT); // LED
  Serial.begin(9600);
  IrSender.begin();
  Serial.print("Listo para enviar comandos vía Ir, no pin ");
  Serial.println(IR_SEND_PIN);
}

void loop() {

  Serial.println();
  Serial.print("Enviando: enderezo=0x");
  Serial.print(enderezo, HEX);
  Serial.print(" commando=0x");
  Serial.print(comando, HEX);
  Serial.println();
  IrSender.sendNEC(enderezo, comando, 0);
  delay(1000);
}
