# Control  Puerto serie

Ejemplos para controlar Echidna desde el puerto serie. Nos permiten controlar la placa desde el teclado del ordenador. Estos códigos son también válidos para comunicarnos por bluetooth con lo que podríamos realizar aplicaciones con para controlar Echidna desde App Inventor.

IMAGEN PUERTO SERIE

## [1.Control de LED RGB luz blanca](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/ControlPuertoSerie/PhysicalPixel/PhysicalPixel.ino)
Basado en el ejemplo Physical Pixel permite encender y apagar el LED RGB con luz blanca, mandando desde el puerto serie una H para encender y una L para apagar

## [2.Control brillo LED RGB luz blanca](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/ControlPuertoSerie/ControlLedPWM/ControlLedPWM.ino)
En este caso el programa permite controlar la intensidad luminosa del LED RGB blanco enviando un valor entre 0 y 255 y un terminador >. Ejemplo 125>

## [3.Control colores de led RGB](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/ControlPuertoSerie/ControlLedRGBPWM/ControlLedRGBPWM.ino)
El programa nos permite controlar el color del LED RGB, enviando el valor entre 0 y 255 y el código del color al final, r, g, o b. Ejemplo: 100r 200g 10b
