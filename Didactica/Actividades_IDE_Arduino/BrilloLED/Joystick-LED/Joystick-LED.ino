/*
  Control de la lumninosidad de un LED RGB blanco con Joystick X

  LED R pin 9
  LED G pin 5
  LED B pin 6
  Joystick X pin A0
  Valores JoyX 0  353  702

  Marzo 2020
  Jose Pujol
*/

// Variables globales
// Variables constantes para los pines
const int joyXPin = A0; // selecciona el pin de entrada para el potenciómetro
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

// variables que almacenan los datos
int joyXValue = 0; // variable para almacenar los valores del potenciómetro 0-1023
int bright = 0; // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  // nada que declarar en el setup
  // Serial.begin(9600);
}

void loop() {
  // lee el valor del joystick 0-702
  joyXValue = analogRead(joyXPin);
  // mapea el valor a escala 0-255
  if (joyXValue > 370) {
    bright = map(joyXValue, 370, 702, 0, 255);
  }
  else if (joyXValue < 330) {
    bright = map(joyXValue, 330, 0, 0, 255);
  }
  else {
    bright = 0;
  }

  // escribimos el valor en analogico en el LED
  analogWrite(ledRPin, bright);
  analogWrite(ledGPin, bright);
  analogWrite(ledBPin, bright);
  //  Serial.println(joyXValue);
  //  delay(500);
}
