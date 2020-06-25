#pragma once
#ifndef PELICULA_H
#define PELICULA_H
#include "Genero.h"

class pelicula {

private:
	char* idTitle;
	char* title;
	int year;

	genero* primerGenero;	
	pelicula* siguiente;
	pelicula* anterior;

public:
	
	pelicula(const char*, const char*, int);

	void addGenero(const char*);	

	char* getIdTitle();
	char* getTitle();
	int getYear();

	void setSiguiente(pelicula*);
	void setAnterior(pelicula*);

	pelicula* getSiguiente();


	genero* getPrimerGenero();
	void imprimirGeneros();

};
#endif // !PELICULA_H
