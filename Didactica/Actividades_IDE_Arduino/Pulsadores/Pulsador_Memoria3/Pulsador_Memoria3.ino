/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;    // pin del pulsador
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

// Variables will change:
int ledState = HIGH;         // estado actual del LED
int buttonState;             // lectura actual del pulsador
int lastButtonState = LOW;   // lectura anterior del pulsador

// variables asociadas al tiempo
unsigned long lastDebounceTime = 0;  // Ultima vez que el pulsador fue pulsado
unsigned long debounceDelay = 50;    // tiempo para filtrar rebotes

void setup() {
  // establece los pines como entradas y salidas
  pinMode(buttonPin, INPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);

  // Escribe en el LED RGB el estado actual
  digitalWrite(ledRPin, ledState);
  digitalWrite(ledGPin, ledState);
  digitalWrite(ledBPin, ledState);
}

void loop() {
  // lee el estado del pulsador y lo alamcena
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // si el valor del pulsador ha cambiado por ruido o presion
  if (reading != lastButtonState) {
    // resetea el ultimo tiempo de rebote
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si el valor permanece mas de 50 ms
    
    // Si el valor ha cambiado:
    if (reading != buttonState) {
      buttonState = reading;

      // Si el valor del pulsador es alto cambia el valor del estado del led
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // escribe en el LED RGB:
  digitalWrite(ledRPin, ledState);
  digitalWrite(ledGPin, ledState);
  digitalWrite(ledBPin, ledState);

  // almacena el valor de la ultima lectura
  lastButtonState = reading;
}
