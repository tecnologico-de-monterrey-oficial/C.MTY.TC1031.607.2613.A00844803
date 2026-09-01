// Cesar Cardenas - A00844803

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int busquedaSecuencial(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int busquedaBinaria(const vector<int>& arr, int target) {
    int inicio = 0, fin = arr.size() - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (arr[medio] == target) return medio;
        if (arr[medio] < target) inicio = medio + 1;
        else fin = medio - 1;
    }
    return -1;
}

int main() {
    srand(time(0));
    vector<int> datos(10000);

    for (int i = 0; i < 10000; i++) {
        datos[i] = (rand() % 1000000) + 1;
    }

    sort(datos.begin(), datos.end());

    int n;
    while (cout << "\nNumero a buscar (0 para salir): " && cin >> n && n != 0) {
        clock_t t1 = clock();
        int r1 = busquedaSecuencial(datos, n);
        clock_t t2 = clock();

        clock_t t3 = clock();
        int r2 = busquedaBinaria(datos, n);
        clock_t t4 = clock();

        if (r2 != -1) cout << "El numero SI se encuentra en la lista.\n";
        else cout << "El numero NO se encuentra en la lista.\n";

        cout << "Tiempo Secuencial: " << (double)(t2 - t1) * 1000000.0 / CLOCKS_PER_SEC << " us\n";
        cout << "Tiempo Binario:    " << (double)(t4 - t3) * 1000000.0 / CLOCKS_PER_SEC << " us\n";
    }

    return 0;
}