//Marcos Herrero

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;
	std::cin.ignore(1);

	std::map<std::string, std::vector<int>> palabras;
	std::string linea, palabra; std::stringstream ss;
	for (int i = 0; i < N; ++i) {
		getline(std::cin, linea);
		ss.clear();
		ss.str("");
		ss << linea;
		while (ss >> palabra) {
			if (palabra.length() > 2) {
				for (int i = 0; i < palabra.size(); ++i) palabra[i] = tolower(palabra[i]);
				//esto hay que optimizarlo. Es lo malo del logaritmo
				if(palabras[palabra].empty() || palabras[palabra][palabras[palabra].size()-1] != i+1)palabras[palabra].push_back(i+1);
			}
		}
	}

	std::map<std::string, std::vector<int>>::iterator it = palabras.begin();
	while (it != palabras.end()) {
		std::cout << it->first;
		for (int i = 0; i < it->second.size(); ++i) std::cout << ' ' << it->second[i];
		std::cout << '\n';
		++it;
	}

	std::cout << "----\n";
	return true;
}

int main() {
	while (resuelveCaso());
}