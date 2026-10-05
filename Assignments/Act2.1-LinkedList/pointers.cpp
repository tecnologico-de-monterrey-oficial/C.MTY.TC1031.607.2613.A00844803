// Cesar Cardenas - A00844803
#include <iostream>
#include <memory>
#include "Fraction.h"

int main() {
    int x = 42;
    int* p = &x;
    std::cout << x << '\n' << &x << '\n' << p << '\n' << *p << '\n';
    int* q = new int(5);
    std::cout << "Valores de q: " << q << ", " << *q << '\n';
    delete q;
    q = nullptr;
    // Despues de delete no se desreferencia el apuntador.
    std::cout << "q liberado y restablecido a nullptr\n";
    Fraction* f = new Fraction(2, 3);
    f->print();
    std::cout << f->getDenominator() << '/' << f->getNumerator() << '\n';
    delete f;
    f = nullptr;
    auto g = std::make_unique<Fraction>(3, 4);
    g->print();
    std::cout << g->getDenominator() << '/' << g->getNumerator() << '\n';
}
