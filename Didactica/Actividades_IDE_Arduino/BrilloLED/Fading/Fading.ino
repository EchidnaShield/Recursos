/*
    Programa para encender y apagar LED RGB blanco gradualmente

    LED R pin 9
    LED G pin 5
    LED B pin 6

    Basado en el programa Fade de Arduino
    Jose Pujol
    Marzo de 2020
*/

// Variables globales constantes
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

void setup() {
  // nada que declarar en el set up
}
void loop() {
  // Encendido gradual del LED 
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue ++) {
    analogWrite(ledRPin, fadeValue);
    analogWrite(ledGPin, fadeValue);
    analogWrite(ledBPin, fadeValue);
    delay(10);                        // espera de 10 ms
  }
  // Apagado gradual del LED 
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue --) {
    analogWrite(ledRPin, fadeValue);
    analogWrite(ledGPin, fadeValue);
    analogWrite(ledBPin, fadeValue);
    delay(10);                        // espera de 10 ms
  }
  // tiempo de espera apagado
  delay(1000);
}
