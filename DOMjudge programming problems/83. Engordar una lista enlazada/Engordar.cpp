//Marcos Herrero

#include "ExtendedDeque.h"

void resuelveCaso() {
	ExtendedDeque<int> princ, sec;
	int aux;

	int N, M;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		princ.push_back(aux);
	}
	std::cin >> M;
	for (int i = 0; i < M; ++i) {
		std::cin >> aux;
		sec.push_back(aux);
	}

	princ.engordar(sec);

	while (!princ.empty()) {
		std::cout << princ.front()<<' ';
		princ.pop_front();
	}

	std::cout << '\n';
}

int main(){
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}