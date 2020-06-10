#include "SeccionLista.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

SeccionLista::SeccionLista() : primero(nullptr)
{}

bool SeccionLista::estaVacia() {

	return primero == nullptr;
}

void SeccionLista::agregarAlumno(char* nombre1, float nota1) {

	AlumnoNodo* nuevo = new AlumnoNodo(nombre1, nota1,  nullptr);

	if (estaVacia()) {

		primero = nuevo;
	}
	else {
		
		AlumnoNodo* actual = primero;

		while (actual->getSiguiente() != nullptr) {
			//comparo si voy aqui


			if (strcmp(nombre1, actual->getNombre()) > 0) {
				//si voy aqui ingresso nodo
				nuevo->setSiguiente(actual->getSiguiente());
				actual->setSiguiente(nuevo);
			}
			else {
				//si el siguiente es nullptr, voy aqui
			actual = actual->getSiguiente();

			}
			//si no voy aqui
				//me voy al siguiente


		}


		
	}
}

void SeccionLista::listarSeccion() {

	AlumnoNodo* actual = primero;


	while (actual != nullptr) {

		cout << "Nombre: " << actual->getNombre() << "\nNota: " << actual->getNota();
		actual = actual->getSiguiente();
	}

	cout << "\n";
}

int SeccionLista::cantidadAprobados() {

	AlumnoNodo* actual = primero;
	int reprobados = 0;
	while (actual != nullptr) {

		if (actual->getNota() < 70) {
			reprobados++;
			actual = actual->getSiguiente();
		}
		else {
			actual = actual->getSiguiente();
		}
	}	

	return reprobados;
}