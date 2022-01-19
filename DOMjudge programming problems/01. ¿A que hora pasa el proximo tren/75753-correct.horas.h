//Marcos Herrero

#ifndef HORAS_H
#define HORAS_H

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

class horas {
public:
	horas() {};
	horas(int hora, int minuto, int segundo);
	bool horaValida(int hora, int minuto, int segundo);
	bool operator<(horas const & that) const;
	void read(std::istream & flujo);
	void print(std::ostream & flujo)const;
private:
	int hora;
	int minuto;
	int segundo;

};



#endif