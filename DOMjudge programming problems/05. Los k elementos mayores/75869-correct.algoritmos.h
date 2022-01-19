//Marcos Herrero

template<typename T>
bool binarySearch(T* v, T buscado, int ini, int fin, int & pos) {
	if (ini == fin) {
		pos = ini;
		return false;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (buscado < v[m]) return binarySearch(v, buscado, ini, m, pos);
		else if (v[m] < buscado) return binarySearch(v, buscado, m + 1, fin, pos);
		else {
			pos = m;
			return true;
		}
	}
}
