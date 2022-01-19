//Marcos Herrero

#include <iostream>
#include <string>
#include <stack>

bool resuelveCaso() {
	std::string frase;
	getline(std::cin, frase);
	if (!std::cin)return false;

	std::stack<char> llaves;
	bool equilibrado = true;
	for (int i = 0; equilibrado && i < frase.size(); ++i) {
		if (frase[i] == '(' || frase[i] == '{' || frase[i] == '[') llaves.push(frase[i]);
		else if (frase[i] == ')') {
			if (llaves.empty() || llaves.top() != '(') equilibrado = false;
			else llaves.pop();
		}
		else if (frase[i] == '}') {
			if (llaves.empty() || llaves.top() != '{') equilibrado = false;
			else llaves.pop();
		}
		else if (frase[i] == ']') {
			if (llaves.empty() || llaves.top() != '[')equilibrado = false;
			else llaves.pop();
		}
	}

	if (!llaves.empty()) equilibrado = false;


	if (equilibrado) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
}