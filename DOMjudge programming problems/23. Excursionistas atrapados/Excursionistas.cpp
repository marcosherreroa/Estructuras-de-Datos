//Marcos Herrero

#include <iostream>
#include "bintree_eda.h"

struct sol {
	int max;
	int numgrupos;
};

sol resolver(bintree<int> const & tree) {
	if (tree.empty()) return { 0,0 };
	else {
		sol izq = resolver(tree.left());
		sol dch = resolver(tree.right());

		sol sol;
		sol.max = tree.root() + std::max(izq.max, dch.max);
		sol.numgrupos = izq.numgrupos + dch.numgrupos;
		if (sol.numgrupos == 0 && tree.root() != 0) sol.numgrupos = 1;
		return sol;
	}
}

void resuelveCaso() {
	bintree<int> tree = leerarbol(-1);

	int numgrupos = 1;
	sol sol = resolver(tree);
	std::cout << sol.numgrupos <<' '<< sol.max << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}