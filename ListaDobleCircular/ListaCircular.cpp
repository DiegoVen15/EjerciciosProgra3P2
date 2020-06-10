#include "ListaDobleCircular.h"

#include <iostream>
using namespace std;

ListaCircular::ListaCircular() : primero(nullptr), ultimo(nullptr)
{}

bool ListaCircular::estaVacia() {

	return primero == nullptr;
}

void ListaCircular::agregarElemento(int valor1) {

	Nodo* nuevo = new Nodo(valor1, nullptr, nullptr);
	
		if (estaVacia()) {

			primero = nuevo;
			ultimo = nuevo;

			ultimo->setSiguiente(primero);
			primero->setAnterior(ultimo);
		}
		else {

			ultimo->setSiguiente(nuevo);
			primero->setAnterior(ultimo);

			ultimo = nuevo;

			ultimo->setSiguiente(primero);
			primero->setAnterior(ultimo);
		}

		cout << "Elemento ingresado\n";
}

void ListaCircular::imprimirLista() {

	if (estaVacia())
		return;

	Nodo* actual = primero;

	do {

		cout << "[ " << actual->getValor() << " ]";
		actual = actual->getSiguiente();
	} while (actual != primero);
	cout << "\n";
}

void ListaCircular::imprimirListaRev() {

	if (estaVacia())
		return;

	Nodo* actual = ultimo;

	do {

		cout << "[ " << actual->getValor() << " ]";
		actual = actual->getAnterior();
	} while (actual != ultimo);
}