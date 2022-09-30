/* Dim_Led_Via_Serie
  Axusta luminosidade LED mediante a consola serie
  0 = apagado, 255 = máximo
*/
#define RGB_G 5 // Pin do LED verde
int Rec_Ser;    // Variable de caracteres da recepción serie

void setup() {
  pinMode(RGB_G, OUTPUT);  // Pin LED como saída
  Serial.begin(115200);
  Serial.println("Escribe un número entre 0 e 100" );
  digitalWrite(RGB_G, LOW);
}

void loop() {
  if (Serial.available()) {   // Comproba que temos conexión establecida
    Rec_Ser = Serial.parseInt();  // Pasa o dato recibido a variable Rec_Ser
    Serial.println(Rec_Ser);  // Reenvia o dato recibido
    Rec_Ser = map (Rec_Ser, 0, 100, 0, 255);
    analogWrite (RGB_G, Rec_Ser);

  }
}
