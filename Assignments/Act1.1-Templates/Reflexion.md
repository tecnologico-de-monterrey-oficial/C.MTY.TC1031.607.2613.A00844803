<!-- 

Reflexión - Act1.1 Templates

1. ¿Qué ventaja concreta notaste al usar templates en tu clase Lista, comparado con haberla hecho solo para un tipo de dato (por ejemplo, solo enteros)? Da un ejemplo de tu propio código.**

Con templates solo escribí la clase `List` una vez y la pude usar con enteros y con strings sin repetir código. En mi `main.cpp` uso `List<int> list;` y también `List<string> names;`, y las dos funcionan con la misma clase. Sin templates hubiera tenido que hacer una clase para cada tipo de dato.

2. ¿Qué parte de la actividad —ya sea el uso de templates o el reto de insertAt/removeAt— te costó más trabajo entender o depurar? ¿Qué hiciste para resolverlo?**

Lo que más se me dificultó fue `insertAt` y `removeAt`, porque no sabía bien cómo mover los elementos de lugar dentro del vector sin perder datos. Para resolverlo usé las funciones `insert` y `erase` que ya trae `vector`, en lugar de mover los elementos a mano. Luego probé cada método imprimiendo la lista para ver que sí funcionara bien.

3. Si tuvieras que explicarle a un compañero qué es un template en C++ usando tus propias palabras, sin tecnicismos, ¿qué le dirías?**

Le diría que un template es como un molde: escribes el código una sola vez y dejas un espacio en blanco para el tipo de dato. Luego, cada vez que lo usas, tú decides si ese espacio va a ser un entero, un texto o cualquier otro tipo, y el compilador se encarga de acomodarlo. 

-->