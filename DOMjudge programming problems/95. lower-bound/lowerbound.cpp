//Marcos Herrero
#include "set_eda.h"
#include <iostream>

bool resuelveCaso() {
	int N, M;
	std::cin >> N;
	if (N == 0)return false;
	set<int> conj; int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		conj.insert(aux);
	}

	std::cin >> M;
	for (int i = 0; i < M; ++i) {
		std::cin >> aux;
		auto sol = conj.lower_bound(aux);
		if (sol.first)std::cout << sol.second<<'\n';
		else std::cout << "NO HAY\n";
	}

	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
}