//Marcos Herrero

#include "pelicula.h"
#include <algorithm>

std::istream &operator>>(std::istream & flujo, pelicula & pelicula) {
	pelicula.read(flujo);
	return flujo;
}

std::ostream &operator<<(std::ostream & flujo, pelicula const & pelicula) {
	pelicula.print(flujo);
	return flujo;
}

bool resuelveCaso() {
	int npeliculas;
	std::cin >> npeliculas;
	if (npeliculas == 0) return false;

	std::vector<pelicula> v(npeliculas);
	for (int i = 0; i < npeliculas; ++i) {
		try {
			std::cin >> v[i];
		}
		catch (std::domain_error) {

		}
	}

	std::sort(v.begin(), v.end());
	for (int i = 0; i < npeliculas; ++i)std::cout << v[i];
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	system("PAUSE");
}

