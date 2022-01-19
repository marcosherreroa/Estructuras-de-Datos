//Marcos Herrero

#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <vector>
#include <cmath>

struct monomio {
	int coef;
	int exp;
};

class polinomio {
public:  polinomio() {};
		 void agregarMonomio(int coef, int exp);
		 int evaluar(int num)const;
private: std::vector<monomio> v;
};

#endif