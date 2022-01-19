//Marcos Herrero
//No he sabido utilizar la constructora con argumentos pedida
#include "horas.h"


std::istream &operator>>(std::istream & flujo, horas & horas) {
	horas.read(flujo);
	return flujo;
}

std::ostream &operator<<(std::ostream & flujo, horas const & horas) {
	horas.print(flujo);
	return flujo;
}

bool busqBinRecurs(std::vector<horas> const & v, horas  buscado, int ini, int fin , int & pos) {
	if (ini == fin) {
		pos = ini;
		return false;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (buscado < v[m])return busqBinRecurs(v, buscado, ini, m, pos);
		else if (v[m] < buscado) return busqBinRecurs(v, buscado, m + 1, fin,pos);
		else {
			pos = m;
			return true;
		}
	}
}


bool resuelveCaso() {
	int ntrenes, nhoras;
	std::cin >> ntrenes >> nhoras;

	if (ntrenes == 0 && nhoras == 0)return false;

	std::vector<horas> vtrenes(ntrenes);
	for (int i = 0; i < ntrenes; ++i)std::cin >> vtrenes[i];

	horas hora;
	for (int i = 0; i < nhoras; ++i) {
		try {
			std::cin >> hora;
			int pos = 0;
			busqBinRecurs(vtrenes, hora, 0, ntrenes, pos);
			if (pos == ntrenes) std::cout << "NO\n";
			else std::cout << vtrenes[pos] << '\n';
		}
		catch (std::domain_error) {
			std::cout << "ERROR\n";
		}
		
	}

	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
}
