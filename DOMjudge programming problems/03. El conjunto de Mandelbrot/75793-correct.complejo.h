//Marcos Herrero

#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <cmath>

template<class T>
class complejo {
public: complejo<T>()  {}
		complejo<T>(T const & a, T const & b) { this->a = a; this->b = b; }
		complejo<T> operator+(complejo<T> const & that)const;
		complejo<T> operator*(complejo<T> const & that)const;
		T modulo()const;
private: T a;
		 T b;
};

template<class T>
complejo<T> complejo<T>::operator+(complejo<T> const & that)const {
	return complejo<T>(a + that.a, b + that.b);
}

template<class T>
complejo<T> complejo<T>::operator*(complejo<T> const & that)const {
	return complejo<T>(a*that.a - b * that.b, a*that.b + that.a* b);
}

template<class T>
T complejo<T>::modulo() const {
	return sqrt(a*a + b * b);
}

#endif