//Marcos Herrero

#include "insertQueue.h"


std::ostream &operator<<(std::ostream & flujo, insertQueue const & cola) {
	cola.mostrar(flujo);
	return flujo;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;

	insertQueue principal; int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		principal.push(aux);
	}

	int M, P;
	std::cin >> M >> P;
	insertQueue aInsertar;
	for (int i = 0; i < M; ++i) {
		std::cin >> aux;
		aInsertar.push(aux);
	}

	principal.insert(aInsertar, P);
	std::cout << principal << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}