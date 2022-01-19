//Marcos Herrero
#include <iostream>
#include "extendedDeque.h"

void resuelveCaso() {
	int N;
	std::cin >> N;

	extendedDeque<int> princ, sec; int el;
	for (int i = 0; i < N; ++i) {
		std::cin >> el;
		princ.push_back(el);
	}

	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i){
		std::cin >> el;
		sec.push_back(el);
	}

	princ.entremezclar(sec);
	princ.mostrar();
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}
