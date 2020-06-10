#include <iostream>
#include <conio.h>
using std::cout;

int main() {

	char abc[27];

	for (int i = 0; i < 27; i++) {

		abc[i] = 0;
	}
	cout << "Direccion de memoria de abc[0]: " << &abc[0] << "\n";

	cout << "Direccion de memoria de abc[1]: " << &abc[1] << "\n";	

	_getch();
}