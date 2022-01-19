//Marcos Herrero

#include <queue>
#include <iostream>
#include <vector>

struct pares {
	int j;
	int cont;
};

bool operator<(pares const & p1, pares const & p2) {
	return p1.cont > p2.cont;
}

bool resuelveCaso() {
	int R;
	std::cin >> R;

	if (!std::cin)return false;


	std::vector<int> clave(R);
	for (int i = 0; i < R; ++i) std::cin >> clave[i];


	int N;
	std::cin >> N;

	std::queue<pares> jconts; int n;
	int min = N, digito; pares aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> digito;

		n = jconts.size();
		for (int k = 0; k < n; ++k) {
			aux = jconts.front();
			jconts.pop();
			if (digito == clave[aux.j]) {
				++aux.j;
				++aux.cont;
				if (aux.j == R && aux.cont < min) min = aux.cont;
			}

			else ++aux.cont;

			if (aux.j != R && aux.cont < min && (jconts.empty() || k == n-1 || jconts.front().j < aux.j )) jconts.push(aux);
		}

		if (digito == clave[0])jconts.push({ 1,1 });
	}
		

	std::cout << min << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}