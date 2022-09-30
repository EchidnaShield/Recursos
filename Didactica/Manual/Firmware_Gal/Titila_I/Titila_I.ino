/* Titila_I
 * Acende e apaga repetidamente un LED 
 * A modo de comprobación. 
*/
#define LED 12 // asignamos o LED o pin D12 (Led laranxa)

void setup() {
 pinMode(LED, OUTPUT); //Modo saída
}
void loop() {
 digitalWrite(LED, HIGH); // acende o LED HIGH = "1" = +5V
 delay(100); // espera 100 milisegundos
 digitalWrite(LED, LOW); // apaga o LED LOW = "0" = 0V
 delay(500); // espera 500 milisegundos
}