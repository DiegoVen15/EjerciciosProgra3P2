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

void ListaCircular::eliminarElemento(int valor1) {

	if (estaVacia())
		return;

	Nodo * actual = primero;

	do{
	
		if (actual->getValor() == valor1) {

			if (actual == primero) {

				primero = actual->getSiguiente();
				primero->setAnterior(ultimo);
				ultimo->setSiguiente(primero);

				delete actual;
			}
			else if (actual == ultimo) {

				ultimo = actual->getAnterior();
				ultimo->setSiguiente(primero);
				primero->setAnterior(ultimo);

				delete actual;
			}
			else{
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());

				delete actual; 
			}
		}
		else {
			actual = actual->getSiguiente
		}
	
	} while (actual != primero);
}

void ListaCircular::insertarElemento(int pos1, int valor1) {

	if (estaVacia()) {

		agregarElemento(valor1);
		return;
	}
	else {

		int cantidad = tamanoLista();

		if (pos1 > cantidad) {

			cout << "Posicin de insersion no existe";
			return;
		}

		Nodo* actual = primero;
		int posActual = 1;
		Nodo* nuevo = new Nodo(valor1, nullptr, nullptr);

		do {

			if (posActual == pos1) {

				if (actual == primero) {

					nuevo->setSiguiente(primero);
					primero->setAnterior(nuevo);

					primero = nuevo;

					primero->setSiguiente(ultimo);
					ultimo->setAnterior(primero);
				}

				else {

					actual->getAnterior()->setSiguiente(nuevo);
					nuevo->setAnterior(actual->getAnterior());

					nuevo->setSiguiente(actual);
					actual->setAnterior(nuevo);
				}

				cout << "Nodo Insertado\n";
			}
			else {
				actual = actual->getSiguiente();
			}

		} while (actual != primero);
	}
}

int ListaCircular::tamanoLista() {

	if (estaVacia()) {
		return 0;
	}
	
		Nodo* actual = primero;

		int cantidad = 0;
		do {

			cantidad++;
			actual = actual->getSiguiente();
		} while (actual != primero);

		return cantidad;
	
}
