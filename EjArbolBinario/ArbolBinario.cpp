#include "ArbolBinario.h"

#include <iostream>
#include <fstream>
using namespace std;

using std::cout;

ArbolBinario::ArbolBinario() : raiz(nullptr)
{}

void ArbolBinario::agregarElemento(const char* _nombre)
{

	raiz = agregarAux(raiz, _nombre);

}

NodoArbol* ArbolBinario::agregarAux(NodoArbol* _raiz, const char* _nombre)
{

	if (_raiz == nullptr)
	{
		NodoArbol* nuevo = new NodoArbol(_nombre, nullptr, nullptr);
		_raiz = nuevo;
	}
	else if (strcmp(_nombre, _raiz->getNombre()) > 0)
		_raiz->setHijoDerecho(agregarAux(_raiz->getHijoDerecho(), _nombre));
	else if (strcmp(_nombre, _raiz->getNombre()) < 0)
		_raiz->setHijoIzquierdo(agregarAux(_raiz->getHijoIzquierdo(), _nombre));

	return _raiz;
}

void ArbolBinario::imprimirArbol()
{
	imprimirAux(raiz);
}

void ArbolBinario::imprimirAux(NodoArbol* _raiz)
{

	if (_raiz == nullptr)
		return;

	cout << "[ " << _raiz->getNombre() << " ] ";
	imprimirAux(_raiz->getHijoIzquierdo());
	imprimirAux(_raiz->getHijoDerecho());
}

int ArbolBinario::obtenerPeso() {

	return pesoTotal(raiz);
}

int ArbolBinario::pesoTotal(NodoArbol* x) {

	int a = 0, b = 0;

	if (x->getHijoIzquierdo() != nullptr) {

		a = pesoTotal(x->getHijoIzquierdo());
	}
	if (x->getHijoDerecho() != nullptr) {

		b =pesoTotal(x->getHijoDerecho());
	}

	int t = a + b;
	return t + 1;
}

int ArbolBinario::obtenerAlturaMaxima() {

	return alturaTotal(raiz);
}

int ArbolBinario::alturaTotal(NodoArbol* x) {

	int a = 0, b = 0;

	if (x->getHijoIzquierdo() != nullptr) {

		a = pesoTotal(x->getHijoIzquierdo());
	}
	if (x->getHijoDerecho() != nullptr) {

		b = pesoTotal(x->getHijoDerecho());
	}

	if (a > b) {

		return a + 1;
	}
	else if (a < b) {

		return b + 1;
	}
	else if (a == b) {

		return a;
	}
}

void ArbolBinario::guardarElementos(){

	char elementos[] = "elementos.dat";
	
	ofstream elementosOut;
	elementosOut.open(elementos, ios::out | ios::end | ios::binary);

	ArbolBinario nuevo;
	if (!elementosOut) {

		cout << "Error al intentar abrir archivo\n";
		return;
	}

	elementosOut.write(reinterpret_cast<const char*>(&nuevo), sizeof(ArbolBinario));

	elementosOut.close();
}