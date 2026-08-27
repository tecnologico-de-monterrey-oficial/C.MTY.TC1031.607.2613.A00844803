#include <iostream>
using namespace std;

int sumaImparesIterativo(int v[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            suma += v[i];
        }
    }
    return suma;
} // O(n), porque recorre el vector una vez, elemento por elemento

int sumaImparesRecursivo(int v[], int n, int indice = 0) {
    if (indice >= n) {
        return 0;
    }

    int resto = sumaImparesRecursivo(v, n, indice + 1);

    if (v[indice] % 2 != 0) {
        return v[indice] + resto;
    } else {
        return resto;
    }
} // O(n), porque hace una llamada recursiva por cada elemento del vector

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(numeros) / sizeof(numeros[0]);

    cout << "Suma de impares (iterativo): "
         << sumaImparesIterativo(numeros, n) << endl;

    cout << "Suma de impares (recursivo): "
         << sumaImparesRecursivo(numeros, n) << endl;

    return 0;
}
