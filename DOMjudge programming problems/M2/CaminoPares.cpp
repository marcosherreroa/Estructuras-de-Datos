//Marcos Herrero
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

struct sol {
	int r;
	int s;
};

sol caminoPares(bintree<int> const & tree) {
	if (tree.empty())return{ 0, 0 };
	else {
		sol izq = caminoPares(tree.left());
		sol dch = caminoPares(tree.right());

		sol sol;
		if (tree.root() % 2 == 0) {
			sol.s = 1 + std::max(izq.s, dch.s);
			sol.r = std::max(1+izq.s+dch.s, std::max(izq.r, dch.r));
		}
		else {
			sol.s = 0;
			sol.r = std::max(izq.r, dch.r);
		}

		return sol;
	}
}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);

	std::cout << caminoPares(tree).r << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}