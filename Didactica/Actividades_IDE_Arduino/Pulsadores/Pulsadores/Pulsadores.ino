/*
  Programa para controlar con 2 pulsadores LEd RGB blanco y Zumbador
  - Pulsador L con Memoria controla LED RGB blanco
  - Pulsador R para controlar un zumbador
  con dos leds testigos que indican el estado del zumbador

  Pulsador Memoria Left pin 3
  LED RGB pines 9, 5, 6

  Pulsador Right pin 2
  Zumbador pin 10
  LED rojo 13
  LED Verde 11

  Marzo de 2020
  Jose Pujol
*/
// constantes que no cambian se usan para establecer los pines
const int buttonLPin = 3;     // el numero del pin del pulsador
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

const int buttonRPin = 2;     // el numero del pin del pulsador
const int buzzerPin =  10;   // el numero de pin del zumbador
const int ledRoPin = 13;      // numero pin LED Rojo
const int ledVPin = 11;     // numero pin LED Verde

// variables que cambian
int ledState = LOW;         // Estado actual del led apagado
int buttonLState = 0;        // variable para almacenar el estado del pulsador Left
int buttonRState = 0;       // variable para almacenar el estado del pulsador Right

void setup() {
  // inicializa los pulsadores como entradas
  pinMode(buttonRPin, INPUT);
  pinMode(buttonLPin, INPUT);
  // inicializa los leds como salidas
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(ledVPin, OUTPUT);
  pinMode(ledRoPin, OUTPUT);
}

void loop() {
  // lee el estado de los pulsadores y lo almacena en su variable
  buttonLState = digitalRead(buttonLPin);
  buttonRState = digitalRead(buttonRPin);

  // LED RGB
  // revisa si el pulsador esta presionado
  if (buttonLState == HIGH) {
    // si el estado del led es bajo
    if (ledState == LOW) {
      ledState = HIGH;  // lo establece como alto
    }
    // en caso contario lo establece como bajo
    else {
      ledState = LOW;
    }

    while (buttonLState == HIGH) {
      buttonLState = digitalRead(buttonLPin);
    }
  }
  // establece el estado del LED:
  digitalWrite(ledRPin, ledState);
  digitalWrite(ledGPin, ledState);
  digitalWrite(ledBPin, ledState);

  // ZUMBADOR Y LEDS TESTIGOS
  // revisa si el pulsador esta presionado
  if (buttonRState == HIGH) {
    analogWrite(buzzerPin, 125);      // activa el zumbador
    digitalWrite(ledVPin, HIGH);      // enciende led Verde
    digitalWrite(ledRoPin, LOW);       //  apaga led Rojo

  }
  // si no esta presionado
  else {
    analogWrite(buzzerPin, 0);     // apaga el zumbador
    digitalWrite(ledVPin, LOW);     //  apaga led Verde
    digitalWrite(ledRoPin, HIGH);    // enciende led Rojo
  }
}
