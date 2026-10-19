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

Se utilizó ChatGPT como apoyo para revisar los requisitos de la actividad y comprender las estructuras de datos y funciones utilizadas. También se consultó sobre la búsqueda inversa con pila, las diferencias entre Merge Sort y Quick Sort, errores de compilación y pruebas con los archivos `log607`.

Prompts de referencia:

- “Explícame cómo buscar todos los registros de un día en una lista ordenada.”
- “Explícame cómo usar una pila para mostrar los resultados de una búsqueda en orden inverso.”
- “¿Cuál es la diferencia entre Merge Sort y Quick Sort al ordenar mis registros?”
- “¿Qué errores o casos límite debo revisar al cargar los archivos `log607`?”
- “Explícame qué significan el número de comparaciones y la profundidad máxima del ordenamiento.”

## Video

Agrega aquí el enlace al video de 3 a 5 minutos cuando esté grabado y subido.