//Marcos Herrero

#include "polinomio.h"

bool resuelveCaso() {
	int c, e;
	std::cin >> c >> e;
	if (!std::cin) return false;

	polinomio p;
	while (c != 0 || e != 0) {
		p.agregarMonomio(c, e);
		std::cin >> c >> e;
	}
	
	int N, num;
	std::cin >> N;
	for (int i = 0; i < N-1; ++i) {
		std::cin >> num;//rep expo
		std::cout << p.evaluar(num) << ' ';
	}

	std::cin >> num;
	std::cout << p.evaluar(num)<<'\n';
	return true;
}

int main() {
	while (resuelveCaso());
}