//Marcos Herrero

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
private:
	std::string nombre;
	int edad;

public:
	std::string const & consultarNombre()const {
		return nombre;
	}

	int consultarEdad()const {
		return edad;
	}

	void leer(std::istream & flujo) {
		flujo >> edad;
		flujo.ignore(1);
		getline(flujo, nombre);
	}

	void mostrar(std::ostream & flujo)const {
		flujo << nombre;
	}

};


#endif