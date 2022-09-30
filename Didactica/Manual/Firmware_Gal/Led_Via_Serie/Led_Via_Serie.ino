/* Led_Via_Serie
  Acende /apaga uns LED mediante a consola serie
  1 acende, 2  apaga RGB_B
*/
#define RGB_G 5 // Pin do LED verde

char Rec_Ser;   // Variable de caracteres da recepción serie

void setup() {
  pinMode(RGB_G, OUTPUT);  // Pin LED como saída
  Serial.begin(115200);
  Serial.println("Escribe un '0' para apagar, '1' para acender" );  
  digitalWrite(RGB_G, LOW);
}

void loop() {
  if (Serial.available()) {   // Comproba que temos conexión establecida
    Rec_Ser = Serial.read();  // Pasa o dato recibido a variable Rec_Ser
    Serial.println(Rec_Ser);  // Reenvia o dato recibido
  
    if (Rec_Ser == '1') {  // Si o carácter recibido é '1' código ASCII 49
      digitalWrite(RGB_G, HIGH);  // Acende o LED
    }
    else if (Rec_Ser == '2') {  // Si o carácter recibido é '0' ASCII 50
      digitalWrite(RGB_G, LOW); // Apaga o LED
    }
  }
}
