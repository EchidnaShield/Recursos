/*
   Pulsador con Memoria
  Pulsador para controlar un LED con memoria

  Pulsador pin 3
  LED RGB pines 9, 5, 6

   Noviembre de 2017
   Jose Pujol
*/
// constantes que no cambian se usan para establecer los pines
const int buttonPin = 3;     // el numero del pin del pulsador
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

// variables que cambian
int ledState = LOW;         // Estado actual del led apagado
int buttonState = 0;        // variable para almacenar el estado del pulsador

void setup() {
  // inicializa los pines como entradas y salidas
  pinMode(buttonPin, INPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  // lee el estado del pulsador y lo almacena en variable
  buttonState = digitalRead(buttonPin);

  // revisa si el pulsador esta presionado
  if (buttonState == HIGH) {
    // si el estado del led es bajo
    if (ledState == LOW) {
      ledState = HIGH;  // lo establece como alto
    }
    // en caso contario lo establece como bajo
    else {
      ledState = LOW;
    }

    while (buttonState == HIGH) {
      buttonState = digitalRead(buttonPin);
    }
  }
  // establece el estado del LED:
  digitalWrite(ledRPin, ledState);
  digitalWrite(ledGPin, ledState);
  digitalWrite(ledBPin, ledState);
}
