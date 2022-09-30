/* SoftwareSerial
 * Abre unha canle serie nos pines especificados
 * Usamos dous dos de libre disposición
 * D4 como RXD,
 * D7 como TXD
 */
#include <SoftwareSerial.h> //Librería incluída no IDE

#define BaudRate 38400 // Velocidade de comunicacións

SoftwareSerial SoftSerial(4, 7); // Asina os pines 4 RXD, 7 TXD

void setup() {
    Serial.begin(BaudRate); // Inicializa o porto de comunicacións 
    Serial.println("Canle serie funcionando"); // Mensaxe de cortesía
    SoftSerial.begin(BaudRate); // Inicializa o porto de comunicacións software

 }
void loop() { 
  if (SoftSerial.available()) { // Si ten datos SoftSer.os pasa a canle normal
    Serial.write(SoftSerial.read());
     }
  if (Serial.available()) {
    SoftSerial.write(Serial.read()); // Si ten datos  os pasa a canle Softw
 }
}
