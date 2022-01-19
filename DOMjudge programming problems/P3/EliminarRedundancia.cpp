//Marcos Herrero

#include <iostream>
#include <vector>
#include <unordered_map>


bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin) return false;

	std::unordered_map<int, int> map; std::vector<int> orden;
	int num;
	for (int i = 0; i < N; ++i) {
		std::cin >> num;
		auto it = map.find(num);

		if (it != map.end()) ++it->second;
		else {
			map.insert({ num, 1 });
			orden.push_back(num);
		}
	}

	for (int i = 0; i < orden.size(); ++i) {
		std::cout << orden[i] << ' ' << map[orden[i]]<<'\n';
	}

	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
}