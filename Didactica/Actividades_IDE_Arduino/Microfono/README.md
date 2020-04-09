# Micrófono
Programas usando el micrófono. Validos para Echidna White y Echidna Black
- Echidna White A8
- Echidna Black A7

## [1.Smoothing](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Microfono/SmoothingMicrophone/SmoothingMicrophone.ino)
Programa para filtrar la señal proveniente del micrófono y representarla por el Serial plotter. Está basado en el programa Smoothing https://www.arduino.cc/en/tutorial/smoothing que realiza un filtrado de los datos y elimina los valores picos . En el programa se usa una pila de datos FIFO “first in first out”, que almacena los últimos 10 valores captados por el micrófono y realiza la media eliminando así los valores extremos. Se ha representado por serial plotter los valores instantáneos y el valor medio para comprobar el funcionamiento del filtro.

IMAGEN SERIAL PLOTTER


Otros programas para añadir:
- Semáforo de ruido
- Encendido de LED por palmada
