# Evidencia 2: Estructuras de datos lineales

**Cesar Cardenas - A00844803**

## Archivos

El programa usa `log607-1.txt` o `log607-2.txt`. Coloca los archivos `.h`, `main.cpp` y los dos archivos de log en esta carpeta.

## Compilar y ejecutar

```bash
g++ -std=c++11 main.cpp -o evidencia2
./evidencia2
```

El programa permite ordenar con Merge Sort o Quick Sort, buscar registros de un día, mostrar esa búsqueda al revés con una pila y consultar estadísticas. El ordenamiento genera `output607.out`.

## Pruebas de estructuras

```bash
g++ -std=c++11 test_estructuras.cpp -o test_estructuras
./test_estructuras
```

Las pruebas revisan casos vacíos, con un elemento y operaciones en los extremos. También comprueban los mensajes de error al intentar sacar elementos de una pila o fila vacía.

## Uso de inteligencia artificial

## Uso de inteligencia artificial

Utilicé ChatGPT como apoyo para aclarar dudas, explicarme conceptos y revisar mi programa contra los requisitos de la actividad. La implementación base de las estructuras, la carga y validación de los logs, los ordenamientos, la búsqueda por día, las estadísticas y el menú la realicé yo, y yo ejecuté el programa para obtener las mediciones del reporte.

También le pedí que revisara mi programa y me señalara errores o casos incompletos. A partir de sus recomendaciones mejoré la estructura del código para que quedara más limpia y corregí errores que yo no había logrado detectar. Las sugerencias que decidí aplicar las integré y probé yo.

Las consultas trataron sobre cómo aprovechar que la lista está ordenada para buscar los registros de un día, cómo funciona una pila para mostrar resultados en orden inverso, las diferencias entre Merge Sort y Quick Sort, el significado del número de comparaciones y de la profundidad máxima, y errores de compilación y casos límite al cargar los archivos log607.

Prompts utilizados:
- “¿Cuál es la diferencia entre Merge Sort y Quick Sort al ordenar mis registros?”
- “¿Qué errores o casos límite debo revisar al cargar los archivos `log607`?”
- “Revisa mi programa según los requisitos de la actividad y explícame qué errores o casos incompletos encuentras.”

## Video
https://drive.google.com/file/d/1_c3y0Jw5o9LxV-bbME5I-ArvYHlwdUFR/view?usp=share_link
