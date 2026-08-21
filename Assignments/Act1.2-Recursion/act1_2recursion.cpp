// Cesar Cardenas - A00844803

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sumiterative(int n){
    int suma = 0;
    for(int i = 1; i <= n; i++){
        suma += i;
    }
    return suma;
}

int sumrecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return n + sumrecursive(n - 1);
}

int sumFormula(int n) {
    return n * (n + 1) / 2;
}

int fibonacciIterative(int n) {
    int a = 1;
    int b = 1;
    int c;
    for(int i = 3; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursive(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int bacteriasIterative(int n){
    double born = 3.78;
    double died = 2.34;
    int sum = 1;

    for(int i = 1; i <= n; i++){
        int bacborn = sum * born;
        int bacdied = sum * died;
        sum += bacborn - bacdied;
    }
    return sum;
}

int bacteriasRecursive(int n){
    if(n == 0){
        return 1;
    }

    int bac = bacteriasRecursive(n - 1);
    int born = bac * 3.78;
    int died = bac * 2.34;
    return bac + born - died;
}

double investmentIterative(double dinero, int meses) {

    for(int i = 1; i <= meses; i++) {
        double dineromes = 1.1875 * dinero;
        dinero = dineromes;
    }
    return dinero;
}

double investmentRecursive(double dinero, int meses){
    if(meses == 0){
        return dinero;
    }
    dinero = dinero * 1.1875;
    return investmentRecursive(dinero, meses - 1);
}

int powIterative(int n, int y){
    int resultado = 1;
    for(int i = 1; i <= y; i++){
        resultado *= n;
    }

    return resultado;
}

int powRecursive(int n, int y){
    if(y == 0){
        return 1;
    }
    return n * powRecursive(n, y - 1);
}

int main() {
    cout << "El factorial de 3 es: " << factorial(3) << endl;
    cout << "La suma iterativa de 5 es: "<< sumiterative(5) << endl;
    cout << "La suma recursiva de 5 es: "<< sumrecursive(5) << endl;
    cout << "La suma con formula de 5 es: "<< sumFormula(5) << endl;
    cout << "La fibonacci iterativa de 5 es: "<< fibonacciIterative(5) << endl;
    cout << "La fibonacci recursiva de 5 es: "<< fibonacciRecursive(5) << endl;
    cout << "Las bacterias para el dia 5 son: "<< bacteriasIterative(5) << endl;
    cout << "Las bacterias recursivas para el dia 5 son: "<< bacteriasRecursive(5) << endl;
    cout << "100 pesos en 5 meses se convertiran en: "<< investmentIterative(100, 5) << endl;
    cout << "100 pesos en 5 meses con recursion se convertiran en: "<< investmentRecursive(100, 5) << endl;
    cout << "2 elevado a la 5 de forma iterativa es: "<< powIterative(2, 5) << endl;
    cout << "2 elevado a la 5 de forma recursiva es: "<< powRecursive(2, 5) << endl;

    return 0;
}