//Marcos Herrero

#include <iostream>
#include <string>
#include <stack>
#include <deque>

bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void volcarPila(std::stack<char> & pila, std::string & sol) {
	while (!pila.empty()) {
		sol.push_back(pila.top());
		pila.pop();
	}
}

void revertir1(std::deque<char> & dq, std::string & sol) {
	std::stack<char> pilaConsonantes;

	int n = dq.size();
	for (int i = 0;  i < n; ++i) {
		if (isvowel(dq.front())) {
			volcarPila(pilaConsonantes, sol);
			sol.push_back(dq.front());
			dq.pop_front();
		}
		else {
			pilaConsonantes.push(dq.front());
			dq.pop_front();
		}
	}

	volcarPila(pilaConsonantes, sol);
}

void revertir2(std::string const & linea, std::deque<char> & sol ) {
	for (int i = linea.length()-1; i >= 0 ; --i) {
		if (i % 2 == 0)sol.push_front(linea[i]);
		else sol.push_back(linea[i]);
   }
}
bool resuelveCaso() {
	std::string linea;
	getline(std::cin, linea);

	if (!std::cin)return false;

	std::deque<char> sol1; std::string sol2;
	revertir2(linea, sol1);
	revertir1(sol1, sol2);

	for (int i = 0; i < sol2.length(); ++i)std::cout << sol2[i];
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}
