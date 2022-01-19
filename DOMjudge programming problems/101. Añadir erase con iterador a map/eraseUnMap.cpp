//Marcos Herrero
#include <iostream>
#include "hashmap_eda.h"

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	unordered_map<int,int> map;
	int key;
	for (int i = 0; i < N; ++i) {
		std::cin >> key;
		map[key] = 0;
	}

	auto it = map.begin();
	while (it != map.end()) {
		if (it->clave % 2 == 0)it = map.erase(it);
		else ++it;
	}

	std::cout << "TODO BIEN\n";
}

int main() {
	while (resuelveCaso());
}