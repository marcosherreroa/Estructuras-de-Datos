
#include <iostream>
#include <vector>
#include<algorithm>
#include <stack>


struct intervalo {
	long int ini;
	long int fin;
};

bool medianos(std::vector<long int> const & v, int N) {
	std::stack<int> medianos; int mm = -1; bool encontrado = false;

	for (int i = v.size() - 1; !encontrado && i >= 0; --i) {
		while (!medianos.empty() && v[i] > medianos.top()) {
			mm = medianos.top();
			medianos.pop();
		}

		if (v[i] > mm) medianos.push(v[i]);
		else if (v[i] < mm)encontrado = true;
	}

	if (!encontrado)return false;
	else return true;
}

bool encontrado(std::vector<long int> const & v, int N) {
	std::stack<intervalo> intervalos;

	bool OK = false;
	int minl = v[0];
	int maxr = v[1];

	for (int i = 2; !OK && i < N; ++i) {
		if (v[i - 1] < minl) {
			if (minl < maxr) intervalos.push({ minl,maxr });
			minl = v[i - 1];
			maxr = v[i];
		}

		else if (v[i] > maxr) maxr = v[i];

		if (v[i] > minl && v[i] < maxr) OK = true;
		else if (intervalos.size() > 0) {
			int iniMejor = intervalos.top().ini, finMejor = intervalos.top().fin;
			for (int j = 0; !OK && j < intervalos.size() && intervalos.top().ini < v[i]; ++j) {
				if (intervalos.top().fin > v[i]) OK = true;
				else {
					if (intervalos.top().fin > finMejor)finMejor = intervalos.top().fin;
					intervalos.pop();
				}
			}

			intervalos.push({ iniMejor, finMejor });
		}
	}

	return OK;
}


bool resuelveCaso() {
	long int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<long int> v(N);

	for (long int i = 0; i < N; ++i) std::cin >> v[i];

	if (medianos(v, N)) std::cout << "ELEGIR OTRA\n";
	else std::cout << "SIEMPRE PREMIO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}