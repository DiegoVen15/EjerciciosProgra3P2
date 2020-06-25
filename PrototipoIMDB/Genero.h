#pragma once
#ifndef GENERO_H
#define GENERO_H

class genero {

private:
	
	char* nombre;
	genero* siguiente;

public:

	genero(const char*, genero*);

	void setSiguiente(genero*);
	
	char* getGenero();
	genero* getSiguiente();
};
#endif // !GENERO_H
