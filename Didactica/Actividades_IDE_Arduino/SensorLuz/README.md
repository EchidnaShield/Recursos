# Sensor Luz:

Códigos ejemplo usando la LDR, el sensor de luz situado en el pin analógico de entrada A5.

## 1. [Monitorización de sensores](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/SensorLuz/Monitorizacion_sensores/Monitorizacion_sensores.ino)
Programa para ver en el monitor serie los valores que da el sensor según las condiciones de luz
- LDR A5

## 2. [Linterna automática](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/SensorLuz/Linterna_automatica/Linterna_automatica.ino)
Linterna que se enciende de forma automática al hacerse de noche. Con poca luz enciende LED RGB color blanco
- A5 LDR
- D9, D5, D6 LED RGB

## 3. [Medidor de luz](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/SensorLuz/Medidor_Luz/Medidor_Luz.ino)
Dispositivo que muestra la cantidad de luz que recibe el sensor en los leds. Con baja intensidad luminosa solo se enciende un led, a medida que sube la cantidad de luz se van encendiendo mas leds, con mucha luz los leds parpadean
- LDR pin A5
- LED RGB Azul pin 6
- LED Rojo pin 13
- LED Naranja pin 12
- LED Verde pin 11
