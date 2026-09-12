# Reflexión - A00844803

1. ¿Qué algoritmos lograste implementar con mayor facilidad gracias al apoyo de Copilot?
Los algoritmos cuadráticos como Bubble Sort, Selection Sort y Swap Sort se implementaron mas facil, ya que siguen una estructura iterativa bastante estándar y predecible con ciclos anidados.

2. ¿En qué casos Copilot te dio soluciones correctas de inmediato y en cuáles tuviste que corregir o ajustar la propuesta?
En algoritmos recursivos como Merge Sort y Quick Sort ofreció la lógica base correcta a la primera, pero, para los primeros cuatro algoritmos fue necesario ajustar manualmente el código para incluir las variables de conteo de comparaciones e intercambios sin alterar el flujo original del ordenamiento.

3. ¿Consideras que Copilot te ayudó a ahorrar tiempo o más bien te obligó a pensar más sobre cómo funciona el algoritmo?
Pues ahorró tiempo considerable en la escritura de sintaxis repetitiva, como la creación del menú interactivo y la toma de tiempos en nanosegundos con "<chrono>". No obstante, obligó a analizar más a fondo la complejidad algorítmica cuando se vio la diferencia de rendimiento al procesar listas grandes de 100,000 elementos.

4. Escribe un ejemplo concreto donde Copilot no resolvió el problema directamente y tuviste que razonar la solución.
Al contar las comparaciones en Insertion Sort, Copilot sugería colocar el contador solo dentro del ciclo "while". Esto dejaba fuera la última comparación (la que hace que la condición falle y termine el ciclo). Tuve que mover el incremento para que contara correctamente todas las iteraciones evaluadas.

5. ¿Qué hubieras hecho diferente si no hubieras tenido acceso a Copilot para esta actividad?
Habría tomado más tiempo construyendo la estructura del menú, las funciones de prueba y la medición del tiempo de ejecución. También habría tenido que revisar notas de clase para verificar los casos base de la división en Merge Sort.