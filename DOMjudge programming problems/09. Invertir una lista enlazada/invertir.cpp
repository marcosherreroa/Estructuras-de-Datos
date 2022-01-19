//Marcos Herrero


#include "queue_eda.h"
#include <iostream>

template< class T>
std::ostream &operator<<(std::ostream & flujo, queue<T> const & cola) {
	cola.mostrar(flujo);
	return flujo;
}

bool resuelveCaso() {
	int aux;
	std::cin >> aux;
	if (!std::cin)return false;

	queue<int> cola;
	while (aux != 0) {
		cola.push(aux);
		std::cin >> aux;
	}

	cola.invertirNodos();
	std::cout << cola << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}