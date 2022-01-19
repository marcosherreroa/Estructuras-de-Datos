//Marcos Herrero
#include "bintree_eda.h"
#include <utility>
#include <algorithm>


std::pair<bool, int> genealogico(bintree<int> const & tree) { // <genealogico, numgeneraciones>
	if (tree.empty()) return { true, 0 };
	else if (tree.left().empty() && tree.right().empty()) return { true, 1 };
	else if (tree.left().empty()) {
		return { false, 0 };
	}
	else if (tree.right().empty()) {
		std::pair<bool, int> soll = genealogico(tree.left());
		return { soll.first && tree.root() - tree.left().root() >= 18 , 1 + soll.second };
	}
	else {
		std::pair<bool, int> soll = genealogico(tree.left());
		std::pair<bool, int> solr = genealogico(tree.right());
		
		return { soll.first && solr.first && tree.root() - tree.left().root() >= 18 &&
		tree.left().root() >= tree.right().root() + 2, 1 + std::max(soll.second, solr.second) };
	}
}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);

	std::pair<bool, int> sol = genealogico(tree);
	if (sol.first) std::cout << "SI " << sol.second<< '\n';
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}