#ifndef fecha_h
#define fecha_h


class fecha {
private:
	int dia;
	int mes;
	int year;

public:
	fecha() {};
	fecha(int dia, int mes, int year) {
		this->dia = dia;
		this->mes = mes;
		this->year = year;
	}

	int getDia()const {
		return dia;
	}

	void setDia(int dia) {
		this->dia = dia;
	}

	int getMes()const {
		return mes;
	}

	void setMes(int mes) {
		this->mes = mes;
	}
	int getYear()const {
		return year;
	}

	void setYear(int year) {
		this->year = year;
	}

	bool operator<(fecha const & that)const {
		if (year < that.year) return true;
		else if (year == that.year && mes < that.mes)return true;
		else if (year == that.year && mes == that.mes && dia < that.dia)return true;
		else return false;
	}
};


#endif