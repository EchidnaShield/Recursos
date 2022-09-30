/*LDR_crepuscular
 Lectura analóxica da LDR
 Interruptor crepuscular
*/
#define LDR A5 //LDR conectada a A5 
#define L_Orn 12 //Led laranxa a D12
int limiar = 600; //valor activación

void setup() {
 pinMode (LDR, INPUT); // Definimos como entrada
 pinMode (L_Orn, OUTPUT); // Definimos modo saída
}
void loop() {
 // Leemos aa entrada
 int Valor_LDR = analogRead(LDR);
 // comproba si o valor está por baixo
 if ( Valor_LDR < limiar) {
 digitalWrite (L_Orn, HIGH); // Acende o LED
 }
 else {
 digitalWrite (L_Orn, LOW); // Apaga o LED
 }
 // un pequeno retardo para estabilizar as medidas.
 delay(1);
}
