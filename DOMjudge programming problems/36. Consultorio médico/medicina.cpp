//Marcos Herrero

#include "consultorio.h"
#include <iostream>
#include <iomanip>

std::istream & operator>>(std::istream & flujo, fecha & f) {
	int dia, hora, min;
	flujo >> dia >> hora >> min;
	f.setDia(dia);
	f.setHora(hora);
	f.setMinuto(min);
	return flujo;
}

std::ostream & operator<<(std::ostream & flujo, horaMinuto const & HM) {
	flujo <<std::setfill('0')<< std::setw(2) << HM.hora <<':'<< std::setw(2) << HM.minuto;
	return flujo;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;

	consultorio consult;
	for (int i = 0; i < N; ++i) {
		std::string op;
		std::cin >> op;

		try {
			if (op == "nuevoMedico") {
				medico m;
				std::cin >> m;
				consult.nuevoMedico(m);
			}
			else if (op == "pideConsulta") {
				medico m; paciente p; fecha f;
				std::cin >> p >> m >> f;
				consult.pideConsulta(p, m, f);
			}

			else if (op == "siguientePaciente") {
				medico m;
				std::cin >> m;
				std::cout << "Siguiente paciente doctor "<<m <<'\n'<< consult.siguientePaciente(m) << '\n';
				std::cout << "---\n";
			}

			else if (op == "atiendeConsulta") {
				medico m;
				std::cin >> m;
				consult.atiendeConsulta(m);
			}

			else if (op == "listaPacientes") {
				medico m; int d;
				std::cin >> m >> d;
				std::list<pacienteHora> lista = consult.listaPacientes(m, d);
				std::cout << "Doctor " << m << " dia " << d << '\n';

				std::list<pacienteHora>::iterator it = lista.begin();
				while (it != lista.end()) {
					std::cout << it->p <<' '<< it->HM << '\n';
					++it;
				}

				std::cout << "---\n";
			}

		}
		catch (std::domain_error const & e) {
			std::cout << e.what()<<'\n';
			std::cout << "---\n";
		}
	}
	
	std::cout << "------\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}