//Marcos Herrero
#include "carnet_puntos.h"
#include <iostream>

bool resuelveCaso(){
	std::string op, DNI; int puntos;
	std::cin >> op;
	if (!std::cin) return false;
	
	carnet_puntos cp;
	while (op != "FIN") {
		try {
			if (op == "nuevo") {
				std::cin >> DNI;
				cp.nuevo(DNI);
			}
			else if (op == "quitar") {
				std::cin >> DNI >> puntos;
				cp.quitar(DNI, puntos);
			}
			else if (op == "consultar") {
				std::cin >> DNI;
				std::cout << "Puntos de " << DNI << ": " << cp.consultar(DNI) << '\n';
			}
			else if (op == "cuantos_con_puntos") {
				std::cin >> puntos;
				std::cout << "Con " << puntos << " puntos hay " << cp.cuantos_con_puntos(puntos) << '\n';
			}
		}
		catch (std::domain_error const & e) {
			std::cout <<"ERROR: "<< e.what() << '\n';
		}

		std::cin >> op;
	}

	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
}