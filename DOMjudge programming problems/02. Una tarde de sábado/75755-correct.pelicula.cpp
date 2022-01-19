//Marcos Herrero

#include "pelicula.h"

pelicula::pelicula(std::string const & titulo, horas const & horaComienzo, horas const & duracion) {
	this->titulo = titulo;
	this->horaComienzo = horaComienzo;
	this->duracion = duracion;
	this->horaFin = horaComienzo + duracion;
}

bool pelicula::operator<(pelicula const & that)const {
	if (horaFin < that.horaFin) return true;
	else if (horaFin == that.horaFin && titulo < that.titulo) return true;
	else return false;
}

void pelicula::read(std::istream & flujo) {
	horaComienzo.read(flujo);
	duracion.read(flujo);
	getline(flujo,titulo);
	horaFin = horaComienzo + duracion;
}

void pelicula::print(std::ostream & flujo)const {
	horaFin.print(flujo);
	flujo << titulo << '\n';
}