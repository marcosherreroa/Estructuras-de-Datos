//Marcos Herrero
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

void resuelveCaso() {
	std::string linea; std::stringstream ss;
	getline(std::cin, linea);
	ss << linea;

	std::map<std::string, int> antiguo;
	std::string key; int value;
	while (ss >> key) {
		ss >> value;
		antiguo[key] = value;
	}

	getline(std::cin, linea);
	ss.clear();
	ss.str("");
	ss << linea;

	std::map<std::string, int> nuevo;
	while (ss >> key) {
		ss >> value;
		nuevo[key] = value;
	}

	std::map<std::string, int>::iterator i = antiguo.begin(), j = nuevo.begin();
	std::vector<std::string> added, erased, modified;

	while (i != antiguo.end() && j != nuevo.end()) {
		if (i->first < j->first) {
			erased.push_back(i->first);
			++i;
		}
		else if (j->first < i->first) {
			added.push_back(j->first);
			++j;
		}

		else if (i->second != j->second) {
			modified.push_back(i->first);
			++i;
			++j;
		}
		else {
			++i;
			++j;
		}
	}

	while (i != antiguo.end()) {
		erased.push_back(i->first);
		++i;
	}

	while (j != nuevo.end()) {
		added.push_back(j->first);
		++j;
	}

	if (added.size() == 0 && erased.size() == 0 && modified.size() == 0)std::cout << "Sin cambios\n";
	else {
		if (added.size() > 0) {
			std::cout << '+';
			for (int i = 0; i < added.size(); ++i) {
				std::cout << ' ' << added[i];
			}
			std::cout << '\n';
		}

		if (erased.size() > 0) {
			std::cout << '-';
			for (int i = 0; i < erased.size(); ++i) {
				std::cout << ' ' << erased[i];
			}
			std::cout << '\n';
		}

		if (modified.size() > 0) {
			std::cout << '*';
			for (int i = 0; i < modified.size(); ++i) {
				std::cout << ' ' << modified[i];
			}
			std::cout << '\n';
		}
	}

	std::cout << "----\n";
}

int main() {
	int n;
	std::cin >> n;
	std::cin.ignore(1);
	for (int i = 0; i < n; ++i)resuelveCaso();
}