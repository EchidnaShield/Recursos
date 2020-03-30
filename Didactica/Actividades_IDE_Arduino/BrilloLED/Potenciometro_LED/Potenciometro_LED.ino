/*
 Control de la lumninosidad de un LED con un potenciómetro
 
 LED pin 9
 Potenciometro pin A0
 Valores JoyX 0  353  702
 
 Noviembre 2017
 Jose Pujol
 */
 
// Variables globales
// Variables constantes para los pines
const int joyXPin = A0; // selecciona el pin de entrada para el potenciómetro
const int ledPin = 11;  // selecciona pin 9 para el LED 

// variables que almacenan los datos
int joyXValue = 0; // variable para almacenar los valores del potenciómetro 0-1023
int bright = 0; // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  // nada que declarar en el setup
//  Serial.begin(9600);
}

void loop() {
  // lee el valor del sensor 0-1023
  joyXValue = analogRead(joyXPin);
  // mapea el valor a escala 0-255
  if (joyXValue> 355){
    bright = map(joyXValue, 355, 702, 0, 255);
  }
  else if (joyXValue<350){
    bright = map(joyXValue, 350, 0, 0, 255);
  }
  else{
  bright=0;
  }
  
  // escribimos el valor en analogico en el LED
  analogWrite(ledPin, bright);
//  Serial.println(joyXValue);
//  delay(500);
}
