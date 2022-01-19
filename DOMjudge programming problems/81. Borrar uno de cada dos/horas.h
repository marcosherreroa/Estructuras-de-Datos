//Marcos Herrero

#ifndef HORAS_H
#define HORAS_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <iomanip>

class horas {
private:
	int hora;
	int minuto;
	int segundo;

public:
	horas() {};

	horas(int hora, int minuto, int segundo) {
		if (!horaValida(hora, minuto, segundo)) {
			throw std::invalid_argument("la hora introducida no es correcta");
		}
		else {
			this->hora = hora;
			this->minuto = minuto;
			this->segundo = segundo;
		}
	};

	bool horaValida(int hora, int minuto, int segundo) {
		return hora >= 0 && hora < 24 && minuto >= 0 && minuto < 60 && segundo >= 0 && segundo < 60;
	};
	bool operator<(horas const & that) const {
		if (hora < that.hora) return true;
		else if (hora == that.hora && minuto < that.minuto) return true;
		else if (hora == that.hora && minuto == that.minuto && segundo < that.segundo) return true;
		else return false;
	};

	void read(std::istream & flujo) {
		int hora0, minuto0, segundo0;
		flujo >> hora0;
		flujo.ignore(1);
		flujo >> minuto0;
		flujo.ignore(1);
		flujo >> segundo0;

		if (!horaValida(hora0, minuto0, segundo0))throw std::domain_error("la hora introducida no es correcta");
		else {
			hora = hora0;
			minuto = minuto0;
			segundo = segundo0;
		}
	};

	void print(std::ostream & flujo)const {
		flujo << std::setfill('0') << std::setw(2) << hora << ':' << std::setw(2) << minuto << ':' << std::setw(2) << segundo;
	};

};

std::istream & operator>>(std::istream & flujo, horas & h) {
	h.read(flujo);
	return flujo;
}

std::ostream & operator<<(std::ostream & flujo, horas const & h) {
	h.print(flujo);
	return flujo;
}

#endif