/*
  CocheFantastico
  Mediante la creación de un contador que aumenta de 1 a 4 y decrece
  de 4 a 1 se controla el encendido de los leds

  Jose Pujol
  Marzo 2020
*/

// Declaracion de variables de tipo constante entero
const int ledRPin = 13; // LED rojo asociado al pin 12
const int ledOPin = 12; // LED naranja asociado al pin 12
const int ledVPin = 11; // LED verde asociado al pin 11
const int ledBPin = 6; // LED azul asociado al pin 6

// variables que cambian
int contador = 1;
int sentido = 0;

// la funcion set up se ejecuta una sola vez
void setup() {
  // inicializa los pines como una salida digital
  pinMode(ledRPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledVPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);

  Serial.begin(9600);
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {

  if (sentido == 0) contador = contador + 1;
  if (sentido == 1) contador = contador - 1;
  if (contador > 3)
    sentido = 1;
  if (contador < 2)
    sentido = 0;


  if (contador == 1) {
    digitalWrite(ledVPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
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

  Serial.println(contador);
  delay(200);

}
