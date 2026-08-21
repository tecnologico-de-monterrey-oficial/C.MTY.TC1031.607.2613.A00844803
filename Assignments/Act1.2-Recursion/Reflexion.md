Reflexion

1. ¿En que casos notaste que la version recursiva fue mas lenta o uso mas memoria que la iterativa? ¿A que se debio?

La version recursiva puede ser mas lenta y usar mas memoria porque cada llamada de la funcion se guarda en la memoria hasta que termina la recursion. La version iterativa utiliza ciclos y no necesita crear tantas llamadas a funciones.

En especial, Fibonacci recursivo puede ser mucho mas lento porque realiza muchas llamadas repetidas para calcular los mismos valores.

2. Para la suma 1..n, sumFormula resuelve en un solo paso lo que a sumIterative y sumRecursive les toma n pasos. ¿Que te dice esto sobre buscar una formula antes de escribir codigo?

Me dice que antes de programar un problema es importante analizarlo y buscar si existe una formula o una solucion mas eficiente. En este caso, sumFormula obtiene el resultado directamente, mientras que las otras dos funciones necesitan realizar n operaciones.

3. Si bacteriasRecursive tuviera que calcular n = 100,000 dias, ¿que problema esperarias encontrar y como lo resolverias?

Esperaria que el programa tuviera problemas por la gran cantidad de llamadas recursivas y podria provocar un desbordamiento de la pila de memoria. Lo resolveria utilizando la version iterativa, ya que utiliza un ciclo y no necesita realizar miles de llamadas recursivas.