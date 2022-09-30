/* LED_PWM, Variar a intensidade dun led con modulación da anchura de pulso usando un bucle for.
*/
#define LED 11 // Led conectado o pin 11
void setup() {
 pinMode (LED, OUTPUT); // Definimos modo saída
}
void loop() {
 // Incrementamos O dende 0 ata 255 en pasos de 1
 for (int i = 0; i <= 255; i++)
 {
 analogWrite(LED, i); // Escribimos o valor i “PWM” na saída
 delay(10); // facemos unha pausa de 100mS entre incremento
 }
}
