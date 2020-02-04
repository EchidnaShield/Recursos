/*
  Gamepad con EchidnaShield y Arduino Leonardo por Jorge Lobo @lobo_tic para www.echidna.es
  Modo Joystick y modo Acelerómetro. El modo acelerómetro está desactivado por defecto.

  Modo Joystick:      Modo Acelerómetro:
    - w: UP              - i: UP
    - s: DOWN            - k: DOWN
    - a: LEFT            - j: LEFT
    - d: RIGTH           - l: RIGTH

  D2: 2

  D3: 3

  Licencia CC BY SA
*/

#include <Keyboard.h>

void setup() {

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Keyboard.begin();
}

void loop() {

  //Control de joystick
  //Eje x (A0)
  if ((analogRead(A0)) > (700)) { // Cuando la lectura de la entrada analógica sea mayor del valor de umbral definido (mayor de 512 que mide el joystick en reposo)
    Keyboard.press('d');      // El teclado escribe la letra indicada y la deja presionada

  }
  if ((analogRead(A0)) < (700)) { // Cuando la lectura de la entrada analógica sea menordel valor de umbral definido (menor de 512 que mide el joystick en reposo)
    Keyboard.release('d');      // El teclado libera la presionada

  }
  if ((analogRead(A0)) < (300)) { // Cuando la lectura de la entrada analógica sea menor del valor de umbral definido (menor de 512 que mide el joystick en reposo)
    Keyboard.press('a');      // El teclado escribe la letra indicada y la deja presionada

  }
  if ((analogRead(A0)) > (300)) { // Cuando la lectura de la entrada analógica sea mayor del valor de umbral definido (mayor de 512 que mide el joystick en reposo)
    Keyboard.release('a');      // El teclado libera la presionada

  }
  //Eje y (A1)
  if ((analogRead(A1)) > (700)) { // Cuando la lectura de la entrada analógica sea mayor del valor de umbral definido (mayor de 512 que mide el joystick en reposo)
    Keyboard.press('w');      // El teclado escribe la letra indicada y la deja presionada

  }

  if ((analogRead(A1)) < (700)) { // Cuando la lectura de la entrada analógica sea menor del valor de umbral definido (menor de 512 que mide el joystick en reposo)
    Keyboard.release('w');      // El teclado libera la presionada

  }
  if ((analogRead(A1)) < (300)) { // Cuando la lectura de la entrada analógica sea menor del valor de umbral definido (menor de 512 que mide el joystick en reposo)
    Keyboard.press('s');      // El teclado escribe la letra indicada y la deja presionada

  }
  if ((analogRead(A1)) > (300)) { // Cuando la lectura de la entrada analógica sea mayor del valor de umbral definido (mayor de 512 que mide el joystick en reposo)
    Keyboard.release('s');      // El teclado libera la presionada

  }
  /*
    //Control de acelerómetro, descomentar para activar (eliminar la barra paréntesis de la línea 71 y el paréntesis barra de la linea 91 ¡¡Ojo, código incompleto!! hay que revisar.
      //Eje x (A0)
      if((analogRead(A2)) > (450)){ // Cuando la lectura de la entrada analógica sea mayor del valor de umbral definido
          Keyboard.press('l');      // El teclado escribe la letra indicada

      }
      if((analogRead(A2)) < (250)){ // Cuando la lectura de la entrada analógica sea menor del valor de umbral definido
          Keyboard.press ('j');      // El teclado escribe la letra indicada

      }
      //Eje y (A1)
      if((analogRead(A3)) > (450)){ // Cuando la lectura de la entrada analógica sea mayor del valor de umbral definido
          Keyboard.press('i');      // El teclado escribe la letra indicada

      }
      if((analogRead(A3)) < (250)){ // Cuando la lectura de la entrada analógica sea menor del valor de umbral definido
          Keyboard.press('k');      // El teclado escribe la letra indicada

      }
  */
  //Control de pulsadores
  if (((digitalRead(2)) == (HIGH))) { // Cuando la lectura de la entrada sea 1
    Keyboard.press('2');      // El teclado escribe la letra indicada
  }
  if (((digitalRead(2)) == (LOW))) { // Cuando la lectura de la entrada sea 1
    Keyboard.release('2');      // El teclado escribe la letra indicada
  }
  if (((digitalRead(3)) == (HIGH))) { // Cuando la lectura de la entrada sea 1
    Keyboard.press('3');      // El teclado escribe la letra indicada
  }
  if (((digitalRead(3)) == (LOW))) { // Cuando la lectura de la entrada sea 1
    Keyboard.release('3');      // El teclado escribe la letra indicada
  }

  _loop();
}



void _loop() {

}
