//Marcos Herrero

#include <iostream>

int becariosPrecarios(int N, int minjefes) {
	if (N == 0) return  minjefes <= 0;
	else {
		int n, suma = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> n;
			suma += becariosPrecarios(n, minjefes - 1);
		}

		return suma;
	}
}

bool resuelveCaso() {
	int minjefes;
	std::cin >> minjefes;
	if (!std::cin)return false;

	int N;
	std::cin >> N;
	std::cout << becariosPrecarios(N, minjefes) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}