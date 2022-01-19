//Marcos Herrero

#include "polinomio.h"

bool buscBinRec(std::vector<monomio> const & v, int expBuscado, int ini, int fin, int & pos) {
	if (ini == fin) {
		pos = ini;
		return false;
	}
	else {
		int m = (ini + fin - 1) / 2;

		if (expBuscado == v[m].exp) {
			pos = m;
			return true;
		}

		else if (expBuscado < v[m].exp) return buscBinRec(v, expBuscado, ini, m, pos);
		else return buscBinRec(v, expBuscado, m + 1, fin, pos);
	}
}

void polinomio::agregarMonomio(int coef, int exp) {
	if (coef != 0) {
		int pos = 0;
		if (!buscBinRec(v, exp, 0, v.size(), pos)) {
			monomio h = { coef, exp };
			v.push_back({ 0,0 });
			for (int i = v.size() - 1; i > pos; --i)v[i] = v[i - 1];
			v[pos] = h;
		}

		else v[pos].coef += coef;
	}
}

int polinomio::evaluar(int num)const {
	int sol = 0;
	for (int i = 0; i < v.size(); ++i) {
		sol += v[i].coef * pow(num, v[i].exp);
	}

	return sol;
}