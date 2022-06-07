# EstructurasLinealesDinamicas
Implementa una cola doblemente terminada utilizando arreglos dinámicos y listas doblemente enlazadas circulares, además de una ejecución del problema de flavio josefo.

*En cumplimiento de la materia Estructuras de datos. Semestre 2022-1*


Este proyecto se compila con el uso del Makefile adjunto.

En la función main se encuentran 3 llamadas a funciones de tipo test, que ejecutan las operaciones
requeridas para cada una de los 3 ejercicios que se solicitaron.

El problema de flavio josefo lee una lista de estudiantes (definida como FILENAME), cada uno con una posición asignada dentro del supuesto círculo. Dentro de la función flavio_josefo se ordena alfabéticamente esta lista y procede a ejecutar el "suicidio masivo" en el que se elimina a un estudiante cada K pasos.

Para el problema de flavio josefo se puede cambiar la cantidad de pasos para que ocurra un suicidio desde main.c (se modifica la constante K).
