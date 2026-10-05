// Cesar Cardenas - A00844803
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) throw std::invalid_argument("El denominador no puede ser cero");
    }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int num) { numerator = num; }
    void setDenominator(int den) {
        if (den == 0) throw std::invalid_argument("El denominador no puede ser cero");
        denominator = den;
    }
    void print() const { std::cout << numerator << '/' << denominator << '\n'; }
};
#endif
