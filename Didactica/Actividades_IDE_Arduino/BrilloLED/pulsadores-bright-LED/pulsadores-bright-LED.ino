/*
  Control de la lumninosidad de un LED RGB blanco con pulsadores
  El pulsador derecho aumenta el brillo y el izquierdo lo disminuye
  LED R pin 9
  LED G pin 5
  LED B pin 6
  pulsador Derecho pin 2
  pulsador Izquierdo pin 3


  Marzo 2020
  Jose Pujol
*/

// Variables globales

// Variables constantes para los pines
// pines de los pulsadores
const int buttonRPin = 2; // selecciona el pin del pulsador derecho
const int buttonLPin = 3; // selecciona el pin del pulsador izquierdo
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

// variables que almacenan los datos
int buttonRValue = 0; // variable para almacenar el valor del pulsador derecho
int buttonLValue = 0; // variable para almacenar el valor del pulsador derecho
int bright = 0; // variable que almacena el valor del brillo del LED

void setup() {
  // nada que declarar en el setup
  // Serial.begin(9600);
}

void loop() {
  // lee el valor de los pulsadores
  buttonRValue = digitalRead(buttonRPin);
  buttonLValue = digitalRead(buttonLPin);

  // si se presiona el pulsador derecho aumentamos el brillo
  if (buttonRValue == HIGH) {
    if (bright < 255) {
      bright++;
      delay(10);
    }
  }

  // si se presiona el pulsador izquierdo disminuimos el brillo
  if (buttonLValue == HIGH) {
    if (bright > 0) {
      bright--;
      delay(10);
    }
  }

  // escribimos el valor en analogico en el LED
  analogWrite(ledRPin, bright);
  analogWrite(ledGPin, bright);
  analogWrite(ledBPin, bright);

}
