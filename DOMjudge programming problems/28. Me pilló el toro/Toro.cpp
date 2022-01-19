//Marcos Herrero
#include <iostream>
#include <string>
#include <map>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::map<std::string, int> mapa;
	std::string autor, puntuacion;
	for (int i = 0; i < N; ++i) {
		std::cin.ignore(1);
		getline(std::cin, autor);
		std::cin >> puntuacion;
		
		if (puntuacion == "CORRECTO") ++mapa[autor];
		else --mapa[autor];
	}

	std::map<std::string, int>::iterator it = mapa.begin();
	while (it != mapa.end()) {
		if (it->second != 0) std::cout << it->first<<", "<<it->second<<'\n';
		++it;
	}

	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
}