

#include <conio.h>
#include "ListaDobleCircular.h"
int main() {

	ListaCircular ls;

	ls.agregarElemento(4);
	ls.agregarElemento(1);
	ls.agregarElemento(5);
	ls.agregarElemento(3);	

	ls.imprimirLista();
	ls.imprimirListaRev();


	_getch();
}