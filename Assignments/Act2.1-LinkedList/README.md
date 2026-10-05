# Act 2.1 - Listas encadenadas

Cesar Cardenas - A00844803

## Descripción

Lista ligada genérica usando templates en C++.

El programa permite crear una lista de enteros o decimales con datos
capturados o aleatorios.

El menú permite agregar, insertar, borrar, consultar, actualizar,
buscar y duplicar los elementos de la lista.

Los índices empiezan en 0. La inserción agrega un elemento después
del índice indicado.

## Archivos

- LinkedList.h: clases Node y LinkedList.
- main.cpp: menú y programa principal.
- tests.pdf: evidencias de las pruebas.
- README.md: descripción y reflexión.

## Compilación

```sh
g++ -std=c++11 main.cpp -o main
./main
```

## Prompts utilizados

- "ayudame a hacer la carpeta con todos los archivos corregidos conforme a lo solicitado en la actividad. Modifica tambien los datos del estudiante a #Cesar Cardenas - A00844803"
- "dame el linked list .cpp para copiar y pegar. Necesito que lo hagas mas sencillo, si no me pidieron algo no lo pongas, solo lo de la act. Por favor que el codigo no sea complejo, apenas estoy aprendiendo. solo lo basico"
- "igual el main.cpp"
- "Igual el readme.md, solo lo basico y necesario"

## Reflexión

Borrador para revisar y adaptar a mi experiencia.

### ¿Qué parte propuso la IA que aceptaste tal cual y por qué era correcta?

La inserción al principio conecta el nuevo nodo con el primer nodo
anterior y después actualiza head. Esto conserva los elementos de la lista.

### ¿Qué parte modificaste y cómo verificaste que tu cambio era mejor?

Se simplificó el código para usar operaciones básicas y un menú directo.
Para verificar esta versión, debo probar cada opción con enteros y
decimales y comparar los resultados con lo esperado.

### ¿Dónde se equivocó la IA y cómo lo detectaste?

La primera propuesta tenía más complejidad de la que necesitaba para
mi nivel. Pedí una versión más sencilla. Los errores de funcionamiento
que encuentre al probarla deben documentarse con su caso y corrección.

### ¿Qué harías diferente sin Copilot o ChatGPT?

Dividiría el problema en operaciones pequeñas, dibujaría los enlaces
entre nodos y probaría cada operación antes de continuar.
