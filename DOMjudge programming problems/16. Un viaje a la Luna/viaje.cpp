//Marcos Herrero

#include "persona.h"
#include "listaFiltro.h"


std::istream & operator>>(std::istream & flujo, Persona & p ) {
	p.leer(flujo);
	return flujo;
}

std::ostream & operator<<(std::ostream & flujo, Persona const & p) {
	p.mostrar(flujo);
	return flujo;
}

class pred {
private:
	int min;
	int max;

public:
	pred(int min_, int max_) {
		min = min_;
		max = max_;
	}

	bool operator()(Persona const & p) {
		return p.consultarEdad() < min || p.consultarEdad()> max;
	}
};

bool resuelveCaso() {
	int N, min, max;

	std::cin >> N >> min >> max;
	if (N == 0 && min == 0 && max == 0) return false;

	listaFiltro<Persona> lista; Persona aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		lista.push_back(aux);
	}

	lista.remove_if(
		pred(min, max)
		/*[min, max](Persona const & p){
		return p.consultarEdad()< min || p.consultarEdad() > max;*/
	);

	for (list<Persona>::iterator it = lista.begin(); it != lista.end(); ++it) {
		std::cout << *it<<'\n';
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
}