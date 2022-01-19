//Marcos Herrero
#include <iostream>
#include <queue>
#include <stack>

void reordenar(std::queue<int> & cola) {
	std::stack<int> negativos; int N = cola.size();

	for (int i = 0; i < N; ++i) {
		if (cola.front() >= 0) cola.push(cola.front());
		else negativos.push(cola.front());
		cola.pop();
	}
    
	if (!negativos.empty()) {
		while (!negativos.empty()) {
			cola.push(negativos.top());
			negativos.pop();
		}

		while (cola.front() >= 0) {
			cola.push(cola.front());
			cola.pop();
		}
	}

}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::queue<int> cola; int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		cola.push(aux);
	}

	reordenar(cola);

	while (!cola.empty()) {
		std::cout << cola.front() << ' ';
		cola.pop();
	}

	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}