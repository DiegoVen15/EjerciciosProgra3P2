#pragma once

#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "nodo.h"

class listaSimple {

private:
	Nodo* primero;

public:
	listaSimple(void);	

	bool estaVacia(void);
	void agregarNodo(int);
	void imprimirLista(void);
	void eliminarNodo(int);
};

#endif // !LISTASIMPLE_H
