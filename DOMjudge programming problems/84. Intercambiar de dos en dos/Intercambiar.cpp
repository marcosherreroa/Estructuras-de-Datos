//Marcos Herrero
#include "queueExtended.h"

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0)return false;

	queueExtended<int> cola;
	int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		cola.push(aux);
	}

	cola.intercambiar();
	cola.mostrar(std::cout);
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}