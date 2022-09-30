/* Pulsador_1 
 Acender un led cando se prema o pulsador 
 sen variables
*/
#define SR 2 // Pin do pulsador 
#define LED 11 // pin do led
void setup() {
 pinMode(LED, OUTPUT); //modo saída
 pinMode(SR, INPUT);   //modo entrada
}
void loop() {
 if (digitalRead (SR) == HIGH) { //comproba si SR é igual a "1"
 digitalWrite(LED, HIGH); //acende o LED
 }
 if (digitalRead (SR) == LOW) { //comproba si SR é igual a "0"
 digitalWrite(LED, LOW); //apaga o LED
 }
}
