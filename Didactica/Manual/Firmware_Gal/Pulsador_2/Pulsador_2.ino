/*
   Pulsador_II
   Acender un led cando se prema o pulsador
   apagalo en caso contrario
   xrosas_22
*/

#define SR 2   // Pin do pulsador 
#define LED 11 // pin do led

void setup() {
  pinMode(LED, OUTPUT);  //modo pin como saida
  pinMode(SR, INPUT);//modo pin como saida
}

void loop() {
  //si o pulsador é "1" acende o led
  if (digitalRead (SR) == HIGH) {
    digitalWrite(LED, HIGH);
  } 
  // en caso contrario apaga o led
  else {
    digitalWrite(LED, LOW);
  }
}
