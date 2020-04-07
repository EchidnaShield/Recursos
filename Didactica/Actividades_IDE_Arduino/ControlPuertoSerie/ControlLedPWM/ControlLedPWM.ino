/*
 * Control de la intensidad luminosa de un LED RGB con color Blanco
 * Por puerto serie se introduce un valor entre 0 y 255 y el terminador >
 * Ejemplo:200>
 * En los tres pines del LED RGB se pone la misma intensidad luminosa
 * de forma que se realiza el color blanco
 * 
 * Jose Pujol
 * Abril de 2020
 */

// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul

int incomingByte; // variable para leer los bytes de entrada
int value = 0;  // variable para almacenar el valor numerico
int pwmValue = 0; // variable para enviar el codigo pwm al led

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
    else if (incomingByte == '>') // uso > como finalizador
    {
      pwmValue = value;   // Guarda el valor en la variable pwmValue
      Serial.println(pwmValue);     // Lo imprime por monitor serie
      value = 0;  // Dejamos lista la variable para volver a escribir en ella
    }
  }
  analogWrite(ledRPin, pwmValue);   // Escribimos el valor PWM en el LED Rojo
  analogWrite(ledGPin, pwmValue);   // Escribimos el valor PWM en el LED Verde
  analogWrite(ledBPin, pwmValue);   // Escribimos el valor PWM en el LED Azul
}
