//Marcos Herrero

#include "queueExtended.h"

bool resuelveCaso() {
	int nelems;
	std::cin >> nelems;
	if (nelems == 0)return false;

	queueExtended<horas> cola;
	horas aux;
	for (int i = 0; i < nelems; ++i) {
		std::cin >> aux;
		cola.push(aux);
	}

	cola.eliminarDecrecientes();
	while (!cola.empty()) {
		std::cout << cola.front() << ' ';
		cola.pop();
	}

	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}