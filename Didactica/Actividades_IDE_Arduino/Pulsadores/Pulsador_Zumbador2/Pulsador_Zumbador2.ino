/*
  Pulsador Zumbador
  Sistema para controlar un zumbador con un pulsador
  con dos leds testigos que indican el estado del zumbador

  Hardware:
  Pulsador pin 2
  Zumbador pin 10
  LED rojo 13
  LED Verde 11

  Jose Pujol
  Septiembre 2017
*/

// constantes que no cambian se usan para establecer los pines
const int buttonPin = 2;     // el numero del pin del pulsador
const int buzzerPin =  10;   // el numero de pin del zumbador
const int ledRPin = 13;
const int ledVPin = 11;

// variables que cambian
int buttonState = 0;       // variable para almacenar el estado del pulsador

void setup() {
  // inicializa el pulsador como entrada
  pinMode(buttonPin, INPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledVPin, OUTPUT);

}

void loop() {

  // lee el estado del pulsador y lo almacena en la variable
  buttonState = digitalRead(buttonPin);

  // revisa si el pulsador esta presionado
  if (buttonState == HIGH) {
    analogWrite(buzzerPin, 125);      // activa el zumbador
    digitalWrite(ledVPin, HIGH);      // enciende led Verde
    digitalWrite(ledRPin, LOW);       //  apaga led Rojo

  }
  // si no esta presionado
  else {
    analogWrite(buzzerPin, 0);     // apaga el zumbador
    digitalWrite(ledVPin, LOW);     //  apaga led Verde
    digitalWrite(ledRPin, HIGH);    // enciende led Rojo
  }
}
