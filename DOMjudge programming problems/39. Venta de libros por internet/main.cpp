//Marcos Herrero

#include "ventaLibros.h"
#include <iostream>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;

	ventaLibros v; std::string op;
	for (int i = 0; i < n; ++i) {
		std::cin >> op;
		std::cin.ignore(1);
		try {
			if (op == "nuevoLibro") {
				int n; libro x;
				std::cin >> n;
				std::cin.ignore(1);
				getline(std::cin,x);
				v.nuevoLibro(n, x);
			}
			else if (op == "comprar") {
				libro x;
				getline(std::cin,x);
				v.comprar(x);
			}
			else if (op == "estaLibro") {
				libro x;
				getline(std::cin,x);
				if (v.estaLibro(x))std::cout << "El libro " << x << " esta en el sistema\n";
				else std::cout << "No existe el libro " << x << " en el sistema\n";
				std::cout << "---\n";
			}
			else if (op == "elimLibro") {
				libro x;
				getline(std::cin, x);
				v.elimLibro(x);
			}
			else if (op == "numEjemplares") {
				libro x;
				getline(std::cin, x);
				try {
					std::cout << "Existen " << v.numEjemplares(x) << " ejemplares del libro " << x << '\n';
					std::cout << "---\n";
				}
				catch (std::invalid_argument e) {
					std::cout << "No existe el libro " << x << " en el sistema\n";
					std::cout << "---\n";
				}
			}

			else if (op == "top10") {
				std::list<libro> lista = v.top10();

				auto it = lista.begin();
				while (it != lista.end()) {
					std::cout << *it << '\n';
					++it;
				}
				std::cout << "---\n";
			}
		}
		catch (std::exception const & e) {
			std::cout << e.what() << '\n';
			std::cout << "---\n";
		}

		
	}

	std::cout << "------\n";
	return true;
}

int main() {
	while (resuelveCaso());
}