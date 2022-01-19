//Marcos Herrero

#include "autoescuela.h"
#include <iostream>

bool resuelveCaso() {
	std::string op;
	std::cin >> op;
	if (!std::cin)return false;

	autoescuela aut;

	while (op != "FIN") {

		try {
			if (op == "alta") {
				alumno A; profesor P;
				std::cin >> A >> P;
				aut.alta(A, P);
			}
			else if (op == "es_alumno") {
				alumno A; profesor P;
				std::cin >> A >> P;
				if (aut.es_alumno(A, P)) std::cout << A << " es alumno de " << P << '\n';
				else std::cout << A << " no es alumno de " << P << '\n';
			}

			else if (op == "puntuacion") {
				alumno A;
				std::cin >> A;
				std::cout << "Puntuacion de " << A << ": " << aut.puntuacion(A) << '\n';
			}

			else if (op == "actualizar") {
				alumno A; int N;
				std::cin >> A >> N;
				aut.actualizar(A, N);
			}

			else if (op == "examen") {
				profesor P; int N;
				std::cin >> P >> N;
				std::list<alumno> lista = aut.examen(P, N);
				std::cout << "Alumnos de " << P << " a examen:\n";

				std::list<alumno>::iterator it = lista.begin();
				while (it != lista.end()) {
					std::cout << *it<<'\n';
					++it;
				}
			}

			else if (op == "aprobar") {
				alumno A;
				std::cin >> A;
				aut.aprobar(A);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}

		std::cin >> op;
	}

	std::cout << "------\n";
	return true;
}

int main() {
	while (resuelveCaso());
}