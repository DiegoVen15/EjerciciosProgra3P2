#include "nodo.h"

Nodo::Nodo(void) : valor(-1), siguiente(nullptr)
{}

Nodo::Nodo(int valor1, Nodo* siguiente1) 
{
	setValor(valor1);
	setSiguiente(siguiente1);
}

void Nodo::setValor(int valor1) {

	this->valor = valor1;
}

void Nodo::setSiguiente(Nodo* siguiente1) {

	this->siguiente = siguiente1;
}

int Nodo::getValor(void) {

	return valor;
}

Nodo* Nodo::getSiguiente(void) {

	return siguiente;
}
