
#include "empleado.h"
#include <fstream>
#include <iostream>

using namespace std;

void registroEmpleados() {

	ofstream empleadosOut("empleados.dat", ios::out | ios::app | ios::binary);

	if (!empleadosOut) {

		cout << "Error al intentar abrir el archivo empleados.dat\n";
		return;
	}

	cout << "\n\n INGRESO DE EMPLEADOS \n\n";

	int opcion = 0;
	empleado nuevo;

	do {

		cout << "Ingrese el codigo: ";
		cin >> nuevo.codigo;

		cout << "Ingrese el nombre: ";
		cin >> nuevo.nombre;

		cout << "Ingrese el puesto: ";
		cin >> nuevo.puesto;

		cout << "Ingrese el codigo del jefe (-1 si no tiene): ";
		cin >> nuevo.codigoJefe;
		
		nuevo.activo = 1;

		empleadosOut.write(reinterpret_cast <const char*>(&nuevo), sizeof(empleado));
	} while (opcion != -1);

	empleadosOut.close();
}

void consultaEmpleados() {

	ifstream empleadosIn("empleados.dat", ios::in | ios::binary);

	if (!empleadosIn) {

		cout << "Error al intentar abrir el archivo empleados.dat\n";
		return;
	}

	cout << "\n\n CONSULTA	 DE EMPLEADOS \n\n";

	empleadosIn.seekg(0, ios::beg);

	empleado actual;

	empleadosIn.read(reinterpret_cast <char*>(&actual), sizeof(empleado));

	while (!empleadosIn.eof()) {

		if (actual.activo) {

			cout << "Empleado { codigo: " << actual.codigo << ", nombre: " << actual.nombre << ", puesto: " << actual.puesto <<
				", jefe: " << actual.codigoJefe << " }\n";	
 		}

		empleadosIn.read(reinterpret_cast <char*>(&actual), sizeof(empleado));
	}

	empleadosIn.close();
}

int cantidadEmpleados() {

	ifstream empleadosIn("empleados.dat", ios::in | ios::binary);

	if (!empleadosIn) {

		cout << "Error al intentar abrir el archivo empleados.dat\n";
		return -1;
	}

	//ubicarse al final del archivo
	empleadosIn.seekg(0, ios::end);

	//obtener el ultimo byte del archivo
	int posicionFinal = empleadosIn.tellg();

	int cantidadRegistros = posicionFinal / sizeof(empleado);

	return cantidadRegistros;
}

void desactivarEmpleados(int posicion) {

	if (posicion > cantidadEmpleados()) {

		cout << "Posicion de empleado incorrecta\n";
		return;
	}

	fstream empleadosInOut("empleados.dat", ios::in | ios::out | ios::binary);

	if (!empleadosInOut) {

		cout << "Error al intentar abrir el archivo empleados.dat\n";
		return;
	}

	empleado modificar;
	//posicionarse al inicio del registro a modificar
	int pos = (posicion - 1) * sizeof(empleado);

	//leer el registro
	empleadosInOut.seekg(pos, ios::beg);

	//modificar el registro
	empleadosInOut.read(reinterpret_cast<char*>(&modificar), sizeof(empleado));

	modificar.activo = 0; //false

	empleadosInOut.seekp(pos, ios::beg);

	empleadosInOut.write(reinterpret_cast<char*>(&modificar), sizeof(empleado));

	cout << "Empleado desactivado!";
}