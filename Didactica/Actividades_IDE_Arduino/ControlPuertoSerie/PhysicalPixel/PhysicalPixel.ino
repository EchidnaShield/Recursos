/*
  Modificación del programa Physical Pixel
  Se ha añadido el control de los 3 pines del LED RGB
  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.

  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.

  The circuit:
  - LED connected from digital pin 13 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/PhysicalPixel
*/

// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul
int incomingByte;      // variable para leer los bytes de entrada

void setup() {
  // inicializamos la comunicacion serie
  Serial.begin(9600);
  // establece los pines del LED RGB como salidas
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  // comprobamos si hay datos de entrada
  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = Serial.read();
    // si el byte es H (ASCII 72) enciende el LED
    if (incomingByte == 'H') {
      digitalWrite(ledRPin, HIGH);
      digitalWrite(ledGPin, HIGH);
      digitalWrite(ledBPin, HIGH);
    }
    // si el byte es L (ASCII 76) apaga el LED
    if (incomingByte == 'L') {
      digitalWrite(ledRPin, LOW);
      digitalWrite(ledGPin, LOW);
      digitalWrite(ledBPin, LOW);
    }
  }
}
