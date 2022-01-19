//Marcos Herrero
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

bool operator<(std::pair<std::string, int> const & a, std::pair<std::string, int> const & b) {
	if (a.second > b.second) return true;
	else if (a.second == b.second && a.first < b.first) return true;
	else return false;
}

struct Comp{
	bool operator()(std::pair<std::string, int> const & a, std::pair<std::string, int> const & b) {
		if (a.second > b.second) return true;
		else if (a.second == b.second && a.first < b.first) return true;
		else return false;
	}
};

bool resuelveCaso() {
	std::string palabra;
	getline(std::cin, palabra);
	if (!std::cin)return false;

	std::unordered_map<std::string, std::string> alumnos;
	std::unordered_map<std::string, int> deportes;
	std::string deporte, alumno;

	while (palabra != "_FIN_") {
		deporte = palabra;
		deportes[deporte] = 0;

		getline(std::cin, palabra);
		while (islower(palabra[0])) {
			alumno = palabra;
			if (alumnos.count(alumno) == 0) alumnos[alumno] = deporte;
			else if (alumnos[alumno] != deporte) alumnos[alumno] = "0";
			getline(std::cin, palabra);
		}
	}
	
	auto it= alumnos.begin();
	while (it != alumnos.end()) {
		if(deportes.count(it->second) == 1)++deportes[it->second];
		++it;
	}

	auto it2 = deportes.begin();
	std::vector<std::pair<std::string, int>> v;
	while (it2 != deportes.end()) {
		v.push_back(*it2);
		++it2;
	}

	std::sort(v.begin(), v.end(), Comp());
	for (int i = 0; i < v.size(); ++i) std::cout << v[i].first << ' ' << v[i].second << '\n';
	
	std::cout << "***\n";
	return true;
}

int main() {
	while (resuelveCaso());
}