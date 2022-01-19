//Marcos Herrero

#ifndef PELICULAS_H
#define PELICULAS_H

#include "horas.h"

class pelicula {
public: pelicula() : titulo(""), horaComienzo(), duracion(), horaFin(){}
	    pelicula(std::string const & titulo, horas const & horaComienzo, horas const & duracion);
		bool operator<(pelicula const & that)const ;
		void read(std::istream & flujo);
		void print(std::ostream & flujo)const;
private: std::string titulo;
	     horas horaComienzo;
		 horas duracion;
		 horas horaFin;
};


#endif