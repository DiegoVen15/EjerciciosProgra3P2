#include "Nodo.h"

Nodo::Nodo() : valor(-1), anterior(nullptr), siguiente(nullptr) {

}

Nodo::Nodo(int valor1, Nodo* anterior, Nodo* siguiente) {
	
	setValor(valor1);
	setAnterior(anterior);
	setSiguiente(siguiente);
}

void Nodo::setValor(int valor1) {

	this->valor = valor1;
}

void Nodo::setAnterior(Nodo* anterior1) {

	this->anterior = anterior1;
}

void Nodo::setSiguiente(Nodo* siguiente1) {

	this->siguiente = siguiente1;
}

int Nodo::getValor() {
	return valor;
}

Nodo* Nodo::getAnterior() {
	return anterior;
}

Nodo* Nodo::getSiguiente() {
	return siguiente;
}




