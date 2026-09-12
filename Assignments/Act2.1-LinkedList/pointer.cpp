#include <iostream>
#include <memory>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator)
        : numerator(numerator), denominator(denominator) {}

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    int x = 42;
    int* p = &x;
    cout << x << endl;
    cout << &x << endl;
    cout << *p << endl;
    cout << p << endl;

    int* q = new int(5);
    cout << q << endl;
    cout << *q << endl;

    delete q;
    q = nullptr;
    cout << q << endl;

    Fraction* f = new Fraction(2, 3);
    f->print();
    cout << f->getDenominator() << "/" << f->getNumerator() << endl;

    delete f;
    f = nullptr;

    auto g = make_unique<Fraction>(4, 5);
    g->print();
    cout << g->getDenominator() << "/" << g->getNumerator() << endl;

    return 0;
}