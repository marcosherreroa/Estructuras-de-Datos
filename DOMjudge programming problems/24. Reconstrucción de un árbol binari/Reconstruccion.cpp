//Marcos Herrero

#include "bintree_eda.h"
#include <vector>
#include <sstream>

struct treecont {
	bintree<int> tree;
    int cont;
};

treecont reconstruir(int k, std::vector<int>  const & preorden, std::vector<int> const & inorden, int ini, int fin) {
	if (ini >= fin) return{ {}, 0 };
	int raiz = preorden[k];

	int ind ; bool encontrado = false;
	for (int i = ini; !encontrado && i < fin; ++i) {
		if (inorden[i] == preorden[k]) {
			encontrado = true;
			ind = i;
		}
	}

	if (!encontrado) return { {}, 0 };
	else {
		++k;
		treecont left = reconstruir(k, preorden, inorden, ini, ind);
		k += left.cont;
		treecont right = reconstruir(k, preorden, inorden, ind + 1, fin);

		return{ {left.tree, raiz, right.tree}, 1+left.cont+right.cont };
	}
}

bool resuelveCaso() {
	std::string linea; 
	getline(std::cin, linea);

	if (!std::cin)return false;

	std::vector<int> preorden;
	std::vector<int> inorden;
	int aux;

	std::stringstream ss1(linea);
	ss1 >> aux;
	while (ss1) {
		preorden.push_back(aux);
		ss1 >> aux;
	}

	getline(std::cin, linea);

	std::stringstream ss2(linea);
	ss2 >> aux;
	while (ss2) {
		inorden.push_back(aux);
		ss2 >> aux;
	}

	treecont sol = reconstruir(0 ,preorden, inorden,0, preorden.size());
	std::vector<int> v = sol.tree.postorder();

	for (int i = 0; i < sol.cont; ++i) std::cout << v[i]<<' ';
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}