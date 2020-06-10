
#include "SeccionLista.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {

	SeccionLista sl;
	sl.agregarAlumno((char*)"Diego", 81);
	sl.agregarAlumno((char*)"Andres", 50);
	sl.agregarAlumno((char*)"Carlos", 60);
	
	sl.listarSeccion();

	cout << "Reprobados: " << sl.cantidadAprobados() << "\n";

}