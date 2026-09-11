#ifndef FRACTION_H
#define FRACTION_H

class fraccion {
private:
	int numerador;
	int denominador;

public:
	fraccion(int numerador = 0, int denominador = 1)
		: numerador(numerador), denominador(denominador) {}

	int getNumerador() const {
		return numerador;
	}

	int getDenominador() const {
		return denominador;
	}
};

#endif
