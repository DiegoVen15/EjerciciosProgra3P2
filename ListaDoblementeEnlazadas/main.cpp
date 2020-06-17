#include <conio.h>
#include "EmpresaLista.h"

int main() {

	empresaLista el;

	el.agregarEmpleado(1001, (char*)"Diego", 800);
	el.agregarEmpleado(1002, (char*)"Juan", 1200);
	el.agregarEmpleado(1003, (char*)"Carlos", 1700);

	el.imprimirEmpleados();

	el.insertarEmpleado(1004, (char*)"Pedro", 1100);

	el.imprimirEmpleados();

	el.eliminarEmpleado(1002);

	el.imprimirEmpleados();

	el.actualizarSalarios(0.5);
	
	el.imprimirEmpleados();

	_getch();
}