//Marcos Herrero
#include "bintreeExtended.h"

void resuelveCaso() {
	bintreeExtended<char> arbol = readTree('.');

	std::cout << arbol.numNodos() << ' ' << arbol.numHojas() <<' '<< arbol.altura() << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}