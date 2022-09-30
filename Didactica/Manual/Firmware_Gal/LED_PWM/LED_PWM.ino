/* LED_PWM
  Acender e apagar un led con unha 
  intensidade dada. 
*/
#define LED 11  // Led conectado o pin 11

void setup() {
  pinMode(LED, OUTPUT);  // Definimos modo saída
}

void loop() {
  analogWrite(LED, 16);  // Acendemos o led o 6%
  delay(100);
  analogWrite(LED, 30);  // Acendemos o led o 12%
  delay(100);
  analogWrite(LED, 64);  // Acendemos o led o 25%
  delay(100);
  analogWrite(LED, 128);  // Acendemos o led o 50%
  delay(100);
  analogWrite(LED, 256);  // Acendemos o led o 100%
  delay(100);
}