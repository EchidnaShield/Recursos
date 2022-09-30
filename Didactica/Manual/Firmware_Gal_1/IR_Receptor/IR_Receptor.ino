/* IR_Receptor
   Receptor de infravermellos
   Mostra o protocolo e os datos recibidos
   Baseado no programa ReceiveDump de Armin Joachimsmeyer
*/
#include <IRremote.h> //librería 
#define RECV_PIN A4  //pin asignado o receptor
IRrecv irrecv(RECV_PIN);

#define L_RED 13     //pin led testigo de recepción

void setup()
{
  pinMode (L_RED, OUTPUT);
  Serial.begin(9600);  // iniciamos as comunicacións serie
  irrecv.enableIRIn(); // Inicia a recepción IR
   Serial.println("Receptor listo");
}

void loop() {
  if (IrReceiver.decode()) { //se temos recepción entramos na estrutura switch
    digitalWrite (L_RED, HIGH);
    Serial.print("Protocolo ");
    switch (IrReceiver.decodedIRData.protocol) { //descodifica o protocolo
      case NEC: // no caso de recibir datos co protocolo NEC
        Serial.print("NEC: "); // Envía serie "NEC"
        break;
      case SONY:
        Serial.print("SONY: ");
        break;
      case SAMSUNG:
        Serial.print("SAMSUNG: ");
        break;
      case RC5:
        Serial.print("RC5: ");
        break;
      case RC6:
        Serial.print("RC6: ");
        break;
      case UNKNOWN:
        Serial.print("Non coñecido: ");
        break;
    }
    //Envia os datos vía serie
    Serial.print ("Enderezo=0x");
    Serial.print ( IrReceiver.decodedIRData.address, HEX);
    Serial.print (" Comando=0x");
    Serial.println ( IrReceiver.decodedIRData.command, HEX);
    delay(200);//espera 200ms
    irrecv.resume();//limpa o bufer para atender outra recepción
    digitalWrite (L_RED, LOW);
  }
}
