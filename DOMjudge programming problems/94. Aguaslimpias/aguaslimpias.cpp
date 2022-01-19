//Marcos Herrero
#include "bintree_eda.h"
#include<algorithm>

struct par {
	int tramos;
	int caudalAcum;
};

par tramosNavegables(bintree<int> const & tree) {
	if (tree.empty()) return { 0, 0};
	else if (tree.left().empty() && tree.right().empty()) return { 0, std::max(0 ,1 - tree.root()) };
	else {
		par l = tramosNavegables(tree.left());
		par r = tramosNavegables(tree.right());
		int tramos= l.tramos + r.tramos;
		if (l.caudalAcum >= 3)++tramos;
		if (r.caudalAcum >= 3)++tramos;
		return { tramos, std::max(0, l.caudalAcum + r.caudalAcum - tree.root()) };
	}

}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);

	std::cout << tramosNavegables(tree).tramos << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}