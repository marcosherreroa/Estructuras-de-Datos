//Marcos Herrero
#ifndef TIENDA
#define TIENDA
#include "fecha.h"
#include <string>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>

struct unidades {
	int unids;
	std::map<fecha, int> porFecha;
};

struct vendido {
	bool vendido;
	fecha f;
};

class tienda {
public:
	std::unordered_map<std::string, unidades> existencias;
	std::unordered_map<std::string, std::queue<std::string>> solic;

	std::list<std::string> adquirir(std::string const & cod, fecha const & fecha, int cant) {
		std::queue<std::string> & cola = solic[cod];
		std::list<std::string> servidos;
		while (!cola.empty() && cant > 0) {
			servidos.push_back(cola.front());
			cola.pop();
			--cant;
		}
        
		if (cant > 0) {
			existencias[cod].unids += cant;
			existencias[cod].porFecha[fecha] += cant;
		}
		return servidos;
   }

	vendido vender(std::string const & cod, std::string const & cli) {
		auto & prod = existencias[cod];
		auto it = prod.porFecha.begin();
		if (it != prod.porFecha.end()){
			--it->second;
			--prod.unids;
			fecha f = it->first;
			if (it->second == 0)prod.porFecha.erase(it);
			return { true, f };
		}

		else {
			solic[cod].push(cli);
			fecha f;
			return { false, f };
		}
	}

	int cuantos(std::string const & cod)const {
		if (existencias.count(cod) == 0)return 0;
		else return existencias.at(cod).unids;
	}
	
	bool hay_esperando(std::string const & cod)const  {
		return solic.count(cod) == 1 && !solic.at(cod).empty();
	}

};


#endif