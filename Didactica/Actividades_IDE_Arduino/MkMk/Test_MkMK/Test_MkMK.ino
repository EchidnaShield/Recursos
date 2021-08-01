/* Lectura Makey Makey
  Programa para leer las entradas MkMk
*/

int entrada[] = {A0, A1, A2, A3, A4, A5, 2, 3} ; //Entradas

//char *texto[] = {"A0", "A1", "A2", "A3", "A4", "A5", "D2", "D3"} ; // texto a representar para cada entrada
char *texto[] = {"Mk1", "Mk2", "Mk3", "Mk4", "Mk5", "Mk6", "Mk7", "Mk8"} ; // texto a representar para cada entrada
int V_MkMk[8];
int n = 5;
int i = 0;
#define Buzz 10

void setup() {
  for (int i = 0; i < 8; i++)
  {
    //Las entradas se definen por defecto, pero es una buena costumbre definir antes todo.

    pinMode(entrada[i], INPUT); // define como entradas los pines MkMk
    pinMode (Buzz, OUTPUT);
  }

  Serial.begin(9600); // iniciamos la comunicación serie a 9600bits por segundo

}

void loop() {
  
// Lectura de las entrada0 a entrada7, depositando su valor en V_MkMk0 a V_MkMk7
  for (i = 0; i < 8 ; i++) {
    V_MkMk[i] = digitalRead(entrada[i]);

   digitalWrite (Buzz,V_MkMk[i]);
   delay(10);
   }

// Enviamos (serie) el "texto" de las entradas, solo cada cinco lecturas.
  if (n == 5) {
    n = 0;                        //Borramos el contador de lecturas
    Serial.println();             //Una línea de separación cada cinco lecturas
    
    for (i = 0; i < 8; i++) {
      Serial.print(texto[i]);
      Serial.print("\t");
    }
     Serial.println();
  }
  // Enviamos serie el valor de las entradas
  for (i = 0; i < 8; i++) {
    Serial.print (V_MkMk[i]);
    Serial.print("\t");
  }
  Serial.println();   
  n++;                  //Incrementamos el contador de lecturas
  delay(1);
}
