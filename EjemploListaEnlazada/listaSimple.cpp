#include "listaSimple.h"
#include <iostream>

using namespace std;
listaSimple::listaSimple() : primero(nullptr) 
{}

bool listaSimple::estaVacia() {

	return primero == nullptr;
}

void listaSimple::agregarNodo(int valor1) {

	Nodo* nuevo = new Nodo(valor1, nullptr);

	if (estaVacia()) {

		primero = nuevo;
	}
	else {

		Nodo* actual = primero;

		while (actual->getSiguiente() != nullptr) {

			actual = actual->getSiguiente();
		}

		actual->setSiguiente(nuevo);
	}
	cout << "Nodo agregado\n";

}

void listaSimple::imprimirLista() {
	
	Nodo* actual = primero;

	cout << " ";
	while (actual != nullptr) {

		cout << " [ " << actual->getValor() << " ] ";
		actual = actual->getSiguiente();
	}

	cout << "\n";
}

void listaSimple::eliminarNodo(int valor1) {

	if (estaVacia())
		return;

	Nodo* actual = primero;
	Nodo* anterior = nullptr;

	do {

		if (actual->getValor() == valor1) {

			if (actual == primero) {

				primero == actual->getSiguiente();
				delete actual;
			}
			else {

				anterior->setSiguiente(actual->getSiguiente());
				delete actual;
			}

			cout << "Nodo eliminado\n";
			return;
		}
		else
			anterior = actual;
			actual = actual->getSiguiente();
	} while ( actual != nullptr);
}