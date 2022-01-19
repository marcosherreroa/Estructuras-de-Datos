//Marcos Herrero

#include "bintreeExtended.h"


void resuelveCaso() {
	bintreeExtended<int> arbol = readExtended(-1);

	std::vector<int> frontera = arbol.frontera();

	for (int i = 0; i < frontera.size(); ++i) std::cout << frontera[i]<<' ';
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}