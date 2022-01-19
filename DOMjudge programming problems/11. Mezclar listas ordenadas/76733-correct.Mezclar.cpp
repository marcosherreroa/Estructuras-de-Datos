//Marcos Herrero

#include "mixQueue.h"
#include <iostream>


std::ostream &operator<<(std::ostream & flujo, mixQueue const & cola) {
	cola.mostrar(flujo);
	return flujo;
}

void resuelveCaso() {
	mixQueue c1, c2; int aux;

	std::cin >> aux;
	while (aux != 0) {
		c1.push(aux);
		std::cin >> aux;
	}

	std::cin >> aux;
	while (aux != 0) {
		c2.push(aux);
		std::cin >> aux;
	}

	c1.mezclar(c2);
	std::cout << c1 << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}