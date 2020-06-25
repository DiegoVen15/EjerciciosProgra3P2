#pragma once
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"

class ArbolBinario
{
private:
	NodoArbol* raiz;

public:
	ArbolBinario();

	void agregarElemento(const char*);
	//funcion recursiva
	NodoArbol* agregarAux(NodoArbol*, const char*);

	void imprimirArbol();
	void imprimirAux(NodoArbol*);

	int obtenerPeso();
	int pesoTotal(NodoArbol*);
	int obtenerAlturaMaxima();
	int alturaTotal(NodoArbol*);
	void guardarElementos();
	void cargarElementos();
};


#endif // !ARBOLBINARIO_H