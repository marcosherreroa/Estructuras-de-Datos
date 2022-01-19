#ifndef consultorio_h
#define consultorio_h

#include "fecha.h"
#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <algorithm>

using medico = std::string;
using paciente = std::string;

class horaMinuto {
public:
	int hora;
	int minuto;

	bool operator<(horaMinuto const &that)const {
		if (this->hora < that.hora)return true;
		else if (this->hora == that.hora && this->minuto < that.minuto)return true;
		return false;
	}

};

struct pacienteHora {
	horaMinuto HM;
	paciente p;
};

class consultorio {
private:
 
	std::unordered_map<medico, std::map<int, std::map<horaMinuto, paciente>>> pacientesPorMedico;

public:
	void nuevoMedico(medico const & m) { //coste constante
		auto it = pacientesPorMedico.find(m);
		if (it == pacientesPorMedico.end()) {
			std::map<int, std::map<horaMinuto, paciente>> aux;
			pacientesPorMedico.insert(it, { m, aux });
		}
		
	}

	void pideConsulta(paciente const & p, medico const & m, fecha const & f) { //coste log(D)+log(H)= max{log(D), log(H)} (siendo D el numero de elementos del map de dias y H el del map de HorasMinutos al que accedemos)
		if (pacientesPorMedico.count(m) == 0) throw std::domain_error("Medico no existente");
		if (pacientesPorMedico[m].count(f.getDia()) == 1 && 
			pacientesPorMedico[m][f.getDia()].count({ f.getHora(), f.getMinuto()})== 1) throw std::domain_error("Fecha ocupada");

		pacientesPorMedico[m][f.getDia()][{f.getHora(), f.getMinuto()}] = p;
	}

	paciente const & siguientePaciente(medico const & m) const {//coste contante
		if (pacientesPorMedico.count(m) == 0) throw std::domain_error("Medico no existente");
		if (pacientesPorMedico.at(m).size() == 0) throw std::domain_error("No hay pacientes");

		return pacientesPorMedico.at(m).begin()->second.begin()->second;
	}

	void atiendeConsulta(medico const & m) {// coste constante
		if (pacientesPorMedico.count(m) == 0) throw std::domain_error("Medico no existente");
		if (pacientesPorMedico[m].size() == 0) throw std::domain_error("No hay pacientes");

		int dia = pacientesPorMedico[m].begin()->first;
		pacientesPorMedico[m].begin()->second.erase(pacientesPorMedico[m].begin()->second.begin());
		if (pacientesPorMedico[m][dia].size() == 0)pacientesPorMedico[m].erase(dia);
	}

	std::list<pacienteHora> listaPacientes(medico const & m, int d)const {//coste H + log(D)
		if (pacientesPorMedico.count(m) == 0) throw std::domain_error("Medico no existente");

		std::list<pacienteHora> lista;
		if (pacientesPorMedico.at(m).count(d) == 1) { 
			auto it = pacientesPorMedico.at(m).at(d).begin();
			auto end = pacientesPorMedico.at(m).at(d).end();
			while (it != end) {
				lista.push_back({ it->first, it->second });
				++it;
			}
		}

		return lista;
	}

};


#endif