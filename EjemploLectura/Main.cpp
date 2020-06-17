
#include <conio.h>
#include <iostream>

#include <fstream>

#include <sstream>
using std::cout;
using namespace std;

void LecturaCsv();

int main() {
	
	LecturaCsv();

	_getch();
}

void LecturaCsv() {
	
	ifstream archivoCsv("movies.csv", ios::in);

	if (!archivoCsv) {

		cout << "Error de lectura en archivo movies.csv";
		return;
	}

	string linea;

	int filas = 0;
	while (getline(archivoCsv, linea)) {

		stringstream linestream(linea);

		for (int i = 0; i < 22; i++) {

			string valor;
			getline(linestream, valor, ',');

			if( i < 6)
			cout << valor << "\t";

		}

		cout << "\n";
		
		if (filas > 30) {
			break;
		}
	}
}