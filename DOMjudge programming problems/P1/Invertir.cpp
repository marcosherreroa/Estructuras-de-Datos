//Marcos Herrero

#include "queue_extended.h"

bool resuelveCaso() {
	int N, P, L;

	std::cin >> N >> P >> L;
	if (!std::cin) return false;

	queue_extended cola;
	int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		cola.push(aux);
	}

	cola.invertir(P, L);
	cola.mostrar(std::cout);
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}