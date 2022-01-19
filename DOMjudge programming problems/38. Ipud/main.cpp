//Marcos Herrero
#include "ipud.h"
#include <iostream>

bool resuelveCaso() {
	ipud ipud;

	std::string op;
	std::cin >> op;
	if (!std::cin)return false;

	while (op != "FIN") {
		try {
			if (op == "addSong") {
				cancion S; artista A; duracion D;
				std::cin >> S >> A >> D;
				ipud.addSong(S, A, D);
			}

			else if (op == "addToPlaylist") {
				cancion S;
				std::cin >> S;
				ipud.addToPlaylist(S);
			}

			else if (op == "current") {
				ipud.current();
				//std::cout << ipud.current() << '\n';
			}

			else if (op == "play") {
				try {
					std::cout << "Sonando " << ipud.current() << '\n';
					ipud.play();
				}
				catch (std::domain_error const & e) {
					std::cout << "No hay canciones en la lista\n";
				}
			}

			else if (op == "totalTime") {
				std::cout << "Tiempo total " << ipud.totalTime() << '\n';
			}

			else if (op == "recent") {
				int N;
				std::cin >> N;
				std::list<cancion> lista = ipud.recent(N);

				if (lista.size() == 0)std::cout << "No hay canciones recientes\n";
				else {
					std::cout << "Las " << lista.size() << " mas recientes\n";
					auto it = lista.begin();
					while (it != lista.end()) {
						std::cout << "    " << *it << '\n';
						++it;
					}
				}
			}

			else if (op == "deleteSong") {
				cancion s;
				std::cin >> s;
				ipud.deleteSong(s);
			}
		}
		catch (std::domain_error const & e) {
			std::cout << "ERROR " << e.what()<<'\n';
		}

		std::cin >>op;
	}

	std::cout << "----\n";
	return true;
}

int main() {
	while (resuelveCaso());
}