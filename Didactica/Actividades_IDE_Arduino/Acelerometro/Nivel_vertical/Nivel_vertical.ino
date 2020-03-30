/*
  Nivel vertical
  En horizontal leds apagados
  Si inclinamos se encienden los leds
  Noviembre 2017
  JosePujol
*/

// constantes que no varian
const int yAcelPin = A3;    // pin donde conectamos el sensor analogico
const int ledGPin = 11; // establece el pin del LED verde
const int ledOPin = 12; // establece el pin del LED naranja
const int ledRPin = 13; // establece el pin del LED rojo
const int ledBPin = 6; // establece el pin del LED azul

int yAcelValue = 0;  // variable para alamacenar los valores del sensor

void setup() {
  // establece los LEDs como salidas
  pinMode(ledGPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  Serial.begin(9600);        // abrimos el puerto serie y configuramos velocidad
}

void loop() {
  yAcelValue = analogRead(yAcelPin);    // lee el valor del sensor
//  Serial.println(yAcelValue);       // Imprime el valor del sensor
//  delay(1000);                    // Espera 0.1 segundo
  if (yAcelValue < 300) {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (yAcelValue < 340) {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, HIGH);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (yAcelValue < 360) {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (yAcelValue < 400) {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledBPin, LOW);
  }
  else {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, HIGH);
  }
}
