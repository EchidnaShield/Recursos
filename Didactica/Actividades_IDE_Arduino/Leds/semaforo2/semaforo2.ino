/*
  Semaforo: 
  Estado verde 6s
  Estado naranja 2s- con 5 parpadeos de 0,4s y zumbador
  Estado rojo 4s
  
  
  Jose Pujol
  Octubre 2017
*/

// Declaracion de variables de tipo constante entero
const int ledRPin = 13; // LED rojo asociado al pin 13
const int ledOPin = 12; // LED naranja asociado al pin 12
const int ledVPin = 11; // LED verde asociado al pin 11

const int zumbPin = 10; // zumbador asociado al pin 10

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
  analogWrite(zumbPin, 0); // establece 0v en el pin del zumbador
  delay(6000);    // espera seis segundos

  // ESTADO SEMAFORO AMARILLO
  digitalWrite(ledRPin, LOW);  // establece 0v en el pin del LED rojo
  digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
  // bucle de repetición
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledOPin, HIGH); // establece 5v en el pin del LED amarillo
    analogWrite(zumbPin, 125); // establece 5v en el pin del zumbador
    delay(200);                 // espera 0,2 segundos
    digitalWrite(ledOPin, LOW); // establece 0v en el pin del LED amarillo
    analogWrite(zumbPin, 0); // establece 0v en el pin del zumbador
    delay(200);                 // espera 0,2 segundos
  }

  // ESTADO SEMAFORO ROJO
  digitalWrite(ledRPin, HIGH); // establece 5v en el pin del LED rojo
  digitalWrite(ledOPin, LOW); // establece 0v en el pin del LED amarillo
  digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
  analogWrite(zumbPin, 0); // establece 0v en el pin del zumbador
  delay(4000);    // espera cuatro segundos
}
