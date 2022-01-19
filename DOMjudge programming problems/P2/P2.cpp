//Marcos Herrero
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

struct Alturas {
	int r;
	int s;
};

Alturas subMayor(bintree<char> const & tree) {
	if (tree.empty())return { 0,0 };
	else {
		Alturas l = subMayor(tree.left());
		Alturas r = subMayor(tree.right());

		Alturas sol;
		sol.s = 1 + std::min(l.s, r.s);
		sol.r = std::max(sol.s,std::max(l.r, r.r));

		return sol;
	}
}

void resuelveCaso() {
	bintree<char> tree = leerArbol('.');
	std::cout << subMayor(tree).r << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}