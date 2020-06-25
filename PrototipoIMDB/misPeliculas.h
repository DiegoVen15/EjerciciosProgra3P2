#pragma once
#ifndef MISPELICULAS_H
#define MISPELICULAS_H
#include "Pelicula.h"

class misPeliculas {

private:
	pelicula* primeraPelicula;
	pelicula* ultimaPelicula;	

public:

	misPeliculas();

	void addPeliculas(const char*, const char*, int);

	void deletePelicula(const char*);

	void imprimirPeliculas();
};
#endif // !MISPELICULAS_H
