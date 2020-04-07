/*
   Control del color del LED RGB
   Por puerto serie se introduce un valor entre 0 y 255 y el color
   Ejemplo: 125r200g20b

   Jose Pujol
   Abril de 2020
*/

// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

int incomingByte; // variable para leer los bytes de entrada
int value = 0;  // variable para almacenar el valor numerico
int pwmRValue = 0; // variable para enviar el codigo pwm Rojo al pin Rojo
int pwmGValue = 0; // variable para enviar el codigo pwm Verde al pin Verde
int pwmBValue = 0; // variable para enviar el codigo pwm Azul al pin Azul

void setup() {
  // inicializamos la comunicacion serie
  Serial.begin(9600);
}

void loop() {
  // comprueba si hay datos entrantes en el puerto serie
  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = Serial.read();
    // si es un caracter ASCII entre 0 y 9
    if (incomingByte >= '0' && incomingByte <= '9') {
      //Acumula los datos numericos multiplicando por 10 el valor acumulado
      value = (value * 10) + (incomingByte - '0'); // Resta 48 que es el valor decimal del 0 ASCII
    }
    else if (incomingByte == 'r') {
      pwmRValue = value;   // Guarda el valor en la variable pwmRValue
      Serial.print("Rojo= ");      // Imprimimo texto "Rojo"
      Serial.println(pwmRValue);     // Imprimo el valor del pwm rojo
      value = 0;  // Dejamos lista la variable para volver a escribir en ella
    }
    else if (incomingByte == 'g') {
      pwmGValue = value;   // Guarda el valor en la variable pwmGValue
      Serial.print("Verde= ");      // Imprimimo texto "Verde"
      Serial.println(pwmGValue);     // Imprimo el valor del pwm verde
      value = 0;  // Dejamos lista la variable para volver a escribir en ella
    }
    else if (incomingByte == 'b') {
      pwmBValue = value;   // Guarda el valor en la variable pwmBValue
      Serial.print("Azul= ");      // Imprimimo texto "Azul"
      Serial.println(pwmBValue);     // Imprimo el valor del pwm azul
      value = 0;  // Dejamos lista la variable para volver a escribir en ella
    }

  }
  analogWrite(ledRPin, pwmRValue);   // Escribimos el valor PWM Rojo en el pin Rojo LED RGB
  analogWrite(ledGPin, pwmGValue);   // Escribimos el valor PWM Verde en el pin Verde del LED RGB
  analogWrite(ledBPin, pwmBValue);   // Escribimos el valor PWM Azul en el pin Azul del LED RGB
}
