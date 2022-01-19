//Marcos Herrero
#include <iostream>
#include <vector>
#include <deque>


bool resuelveCaso() {
	int N, k;
	std::cin >> N >> k;

	if (N == 0 && k == 0) return false;

	std::vector<int> sobres(N);
	for (int i = 0; i < N; ++i)std::cin >> sobres[i];

	std::deque<int> indMaximos; // se mantienen los elementos de la ventana mayores de todos los de sus derecha
	for (int i = 0; i < k; ++i) {

		while (!indMaximos.empty() && sobres[i] > sobres[indMaximos.back()]) indMaximos.pop_back();
		indMaximos.push_back(i);
	}

	std::cout << sobres[indMaximos.front()];
	for (int i = k; i < N; ++i) {
		if (indMaximos.front() < i - k+1) indMaximos.pop_front();

		while (!indMaximos.empty() && sobres[i] > sobres[indMaximos.back()]) indMaximos.pop_back();
		indMaximos.push_back(i);

		std::cout << ' ' <<sobres[indMaximos.front()];
	}

	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}