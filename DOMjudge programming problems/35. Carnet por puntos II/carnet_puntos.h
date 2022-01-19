#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <exception>

struct infoPersona {
	int puntos;
	std::list<std::string>::iterator puntPersonasPorPuntos;
};

class carnet_puntos {
private:
	std::unordered_map<std::string, infoPersona> puntosPersona;
	std::vector<std::list<std::string>> personasPorPuntos;

	void modificarPuntos(std::string const & DNI, int puntosAntiguos, int puntosNuevos) { // Coste constante
		if (puntosAntiguos != puntosNuevos) {
			auto it = &puntosPersona[DNI];
			personasPorPuntos[puntosAntiguos].erase(it->puntPersonasPorPuntos);

			auto it2 = &personasPorPuntos[puntosNuevos];
			it2->push_front(DNI);
			it->puntPersonasPorPuntos = it2->begin();
			it->puntos = puntosNuevos;
		}
	}

public:
	carnet_puntos() :personasPorPuntos(16) {};

	void nuevo(std::string const & DNI) { //Coste constante
		auto it = puntosPersona.find(DNI);
		if ( it != puntosPersona.end())throw std::domain_error("Conductor duplicado");

		auto it2 = &personasPorPuntos[15];
		it2->push_front(DNI);
		auto punt = it2->begin();
	
		puntosPersona.insert(it, { DNI, { 15, punt } });
	}
		

	void quitar(std::string const & DNI, int puntos) { //Coste constante
		if (puntosPersona.count(DNI) == 0)throw std::domain_error("Conductor inexistente");
		if (puntos != 0) {
			int puntosAntiguos = puntosPersona[DNI].puntos, puntosNuevos;
			if (puntosAntiguos > puntos) puntosNuevos = puntosAntiguos - puntos;
			else puntosNuevos = 0;

			modificarPuntos(DNI, puntosAntiguos, puntosNuevos);
		}
	}

	void recuperar(std::string const & DNI, int puntos) {//Coste constante
		if (puntosPersona.count(DNI) == 0) throw std::domain_error("Conductor inexistente");
		if (puntos != 0) {

			int puntosAntiguos = puntosPersona[DNI].puntos, puntosNuevos;
			if (puntosAntiguos + puntos < 15) puntosNuevos = puntosAntiguos + puntos;
			else puntosNuevos = 15;

			modificarPuntos(DNI, puntosAntiguos, puntosNuevos);
		}
	}
	int consultar(std::string const & DNI)const { // Coste constante
		if (puntosPersona.count(DNI) == 0)throw std::domain_error("Conductor inexistente");

		return puntosPersona.at(DNI).puntos;
	}

	int cuantos_con_puntos(int puntos)const { //Coste constante
		if (puntos < 0 || puntos > 15)throw std::domain_error("Puntos no validos");

		return personasPorPuntos[puntos].size();
	}

	std::list<std::string> const & lista_por_puntos(int puntos) const {//Coste constante
		if (puntos < 0 || puntos > 15)throw std::domain_error("Puntos no validos");

		return personasPorPuntos[puntos];
	}

};


#endif