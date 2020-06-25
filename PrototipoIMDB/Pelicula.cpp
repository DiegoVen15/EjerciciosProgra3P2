
#include "Pelicula.h"
#include <iostream>
using namespace std;

pelicula::pelicula(const char* idTitle1, const char* title1, int year1){

	idTitle = new char[strlen(idTitle1)];
	strcpy_s(idTitle, strlen(idTitle1), idTitle1);

	title = new char[strlen(title1)];
	strcpy_s(title, strlen(title1), title1);

	year = year1;

	primerGenero = nullptr;
	siguiente = nullptr;
	anterior = nullptr;
}

void pelicula::addGenero(const char* genero1) {

	genero* nuevo = new genero(genero1, nullptr);

	if (primerGenero == nullptr) {

		primerGenero = nuevo;
		return;
	}

	genero* actual = primerGenero;

	while(actual->getSiguiente() != nullptr) {

		actual = actual->getSiguiente();
	};

	actual->setSiguiente(nuevo);
}

char* pelicula::getIdTitle() {

	return idTitle;
}

char* pelicula::getTitle() {

	return title;
}

int pelicula::getYear() {

	return year;
}

genero* pelicula::getPrimerGenero() {

	return primerGenero;
}

void pelicula::imprimirGeneros() {

	if (primerGenero == nullptr) {
		return;
	}

	genero* actual = primerGenero;

	do {

		cout << actual->getGenero();
		
		if (actual->getSiguiente() != nullptr) {
			cout << ", ";
		}

		actual = actual->getSiguiente();
	} while (actual != nullptr);
}

void pelicula::setSiguiente(pelicula* siguiente1) {

	siguiente = siguiente1;
}

void pelicula::setAnterior(pelicula* anterior1) {

	anterior = anterior1;
}

pelicula* pelicula::getSiguiente() {

	return siguiente;
}