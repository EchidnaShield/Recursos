/*
  Nivel eje y
  Cuando eje y está horizontal leds apagados
  Si inclinamos se encienden los leds adyacentes al centro
  Si inclinamos maś se encienden los leds de los extremos

  Acelerometro en reposo=350
  
  A3 Acel y
  D6 RGB Azul
  D13 LED rojo
  D12 LED naranha
  D11 LED verde
  
  Abril 2010
  JosePujol
*/

// constantes que no varian
const int yAcelPin = A3;    // pin donde conectamos el sensor analogico
const int ledGPin = 11; // establece el pin del LED verde
const int ledOPin = 12; // establece el pin del LED naranja
const int ledRPin = 13; // establece el pin del LED rojo
const int ledBPin = 6; // establece el pin del LED azul

int yAcelValue = 0;  // variable para alamacenar los valores del sensor
//int yAcelMedValue = 0; // vble para almacenar los valores medios y eliminar valores fluctuantes

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
  //yAcelMedValue = yAcelMedValue * 0.7 + yAcelValue * 0.3;
  Serial.println(yAcelValue);       // Imprime el valor del sensor
  // Serial.print("   ");       // Imprime el valor del sensor
  // Serial.println(yAcelMedValue);       // Imprime el valor del sensor
  // delay(500);                    // Espera 0.1 segundo
  if (yAcelValue < 310) {
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
  else if (yAcelValue < 390) {
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
