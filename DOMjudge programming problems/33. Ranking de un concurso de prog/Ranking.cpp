//Marcos Herrero

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

struct Problema {
	bool correct;
	int tiempo;
};

struct Equipo {
	std::string nombre;
	int numproblemas;
	int tiempo;
};

bool operator<(Equipo const & a, Equipo const & b) {
	if (a.numproblemas > b.numproblemas)return true;
	else if (a.numproblemas == b.numproblemas && a.tiempo < b.tiempo)return true;
	else if (a.numproblemas == b.numproblemas && a.tiempo == b.tiempo && a.nombre < b.nombre)return true;
	else return false;
}

void resuelveCaso() {
	std::string equipo, problema, verd; int min;

	std::unordered_map < std::string, std::unordered_map<std::string, Problema>> clasif ;
	std::cin >> equipo;
	while (equipo != "FIN") {
		std::cin >> problema >> min >> verd;
		if (clasif[equipo].count(problema) == 0 || clasif[equipo][problema].correct == false) {
			if (verd == "AC") {
				clasif[equipo][problema].correct = true;
				clasif[equipo][problema].tiempo += min;
			}
			else {
				clasif[equipo][problema].correct = false;
				clasif[equipo][problema].tiempo += 20;
			}
		}

		std::cin >> equipo;
	}
	
	std::vector<Equipo> sol; Equipo aux;
	for (auto i = clasif.begin(); i != clasif.end(); ++i) {
		aux.nombre = i->first;
		aux.numproblemas = 0;
		aux.tiempo = 0;
		for (auto j = i->second.begin(); j != i->second.end(); ++j) {
			if (j->second.correct) {
				++aux.numproblemas;
				aux.tiempo += j->second.tiempo;
			}
		}

		sol.push_back(aux);
	}

	std::sort(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); ++i) {
		std::cout << sol[i].nombre <<' '<< sol[i].numproblemas <<' '<< sol[i].tiempo << '\n';
	}

	std::cout << "----\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}