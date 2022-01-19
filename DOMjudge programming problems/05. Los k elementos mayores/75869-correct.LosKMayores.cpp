//Marcos Herrero


#include "set.h"

template<typename T>
void mostrar(set<T> & conj){
	while(!conj.empty()) {
		std::cout << conj.getMenor() << ' ';
		conj.eraseMenor();
	}
	std::cout << '\n';
}

template<typename T>
void add(set<T> & conj, T const & e, int k) {
	if (conj.size() < k)conj.insert(e);
	else if (!conj.contains(e) && conj.getMenor() < e) {
		conj.eraseMenor();
		conj.insert(e);
	}
}

bool resuelveCaso() {
	char opt;
	std::cin >> opt;
	if (!std::cin)return false;

	int k;
	std::cin >> k;
	if (opt == 'N') {
		set<float> conj(k);
		float num; int pos = 0;
		std::cin >> num;
		while (num != -1) {
			add(conj, num, k);
			std::cin >> num;
		}

		mostrar(conj);
	}

	else if (opt == 'P') {
		set<std::string> conj(k);

		std::string s;
		std::cin >> s;
		while (s != "FIN") {
			add(conj, s, k);
			std::cin >> s;
		}

		mostrar(conj);
	}

	
	return true;
}

int main() {
	while (resuelveCaso());
}