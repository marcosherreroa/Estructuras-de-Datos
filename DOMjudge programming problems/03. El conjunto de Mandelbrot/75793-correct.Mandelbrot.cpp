//Marcos Herrero

#include "complejo.h"

void resuelveCaso(){
	float a, b; int n;
	std::cin >> a >> b >> n;

	complejo<float> c(a, b), z(0, 0);
	for (int i = 0; z.modulo() <= 2.0 && i < n; ++i) z = z * z + c;
	
	if (z.modulo() <= 2.0)std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
	return 0;
}