
#include "SeccionLista.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {

	SeccionLista sl;

	sl.agregarAlumno((char*)"Carlos", 60);
	sl.agregarAlumno((char*)"Diego", 81);

	sl.listarSeccion();

	cout << "Reprobados: " << sl.cantidadAprobados() << "\n";

}