/* Lectura Makey Makey
  Programa para leer las entradas MkMk
*/
int entrada[] = {A0, A1, A2, A3, A4, A5, 2, 3} ; //Entradas
int V_MkMk[8];
int n = 5;

void setup() {
  for (int i = 0; i < 8; i++)
  {
    //Las entradas se definen por defecto, pero es una buena costumbre definir antes todo.
    
    pinMode(entrada[i], INPUT); // define como entradas los pines MkMk
  }
  Serial.begin(9600);
  Serial.println("Desliza el selector a MKMK :-)");
}

void loop() {
  for (int i = 0; i < 6; i++) {
    V_MkMk[i] = analogRead(entrada[i]);
    V_MkMk[i + 1] = digitalRead(entrada[i + 1]);
    V_MkMk[i + 2] = digitalRead(entrada[i + 2]);
  }
  if (n == 5) {
    n = 0;
    Serial.println();   //Linea de separacion
    Serial.print("A0");
    Serial.print("\t");
    Serial.print("A1");
    Serial.print("\t");
    Serial.print("A2");
    Serial.print("\t");
    Serial.print("A3");
    Serial.print("\t");
    Serial.print("A4");
    Serial.print("\t");
    Serial.print("A5");;
    Serial.print("\t");;
    Serial.print("D2");
    Serial.print("\t");
    Serial.println("D3");
  }
  for (int i = 0; i < 8; i++) {
    Serial.print (V_MkMk[i]);
    Serial.print("\t");
  }
  Serial.println("");
  n++;
  delay(1000);

}
