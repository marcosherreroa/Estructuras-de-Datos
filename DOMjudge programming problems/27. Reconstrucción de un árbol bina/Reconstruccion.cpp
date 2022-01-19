//Marcos Herrero

#include "bintree_eda.h"
#include <vector>
#include <sstream>

bintree<int> reconstruir(std::vector<int>  const & preorden, int ini, int fin) {
	if (ini >= fin) return{};
	int raiz = preorden[ini];

	int ind = ini + 1;
	while (ind < fin && preorden[ind] < raiz) ++ind;
		
	bintree<int> left = reconstruir(preorden, ini+1, ind);
    bintree<int> right = reconstruir(preorden, ind, fin);

	return{ left, raiz, right };
}

bool resuelveCaso() {
	std::string linea; 
	getline(std::cin, linea);

	if (!std::cin)return false;

	std::vector<int> preorden;
	int aux;

	std::stringstream ss1(linea);
	ss1 >> aux;
	while (ss1) {
		preorden.push_back(aux);
		ss1 >> aux;
	}

	bintree<int> sol = reconstruir(preorden,0, preorden.size());
	std::vector<int> v = sol.postorder();

	for (int i = 0; i < v.size(); ++i) std::cout << v[i]<<' ';
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}