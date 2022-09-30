
/* Cores_RGB
 cores o chou
*/
#define RGB_R 9 //Led RGB vermello
#define RGB_G 5 //Led RGB verde
#define RGB_B 6 //Led RGB azul

void setup() {
 pinMode (RGB_R, OUTPUT); // Definimos como saída
 pinMode (RGB_G, OUTPUT); // "
 pinMode (RGB_B, OUTPUT); // "
}
void loop() {
 analogWrite(RGB_R, random(255)); // PWM aleatorio vermella
 analogWrite(RGB_G, random(255)); // “ verde
 analogWrite(RGB_B, random(255)); // “ azul
 delay(500);
}