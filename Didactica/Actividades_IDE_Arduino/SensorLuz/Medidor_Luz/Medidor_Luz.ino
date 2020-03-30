/*
   Medidor de Luz
   Con baja intensidad luminosa solo se enciende un led
   A medida que sube la cantidad de luz se van encendiendo mas leds
   Con mucha luz los leds parpadean

   LDR pin A5
   LED Verde pin 11
   LED Naranja pin 12
   LED Rojo pin 13
   LED RGB Azul pin 6

   Noviembre 207
   Jose Pujol
*/

// variables constantes para los pines
const int ldrPin = A5;    // establece el pin de la LDR
// pines del LED RGB
const int ledGPin = 11; // establece el pin del LED verde
const int ledOPin = 12; // establece el pin del LED naranja
const int ledRPin = 13; // establece el pin del LED rojo
const int ledBPin = 6; // establece el pin del LED azul


// variables que pueden cambiar
int ldrValue = 0; // variable para almacenar el valor de la LDR
int ldrlevel = 200; // nivel de cambio del valor de la LDR

void setup() {
  // establece los LEDs como salidas
  pinMode(ledGPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);
  // Enciende un número de leds en función de la intensidad
  // luminosa
  if (ldrValue < ldrlevel) {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (ldrValue < 400) {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, HIGH);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (ldrValue < 600) {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, HIGH);
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledBPin, LOW);
  }
  else if (ldrValue < 800) {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, HIGH);
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledBPin, HIGH);
  }
  else {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, HIGH);
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledBPin, HIGH);
    delay(200);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
    delay(200);
  }
}
