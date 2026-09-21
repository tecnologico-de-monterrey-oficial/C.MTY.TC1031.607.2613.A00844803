# Evidencia 1

César Cárdenas - A00844803

## Descripción

Este programa lee dos archivos de logs y ordena sus registros por fecha y hora. Después permite buscar registros dentro de un rango de fechas utilizando búsqueda binaria.

Los archivos utilizados son:

- `log607-1.txt`, que está desordenado.
- `log607-2.txt`, que está casi ordenado y tiene timestamps repetidos.

## Algoritmos

Los algoritmos que incluí son:

- Swap Sort
- Selection Sort
- Bubble Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Shell Sort

Shell Sort fue el algoritmo extra que agregué en la Actividad 1.5.

## Cómo compilar

Todos los archivos deben estar en la misma carpeta. Para compilar se usa:

```bash
g++ evidence.cpp -o evidence
```

Para ejecutar:

```bash
./evidence
```

El programa pide elegir un archivo y un algoritmo. Antes de ordenar también pide escribir una predicción sobre si será rápido o lento.

Después muestra el tiempo de ejecución y permite buscar registros entre dos fechas.

El formato de las fechas es:

```text
Sep 8 2024 00:22:43
```

## Archivos de salida

El programa crea estos archivos:

- `output607.txt`: contiene los registros ordenados.
- `range607.txt`: contiene los registros encontrados en el rango.
- `resultados607.txt`: guarda los tiempos y datos de las corridas.

## Búsqueda por rango

Para buscar el rango utilicé dos búsquedas binarias. Una encuentra el primer registro del rango y la otra encuentra la posición después del último.

Esto permite incluir correctamente los timestamps repetidos de `log607-2.txt`, sin perder registros ni escribirlos dos veces.

## Uso de IA

Utilicé inteligencia artificial para resolver dudas de sintaxis, revisar errores y adaptar los algoritmos que ya había hecho en la Actividad 1.5.

No todas las sugerencias fueron correctas. Al principio los meses se comparaban como texto y los días no tenían siempre la misma cantidad de caracteres. También se estaba leyendo el año como si fuera la hora.

Estos errores se detectaron al ejecutar el programa y revisar los resultados. Después se corrigió la clave de comparación y la lectura de cada registro.

## Video

En el siguiente enlace se encuentra el video donde muestro el funcionamiento del programa:
https://drive.google.com/file/d/19wADqhcEcCqBoc-eeHcIjM71K2xEA8ni/view?usp=sharing