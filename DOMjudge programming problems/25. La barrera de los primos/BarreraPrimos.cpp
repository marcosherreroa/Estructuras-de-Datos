//Marcos Herrero

#include "bintree_eda.h"
#include <cmath>
#include <queue>

struct Nodo {
	bool valido;
	int el;
	int nivel;
};

bool esprimo(int n) {
	int N = sqrt(n);
	bool primo = true;
	for (int i = 2; primo && i <= N; ++i) {
		if (n %  i == 0)primo = false;
	}

	return primo;
}

//Nodo mejorNodo(bintree<int> const & tree, int nivel, Nodo const & mejor) {
//	if (tree.empty() || (mejor.valido && nivel >= mejor.nivel) || esprimo(tree.root())) {
//		return { false , 0, 0 };
//	}
//
//	else if (tree.root() % 7 == 0) return { true, tree.root(), nivel };
//
//	else {
//		Nodo nuevoMejor = mejor;
//		Nodo mejorIzq = mejorNodo(tree.left(), nivel + 1, mejor);
//		if (mejorIzq.valido)nuevoMejor = mejorIzq;
//		Nodo mejorDcha = mejorNodo(tree.right(), nivel + 1, nuevoMejor);
//		if (mejorDcha.valido)nuevoMejor = mejorDcha;
//
//
//		return nuevoMejor;
//	}
//}

Nodo mejorNodo(bintree<int> const & tree) {
	std::queue<bintree<int>> pendientes; bool encontrado = false;
    pendientes.push(tree);
	bintree<int> sig;
	int nivel = 0;
	int mejor = -1;
	int N = 1;
	while (!encontrado && !pendientes.empty()) {
		N = pendientes.size();
		for (int i = 0; !encontrado && i < N; ++i) {

			sig = pendientes.front();
			pendientes.pop();
			if (!sig.empty()) {
				if (sig.root() % 7 == 0 && sig.root() != 7) {
					encontrado = true;
					mejor = sig.root();
				}
				else if (!esprimo(sig.root())) {
					pendientes.push(sig.left());
					pendientes.push(sig.right());
				}
			}
		}

		++nivel;
	}

	return { encontrado, mejor, nivel };
}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);
	Nodo mejor = { false, 0, 0 };
	
	mejor = mejorNodo(tree);

	if (!mejor.valido) std::cout << "NO HAY\n";
	else std::cout << mejor.el << ' ' << mejor.nivel << '\n';

}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}