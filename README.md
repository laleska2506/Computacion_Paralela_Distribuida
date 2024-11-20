#
Sensores de Temperaturas

##
Contexto:
Imaginen que estamos trabajando en un sistema de monitoreo de sensores en una planta industrial. 

Cada sensor tiene varios valores registrados en un arreglo de enteros.

Cada nodo en un árbol binario de sensores representa una sub-estación de sensores, donde cada sub-estación tiene varios sensores, y cada sensor tiene registros de datos en un arreglo.

El objetivo es calcular el valor máximo de cada promedio de todos los valores registrados por los sensores de todas las sub-estaciones.

Este cálculo debe hacerse en paralelo para acelerar el análisis, ya que tenemos un gran número de sub-estaciones y sensores.

##
Problema:
Necesitamos recorrer todo el árbol binario de sensores, promediar los valores de los sensores en cada sub-estación y de manera recursiva ir obteniendo el máximo valor.

Usaremos OpenMP para paralelizar la tarea de recorrer el árbol, promediar los valores y obtener el promedio máximo.

El árbol tiene la forma de un árbol binario, donde cada nodo tiene un arreglo de enteros y apunta a dos hijos (sub-estaciones inferiores).

Además el árbol binario debe verificarse que sea thread safe.

