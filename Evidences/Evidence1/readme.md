```text
Sep 8 2024 00:22:43 10.14.168.155 Unencrypted communication
```

Para las búsquedas se utiliza el mismo formato de fecha y hora:

```text
Sep 8 2024 00:22:43
```

## Algoritmos implementados

El programa incluye los siguientes algoritmos:

1. Swap Sort
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Merge Sort
6. Quick Sort
7. Shell Sort

Shell Sort fue el algoritmo extra agregado en la Actividad 1.5.

## Compilación

Para compilar el programa se utiliza:

```bash
g++ evidence.cpp -o evidence
```

## Ejecución

Para ejecutar el programa:

```bash
./evidence
```

Durante la ejecución, el usuario debe:

1. Elegir uno de los dos archivos.
2. Elegir un algoritmo.
3. Escribir una predicción sobre el tiempo.
4. Revisar el tiempo obtenido.
5. Indicar si el resultado coincidió con la predicción.
6. Escribir una fecha inicial y una fecha final.
7. Elegir si desea realizar otra corrida.

## Archivos generados

El programa genera estos archivos:

- `output607.txt`: contiene los registros ordenados de la corrida más reciente.
- `range607.txt`: contiene los registros encontrados en el último rango.
- `resultados607.txt`: guarda los datos y tiempos de las corridas realizadas.

## Búsqueda por rango

La búsqueda se realiza sobre los datos previamente ordenados.

Se utilizan dos búsquedas binarias:

- `buscarInicio` encuentra el primer registro igual o mayor que la fecha inicial.
- `buscarFin` encuentra la posición después del último registro igual que la fecha final.

Esto permite incluir todos los registros con timestamps duplicados sin perderlos ni repetirlos.

## Complejidades

| Algoritmo | Mejor caso | Peor caso |
|---|---:|---:|
| Swap Sort | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) |
| Bubble Sort | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n²) |
| Shell Sort | O(n log n) | O(n²) |

La búsqueda de cada límite del rango tiene complejidad O(log n).

## Uso de inteligencia artificial

Se utilizó inteligencia artificial como apoyo para revisar sintaxis, entender errores y adaptar los algoritmos de la Actividad 1.5 para trabajar con objetos `Log`.

Las sugerencias fueron revisadas y modificadas antes de integrarlas. Por ejemplo, inicialmente se interpretó de forma incorrecta el formato del archivo y el año se estaba leyendo como si fuera la hora. El problema se detectó al revisar la salida y se corrigió la lectura para separar correctamente el año, la hora y la dirección IP.

También se revisó el manejo de los límites de la búsqueda para asegurar que los timestamps duplicados fueran incluidos correctamente.

## Video

El video de demostración se encuentra en el siguiente enlace:

[Ver video de demostración](https://drive.google.com/file/d/19wADqhcEcCqBoc-eeHcIjM71K2xEA8ni/view?usp=sharing)

## Estructura

```text
Evidence1/
├── evidence.cpp
├── log.h
├── log607-1.txt
├── log607-2.txt
├── output607.txt
├── range607.txt
├── resultados607.txt
├── README.md
└── docs/
    ├── EvidenciasPruebas.pdf
    └── ReflexEvidencia1.pdf
```