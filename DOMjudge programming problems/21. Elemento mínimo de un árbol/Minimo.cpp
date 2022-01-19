//Marcos Herrero

#include <iostream>
#include <string>
#include <algorithm>
#include "bintree_eda.h"

template<typename T>
T minArbol(bintree<T> const & tree) {
	if (tree.left().empty() && tree.right().empty()) return tree.root();
	else if (tree.left().empty()) return std::min(tree.root(), minArbol(tree.right()));
	else if(tree.right().empty()) return std::min(tree.root(), minArbol(tree.left()));
	else return std::min(std::min(tree.root(), minArbol(tree.left())), minArbol(tree.right()));
}

bool resuelveCaso() {
	char c;
	std::cin >> c;
	if (!std::cin)return false;

	switch (c) {
	case 'N': {
		bintree<int> tree = leerarbol(-1);
		std::cout << minArbol(tree) << '\n';
		break;
	}
	case 'P':
		std::string aux = "#";
		bintree<std::string> tree = leerarbol(aux);
		std::cout << minArbol(tree) << '\n';
		break;
	}

	return true;
}

int main() {
	while (resuelveCaso());
}