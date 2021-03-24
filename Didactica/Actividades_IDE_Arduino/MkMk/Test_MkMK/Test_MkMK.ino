/* Lectura Makey Makey
  Programa para leer las entradas MkMk
*/
int entrada[] = {A0, A1, A2, A3, A4, A5, 2, 3} ; //Entradas
int V_MkMk[8];
int n = 5;
int i = 0;

void setup() {
  for (i = 0; i < 8; i++)
  {
    //Las entradas se definen por defecto, pero es una buena costumbre definir antes todo.
    
    pinMode(entrada[i], INPUT); // define como entradas los pines MkMk
  }
  Serial.begin(9600);

}

void loop() {
  for (i = 0; i < 6; i++) {
    V_MkMk[i] = analogRead(entrada[i]);
    }
    V_MkMk[6] = digitalRead(entrada[6]);
    V_MkMk[7] = digitalRead(entrada[7]);
    
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
