//Marcos Herrero

#include <iostream>
#include "bintree_eda.h"

//r es la longitud del camino más largo
// s es la longitud del camino más largo que termina en la raíz

struct par {
	int r;
	int s;
};

 par diametro(bintree<char> const & tree) {
	 if (tree.empty()) return{ 0,0 };
	else {
		par izq = diametro(tree.left());
		par dch = diametro(tree.right());

		par sol;
		sol.s = std::max(izq.s + 1, dch.s + 1);
		sol.r = std::max(izq.s+dch.s+1, std::max(izq.r, dch.r));
		return sol;
	}
}

void resuelveCaso() {
	bintree<char> tree = leerarbol('.');

	par sol = diametro(tree);
	std::cout << sol.r << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}