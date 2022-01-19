//Marcos Herrero

#include "horas.h"

horas::horas(int hora, int minuto, int segundo) {
	if (!horaValida( hora, minuto,  segundo)) {
		throw std::domain_error("la hora introducida no es correcta");
	}
	else {
		this->hora = hora;
		this->minuto = minuto;
		this->segundo = segundo;
	}
}

bool horas::horaValida(int hora, int minuto, int segundo) {
	return hora >= 0 && hora < 24 && minuto >= 0 && minuto < 60 && segundo >= 0 && segundo < 60;
}

bool horas::operator<(horas const & that)const {
	if (hora < that.hora) return true;
	else if (hora == that.hora && minuto < that.minuto) return true;
	else if (hora == that.hora && minuto == that.minuto && segundo < that.segundo) return true;
	else return false;
}

bool horas::operator==(horas const & that)const {
	return hora == that.hora && minuto == that.minuto && segundo == that.segundo;
}

horas horas::operator+(horas const & that) const {
	int secAux = segundo + that.segundo;
	int minAux = minuto + that.minuto;
	int horaAux = hora + that.hora;

	if (secAux >= 60) {
		secAux -= 60;
		++minAux;
	}

	if (minAux >= 60) {
		minAux -= 60;
		++horaAux;
	}


		horas suma(horaAux, minAux, secAux); // si se sale del día, lanza excepción 
		return suma;
}

void horas::read(std::istream & flujo) {
	int hora0, minuto0, segundo0;
	flujo >> hora0;
	flujo.ignore(1);
	flujo >> minuto0;
	flujo.ignore(1);
	flujo >> segundo0;

	if (!horaValida(hora0,minuto0,segundo0))throw std::domain_error("la hora introducida no es correcta");
	else{
		hora = hora0;
		minuto = minuto0;
		segundo = segundo0;
	}
}

void horas::print(std::ostream & flujo) const {
	flujo <<std::setfill('0')<<std::setw(2)<<hora << ':' <<std::setw(2)<< minuto << ':' <<std::setw(2)<< segundo;
}