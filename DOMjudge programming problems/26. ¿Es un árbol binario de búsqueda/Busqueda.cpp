//Marcos Herrero

#include "bintree_eda.h"
#include <iostream>

struct tSol {
	bool BST;
	int max;
	int min;
};

tSol BST(bintree<int> const & tree) {
	int max = tree.root(), min = tree.root();

	tSol izq, dch;
	if (!tree.left().empty()) {
		izq = BST(tree.left());
		if (izq.max > max) max = izq.max;
		if (izq.min < min) min = izq.min;
	}

	if (!tree.right().empty()) {
		dch = BST(tree.right());
		if (dch.max > max) max = dch.max;
		if (dch.min < min) min = dch.min;
	}

	return { (tree.left().empty() || izq.max < tree.root() && izq.BST) &&
		(tree.right().empty() || tree.root() < dch.min && dch.BST), max, min };
}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);

	if (tree.empty())std::cout << "SI\n";
	else {
		tSol sol = BST(tree);
		if(sol.BST) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}