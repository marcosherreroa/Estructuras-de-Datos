//Marcos Herrero

#include <iostream>

int alturaArbol(int N) {
	if (N == 0)return 1;
	else {
		int cinf = 1, max, n;

		for (int i = 0; i < N; ++i) {
			std::cin >> n;
			max = alturaArbol(n);
			if (max > cinf)cinf = max;
		}
		
		return 1+cinf;
	}
}

void resuelveCaso() {
	int nhijos;
	std::cin >> nhijos;
	std::cout << alturaArbol(nhijos)<<'\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}