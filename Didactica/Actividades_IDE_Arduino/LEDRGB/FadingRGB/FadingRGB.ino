/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fading
*/

// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

void setup() {
  // nothing happens in setup
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeRValue = 0 ; fadeRValue <= 255; fadeRValue += 5) {
    // sets the value (range from 0 to 255):
    for (int fadeGValue = 0 ; fadeGValue <= 255; fadeGValue += 5) {
      for (int fadeBValue = 0 ; fadeBValue <= 255; fadeBValue += 5) {
        analogWrite(ledRPin, fadeRValue);
        analogWrite(ledGPin, fadeGValue);
        analogWrite(ledBPin, fadeBValue);
        // wait for 10 milliseconds to see the dimming effect
        Serial.print(fadeRValue);
        Serial.print("   ");
        Serial.print(fadeGValue);
        Serial.print("   ");
        Serial.println(fadeBValue);
        delay(10);
      }

    }
  }

  /*
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(ledPin, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }
  */
}
