//Marcos Herrero

#include <iostream>
#include <unordered_map>
#include <queue>


void resuelveCaso() {
	int N;
	std::cin >> N;
	
	std::unordered_map<int, int> secuencia; // 1 capitulo 2 indice donde fue visto
	std::queue<int> secinds; int aux;
	std::cin >> aux;
	secuencia[aux] = 0;
	secinds.push(aux);
	
	int r = 1, s = 1; // r longitud de la secuencia más larga encontrada
					  // s longitud de la secuencia más larga que acab en i

	for (int i = 1; i < N; ++i) {
		std::cin >> aux;
		
		if (secuencia.count(aux) == 1) {
			if (s > r) r = s;
			s = i- secuencia[aux];
			while (secinds.front() !=aux) {
				secuencia.erase(secinds.front());
				secinds.pop();
			}
			secuencia.erase(aux);
			secinds.pop();
		}
		else ++s;

		secuencia[aux] = i;
		secinds.push(aux);
	}

	if (s > r)r = s;

	std::cout << r << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}