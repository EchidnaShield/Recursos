/*
  Semaforo:
  Estado verde 6s
  Estado amarillo 2s
  Estado rojo 4s

  Jose Pujol
  Octubre 2017
*/

// Declaracion de variables de tipo constante entero
const int ledRPin = 13; // LED rojo asociado al pin 12
const int ledOPin = 12; // LED naranja asociado al pin 12
const int ledVPin = 11; // LED verde asociado al pin 11

// la funcion set up se ejecuta una sola vez
void setup() {
  // inicializa los pines como una salida digital
  pinMode(ledRPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledVPin, OUTPUT);
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {
  // ESTADO SEMAFORO VERDE
  digitalWrite(ledRPin, LOW); // establece 0v en el pin del LED rojo
  digitalWrite(ledOPin, LOW); // establece 0v en el pin del LED amarillo
  digitalWrite(ledVPin, HIGH); // establece 5v en el pin del LED verde
  delay(6000);    // espera seis segundos

  // ESTADO SEMAFORO AMARILLO
  digitalWrite(ledRPin, LOW);  // establece 0v en el pin del LED rojo
  digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
  digitalWrite(ledOPin, HIGH); // establece 5v en el pin del LED amarillo
  delay(2000);                 // espera 2 segundos

  // ESTADO SEMAFORO ROJO
  digitalWrite(ledRPin, HIGH); // establece 5v en el pin del LED rojo
  digitalWrite(ledOPin, LOW); // establece 0v en el pin del LED amarillo
  digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
  delay(4000);    // espera cuatro segundos
}
