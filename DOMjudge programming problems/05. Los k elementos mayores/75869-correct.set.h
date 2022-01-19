//
//  conjunto.h
//

#ifndef conjunto_h
#define conjunto_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <string>
#include "algoritmos.h"


template <class T>
class set {
public:
	set(int tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	int size() const;
	T getMenor() const;
	void eraseMenor();
private:
	const static int TAM_INICIAL = 8;
	int contador;
	int capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
};

template <class T>
set<T>::set(int tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T>
void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (int i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	int pos = 0;
	if (!binarySearch(datos, e, 0, contador, pos)) {
		if (contador == capacidad)amplia();
		for (int i = contador; i > pos; --i) datos[i] = datos[i - 1];
		datos[pos] = e;
		++contador;
	}
}

template <class T>
bool set<T>::contains(T e) const {
	int pos = 0;
	return binarySearch(datos, e, 0, contador, pos);
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (int i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	int pos = 0;
	if (binarySearch(datos, e, 0, contador, pos)) {
		for (int i = pos; i < contador - 1; ++i)datos[i] = datos[i + 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
int set<T>::size() const {
	return contador;
}

template < class T>
T set<T>::getMenor() const {
	if (contador == 0) throw std::domain_error("no hay ningun elemento");
	return datos[0];
}

template <class T>
void set<T>::eraseMenor() {
	if (contador == 0) throw std::domain_error("no hay ningun elemento");
	for (int i = 0; i < contador - 1; ++i) datos[i] = datos[i + 1];
	--contador;
}

#endif // conjunto_h