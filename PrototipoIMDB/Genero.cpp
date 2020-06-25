
#include "Genero.h"
#include <iostream>
using namespace std;

genero::genero(const char* nombre1, genero* siguiente1) {

	nombre = new char[strlen(nombre1)];
	strcpy_s(nombre, strlen(nombre1) + 1, nombre1);

	setSiguiente(siguiente1);
}

void genero::setSiguiente(genero* siguiente1){
	
	this->siguiente = siguiente1;
}

char* genero::getGenero() {

	return this->nombre;
}

genero* genero::getSiguiente() {

	return siguiente;
}