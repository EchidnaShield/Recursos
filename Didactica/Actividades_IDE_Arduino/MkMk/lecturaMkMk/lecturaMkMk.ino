/* Lectura Makey Makey
  Programa para leer las entradas MkMk
*/
int entradas[] = {A0, A1, A2, A3, A4, A5, 2, 3} ; // Entradas

int n=5;

void setup() {
for (int i = 0; i < 8; i++)
  {
   // define como entradas los pines MkMk
    pinMode(entradas[i], INPUT);
  }
// si, que las analog inputs se defin cuando la leemos, pero es una buena costumbre definir antes todo.

 // pinMode(2, INPUT);
 // pinMode(3, INPUT);
  Serial.begin(9600);

}

void loop() {

  int a0Value = analogRead(A0);
  int a1Value = analogRead(A1);
  int a2Value = analogRead(A2);
  int a3Value = analogRead(A3);
  int a4Value = analogRead(A4);
  int a5Value = analogRead(A5);
  int d2Value = digitalRead(2);
  int d3Value = digitalRead(3);
  if (n == 5) {
    n = 0;
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
  Serial.print(a0Value);
  Serial.print("\t");
  Serial.print(a1Value);
  Serial.print("\t");
  Serial.print(a2Value);
  Serial.print("\t");
  Serial.print(a3Value);
  Serial.print("\t");
  Serial.print(a4Value);
  Serial.print("\t");
  Serial.print(a5Value);
  Serial.print("\t");;
  Serial.print(d2Value);
  Serial.print("\t");
  Serial.println(d3Value);
  n++;
  delay(1000);

}


