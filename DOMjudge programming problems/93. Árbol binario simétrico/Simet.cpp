//Marcos Herrero

#include "bintree_eda.h"

bool mirror(bintree<char> const &left, bintree<char> const & right) {
	if (left.empty()) return right.empty();
	else if (right.empty())return false;
	else return left.root() == right.root() && mirror(left.left(), right.right()) && mirror(left.right(), right.left());
}

void resuelveCaso() {
	bintree<char> tree = leerArbol('.');

	if (mirror(tree.left(), tree.right()))std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}