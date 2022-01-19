#ifndef fecha_h
#define fecha_h


class fecha {
private:
	int dia;
	int hora;
	int minuto;

public:
	fecha() {};
	fecha(int dia, int hora, int minuto) {
		this->dia = dia;
		this->hora = hora;
		this->minuto = minuto;
	}

	int getDia()const {
		return dia;
	}

	void setDia(int dia) {
		this->dia = dia;
	}

	int getHora()const {
		return hora;
	}

	void setHora(int hora) {
		this->hora = hora;
	}
	int getMinuto()const {
		return minuto;
	}

	void setMinuto(int minuto) {
		this->minuto = minuto;
	}

	bool operator<(fecha const & that)const {
		if (dia < that.dia) return true;
		else if (dia == that.dia && hora < that.hora)return true;
		else if (dia == that.dia && hora == that.hora && minuto < that.minuto)return true;
		else return false;
	}
};


#endif