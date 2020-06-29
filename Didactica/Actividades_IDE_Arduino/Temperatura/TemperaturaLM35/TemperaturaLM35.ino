/*
 Medida de temperatura con sensor LM35
 Mostramos la temperatura por el monitor serie
 Usamos analogReference para aumentar la precision del sensor

 Descripción

 Sensor LM35 
 pin V del sensor conectado a 5V de Arduino
 pin central del sensor Vout a A0 de Arduino
 pin GND a GND de Arduino
 
 */

// constantes que no cambian
// se usan para establecer los pines
const int LM35Pin = A6;     // Pin al que conectamos sensor temperatura

// variables globales que cambian
float temperatura = 0;         // variable para almacenar la temperatura medida

// Configuración
void setup() {
  
  analogReference(INTERNAL); // cambiamos la referencia analogica a 1.1v
  Serial.begin(9600); // Configuramos la conexion con el PC

}

// Bucle que se repite
void loop() {
  int lectura = analogRead(LM35Pin); // Valor entre 0 y 1023
  temperatura = (lectura* 1.1 * 100.0)/1024.0; // Temperatura en º Celsius

  Serial.print("Temperatura:");  
  Serial.print(temperatura);  // Mostramos el valor de la temperatura 
  Serial.println("C");
  delay(1000);
}
