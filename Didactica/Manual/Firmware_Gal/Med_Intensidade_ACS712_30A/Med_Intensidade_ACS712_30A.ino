/*Med_Intensidade_ACS712_30A
 * Medida da intensidade usando ACS712-30A
 */

float Sensibilidade = 0.066; //sensibilidade en Volts/Amperes para sensor de 30A
float VSensor;    // Variable para a tensión do sensor
float I;          // Variable para o o calculo da Intensidade
float MediaI;      // Calculo da media das medidas 
int n = 500;     // Nº de mostras para a media

void setup() {
  Serial.begin(9600);
}

void loop() {

  media();
  Serial.print("Tensión: ");
  Serial.print(VSensor, 3);
  Serial.print("V  Corrente: ");
  Serial.print(MediaI, 2);
  Serial.println(" A");
}

void media() {
  for (int i = 0; i < n; i++) { //Bucle de n medidas
    VSensor = analogRead(A4) * (4.996 / 1023.0); //lectura da tensión do sensor
    I = (VSensor - 2.5) / Sensibilidade; //Ecuación para obtener la corriente
    MediaI = MediaI + I; //acumula as medidas
    delay(1);
  }
  MediaI = (MediaI / n); // Fai a media das n medidas
}
