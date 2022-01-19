//Marcos Herrero

#include "bintree_eda.h"
#include <utility>

std::pair<bool, int> zurdo(bintree<char> const & tree) { //zurdo, numNodos
	if (tree.empty())return { true, 0 };
	else if (tree.left().empty() && tree.right().empty()) return { true, 1 };
	else if (tree.right().empty()) {
		auto soll = zurdo(tree.left());
		return { soll.first, 1+ soll.second };
	}
	else if(tree.left().empty()) return{ false, -1 };
	else {
		auto soll = zurdo(tree.left());
		auto solr = zurdo(tree.right());

		return { soll.first && solr.first && soll.second > (soll.second + solr.second) / 2, 1 + soll.second + solr.second};
	}
	
}

void resuelveCaso() {
	bintree<char> tree = leerArbol('.');

	if (zurdo(tree).first)std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}