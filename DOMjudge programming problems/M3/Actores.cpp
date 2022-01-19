//Marcos Herrero
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::unordered_map < std::string, std::unordered_map<std::string, int>> porPeliculas;
	std::unordered_map<std::string, int> emisiones;
	std::unordered_map<std::string, int> tiemposActores;
	std::set<std::string> actoresMasTiempo;

	std::string titulo, actor; int A, tiempoAct;
	for (int i = 0; i < N; ++i) {
		std::cin >> titulo >> A;

		auto mapActores = &porPeliculas[titulo];
		for (int j = 0; j < A; ++j) {
			std::cin >> actor >> tiempoAct;
			(*mapActores)[actor] = tiempoAct;
		}
	}

	int E;
	std::cin >> E;

	std::string favorita;
	int maxEmisiones = 0;
	for (int i = 0; i < E; ++i) {
		std::cin >> titulo;
		++emisiones[titulo];

		int numEm = emisiones[titulo];
		if (numEm >= maxEmisiones) {
			maxEmisiones = numEm;
			favorita = titulo;
		}
	}

	
	for (auto it = emisiones.begin(); it != emisiones.end(); ++it) {
		auto mapActores = porPeliculas[it->first];
		for (auto it2 = mapActores.begin(); it2 != mapActores.end(); ++it2) {
			tiemposActores[it2->first] += (it2->second* it->second);
		}
	}

	int maxTiempo = 0;
	for (auto it = tiemposActores.begin(); it != tiemposActores.end(); ++it) {
		if (it->second > maxTiempo) {
			maxTiempo = it->second;
			actoresMasTiempo.clear();
			actoresMasTiempo.insert(it->first);
		}
		else if (it->second == maxTiempo) {
			actoresMasTiempo.insert(it->first);
		}
	}

	std::cout << maxEmisiones << ' ' << favorita<<'\n';
	std::cout << maxTiempo;
	for (auto it = actoresMasTiempo.begin(); it != actoresMasTiempo.end(); ++it)std::cout << ' ' << *it;
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}