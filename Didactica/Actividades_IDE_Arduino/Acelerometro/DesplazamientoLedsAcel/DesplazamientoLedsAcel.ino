/*
  Desplazamiento LEDs Acelerómetro
  Programa que controla el desplazamiento de los leds en sentido y velocidad en
  funcion de la inclinacion del acelerometro

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

// variables que cambian
int contador = 1;
int sentido = 0;
int tiempo = 500;

void setup() {
  // establece los LEDs como salidas
  pinMode(ledGPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  //  Serial.begin(9600);        // abrimos el puerto serie y configuramos velocidad
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {

  yAcelValue = analogRead(yAcelPin);    // lee el valor del sensor
  if (yAcelValue < 340) {
    sentido = -1;
    tiempo = map(yAcelValue, 340, 250, 500, 10);
  }
  else if (yAcelValue < 360) {
    sentido = 0;
    tiempo = 500;
  }
  else {
    sentido = 1;
    tiempo = map(yAcelValue, 360, 450, 500, 10);
  }

  contar();

  encenderleds();

  delay(tiempo);

}

void contar() {
  if (sentido == 1) contador = contador + 1;
  if (sentido == -1) contador = contador - 1;
  if (contador > 4)contador = 1;
  if (contador < 1) contador = 4;
}

void encenderleds() {

  if (contador == 1) {
    digitalWrite(ledGPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledGPin, LOW); // establece 0v en el pin del LED verde
  }
  if (contador == 2) {
    digitalWrite(ledOPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledOPin, LOW); // establece 0v en el pin del LED verde
  }
  if (contador == 3) {
    digitalWrite(ledRPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledRPin, LOW); // establece 0v en el pin del LED verde
  }
  if (contador == 4) {
    digitalWrite(ledBPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledBPin, LOW); // establece 0v en el pin del LED verde
  }

}
