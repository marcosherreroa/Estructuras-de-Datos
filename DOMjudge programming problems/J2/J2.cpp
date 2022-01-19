//Marcos Herrero

#include <iostream>
#include <iomanip>
#include "tienda.h"

std::istream& operator>>(std::istream & flujo, fecha & f) {
	int year, mes, dia; char aux;
	flujo >> dia >> aux >> mes >> aux >> year;
	f.setDia(dia);
	f.setMes(mes);
	f.setYear(year);
	return flujo;
}

std::ostream& operator<<(std::ostream & flujo, fecha const & f) {
	flujo <<std::setfill('0')<<std::setw(2)<< f.getDia() << '/' << std::setw(2)<< f.getMes() << '/' <<std::setw(2)<< f.getYear();
	return flujo;
}

bool resuelveCaso() {
	tienda t;
	std::string instr;
		
	std::cin >> instr;
	if (!std::cin)return false;
	while (instr != "FIN") {
		if (instr == "adquirir") {
			std::string cod; fecha f; int cant;
			std::cin >> cod >> f >> cant;
			std::list<std::string> list= t.adquirir(cod, f, cant);
			std::cout << "PRODUCTO ADQUIRIDO";
			for (auto it = list.begin(); it != list.end(); ++it)std::cout << ' ' << *it;
			std::cout << '\n';
		}
		else if (instr == "vender") {
			std::string cod, cli;
			std::cin >> cod >> cli;
			vendido sol = t.vender(cod, cli);
			if (sol.vendido)std::cout << "VENDIDO " << sol.f<<'\n';
			else std::cout << "EN ESPERA\n";
		}
		else if (instr == "cuantos"){
			std::string cod;
			std::cin >> cod;
			std::cout << t.cuantos(cod) << '\n';
		}
		else if (instr == "hay_esperando") {
			std::string cod;
			std::cin >> cod;
			if (t.hay_esperando(cod))std::cout << "SI\n";
			else std::cout << "NO\n";
		}

		std::cin >> instr;
	}

	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
}