#ifndef autoescuela_h
#define autoescuela_h

#include <unordered_map>
#include <set>
#include <map>
#include <string>
#include <list>

using alumno = std::string;
using profesor = std::string;

struct infoAlumno {
	std::string profesor;
	int puntos;
};

class autoescuela {
private:
	std::unordered_map<alumno, infoAlumno> alumnos;
	std::unordered_map<profesor, std::set<alumno>> alumnosPorProfesor;

public:
	autoescuela(){};

	void alta(alumno const & A, profesor const & P) { // coste log(N1)+log(N2) donde N1 es el numero de alumnos del profAntiguo y N2 el numero de alumno del nuevo
		if (alumnos.count(A) == 0) {
			alumnos[A] = { P, 0 };
			alumnosPorProfesor[P].insert(A); //log
		}
		else {
			profesor profAntiguo = alumnos[A].profesor;
			alumnos[A] = { P, alumnos[A].puntos };//log
			alumnosPorProfesor[profAntiguo].erase(A);// log
			alumnosPorProfesor[P].insert(A);
		}
	}

	bool es_alumno(alumno const & A, profesor const & P)const {//coste constante
		if (alumnos.count(A) == 0)return false;
		return alumnos.at(A).profesor == P;
	}

	int puntuacion(alumno const & A) {//coste constante
		if (alumnos.count(A) == 0)throw std::domain_error("El alumno " + A + " no esta matriculado.");
		return alumnos[A].puntos;
	}

	void actualizar(alumno const & A, int N) {//coste constante
		if(alumnos.count(A) == 0)throw std::domain_error("El alumno " + A + " no esta matriculado.");
		alumnos[A].puntos += N;
	}

	std::list<alumno> examen(profesor const & P, int N)const {//coste lineal con respecto al numero de alumnos del profesor P
		std::list<alumno> lista;

		if (alumnosPorProfesor.count(P) == 1) {
			std::set<alumno>::iterator it = alumnosPorProfesor.at(P).begin();
			std::set<alumno>::iterator end = alumnosPorProfesor.at(P).end();

			while (it != end) { // lineal
				if (alumnos.at(*it).puntos >= N)lista.push_back(*it);
				++it;
			}

		}
		return lista;
	}


	void aprobar(alumno const & A) {//coste log(N) donde N es el numero de alumnos con el mismo profesor que A
		if (alumnos.count(A) == 0)throw std::domain_error("El alumno " + A + " no esta matriculado.");

		profesor p = alumnos[A].profesor;
		alumnosPorProfesor[p].erase(A); // log
		alumnos.erase(A);
	}
};



#endif