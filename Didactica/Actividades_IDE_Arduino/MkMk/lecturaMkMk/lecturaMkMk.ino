/* Lectura Makey Makey
  Programa para leer las entradads MkMk
*/

int n=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
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
