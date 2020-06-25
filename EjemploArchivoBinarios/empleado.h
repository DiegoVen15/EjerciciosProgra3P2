#pragma once
#ifndef empleado_h
#define empleado_h

struct empleado {

	int codigo;
	char nombre[30];
	char puesto[15];
	int codigoJefe;
	bool activo;
};

void registroEmpleados();
void consultaEmpleados();
int cantidadEmpleados();
void desactivarEmpleados(int);
#endif // !empleado_h
