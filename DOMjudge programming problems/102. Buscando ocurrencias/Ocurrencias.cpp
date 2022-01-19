//Marcos Herrero
#include <iostream>
#include <vector>
#include <unordered_map>

bool resuelveCaso() {
	int N, M;
	std::cin >> N>>M;

	if (!std::cin)return false;

	std::unordered_map<int, std::vector<int>> map;
	int num;
	for (int i = 0; i < N; ++i) {
		std::cin >> num;
		map[num].push_back(i+1);
	}

	int k, v;
	std::vector<int> sol(M);
	for (int i = 0; i < M; ++i) {
		std::cin >> k >> v;
		std::vector<int> & u = map[v];
		if (u.size() > k-1)sol[i] = u[k-1];
		else sol[i] = -1;
	}

	for (int i = 0; i < M; ++i) {
		if (sol[i] == -1)std::cout << "NO HAY\n";
		else std::cout << sol[i] << '\n';
	}

	std::cout << "---\n";
	return true;
}


int main() {
	while (resuelveCaso());
}