//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <stack>

struct accidente {
	std::string fecha;
	int victimas;
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if(!std::cin) return false;

	std::stack<accidente> pila;
	std::vector<std::string> sol(N);
	accidente acc;
	for (int i = 0; i < N; ++i) {
		std::cin >> acc.fecha >> acc.victimas;

		bool encontrado = false;
		while (!pila.empty() && !encontrado) {
			if (pila.top().victimas > acc.victimas) {
				sol[i] = pila.top().fecha;
				encontrado = true;
			}
			else pila.pop();
		}

		if (!encontrado)sol[i] = "NO HAY";
		pila.push(acc);
	}

	for (int i = 0; i < N; ++i)std::cout << sol[i] << '\n';
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
}