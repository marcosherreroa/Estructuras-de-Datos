//Marcos Herrero

#ifndef ventaLibros_h
#define ventaLibros_h

#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include <unordered_set>
#include <exception>
#include <algorithm>
#include <functional>

using libro = std::string;

struct infoLibros {
	int ejemplares;
	int ventas;
	std::list<libro>::iterator ventasPunt;
};

class ventaLibros {
private:
	std::unordered_map<libro, infoLibros> libros;
	std::map<int, std::list<libro>, std::greater<int>> librosPorVentas;
public:

	void nuevoLibro(int n, libro const & x) { //coste log(N) donde N es el numero de numeros de ventas
		auto it = libros.find(x);
		if (it == libros.end()) {
			auto it2 = &librosPorVentas[0];
			it2->push_front(x);
			libros.insert(it, { x, { n, 0, it2->begin() } });
		}
		else {
			it->second.ejemplares += n;
		}
	}

	void comprar(libro const & x) {// coste log del numero de numeros de ventas
		auto it = libros.find(x);
		if (it == libros.end())throw std::invalid_argument("Libro no existente");
		if (it->second.ejemplares == 0)  throw std::out_of_range("No hay ejemplares");

		std::list<libro>* aux = &librosPorVentas[it->second.ventas];
		aux->erase(it->second.ventasPunt);
		++(it->second.ventas);

		auto aux2 = &librosPorVentas[it->second.ventas];
		aux2->push_front(x);
		it->second.ventasPunt = aux2->begin();
		--it->second.ejemplares;
	}

	bool estaLibro(libro const & x)const {//coste constante
		return libros.count(x) == 1;
	}

	void elimLibro(libro const & x) {//coste log del numero de numeros de ventas
		auto it = libros.find(x);
		if(it != libros.end()){
			auto it2 = it->second.ventasPunt;
			librosPorVentas[it->second.ventas].erase(it2);
			libros.erase(it);
		}
	}

	int numEjemplares(libro const & x)const {//coste constante
		auto it = libros.find(x);
		if (it == libros.end()) throw std::invalid_argument("Libro no existente");
		return it->second.ejemplares;
	}

	std::list<libro> top10()const  {// coste constante
		std::list<libro> lista;

		auto it = librosPorVentas.begin();
		int cont = 0;
		while (cont < 10 && it != librosPorVentas.end() && it->first > 0) {
			auto it2 = it->second.begin();
			
			while (cont < 10 && it2 != it->second.end()) {
				lista.push_back(*it2);
				++cont;
				++it2;
			}
			++it;
		}

		return lista;
	}
};





#endif
