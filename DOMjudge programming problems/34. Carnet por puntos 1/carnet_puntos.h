#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <unordered_map>
#include <string>
#include <vector>
#include <exception>

class carnet_puntos {
private:
	std::unordered_map<std::string, int> puntosPersona;
	std::vector<int> numConductores;

	//se escoge representar numConductores con un vector porque el numero de puntos posibles es muy pequeno. Si hubiera muchas mas posibiliades, convendria mas usar otro map

public:
	carnet_puntos():numConductores(16) {};

	void nuevo(std::string const & DNI) { //Coste constante
		if (puntosPersona.count(DNI) == 1)throw std::domain_error("Conductor duplicado");

		puntosPersona[DNI] = 15;
		++numConductores[15];
	}

	void quitar(std::string const & DNI, int puntos) { //Coste constante
		if (puntosPersona.count(DNI) == 0)throw std::domain_error("Conductor inexistente");

		int puntosAntiguos = puntosPersona[DNI], puntosNuevos = 0;
		if (puntosAntiguos > puntos) puntosNuevos = puntosAntiguos - puntos;

		--numConductores[puntosAntiguos];
		++numConductores[puntosNuevos];
		puntosPersona[DNI] = puntosNuevos;
	}

	int consultar(std::string const & DNI)const { // Coste constante
		if (puntosPersona.count(DNI) == 0)throw std::domain_error("Conductor inexistente");

		return puntosPersona.at(DNI);
	}

	int cuantos_con_puntos(int puntos) { //Coste constante
		if (puntos < 0 || puntos > 15)throw std::domain_error("Puntos no validos");

		return numConductores[puntos];
	}



};


#endif