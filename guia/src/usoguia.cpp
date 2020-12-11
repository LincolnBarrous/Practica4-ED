#include "guiatlf.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	Guia_Tlf g;

	ifstream in;
	in.open(argv[1]);

	in >> g;
	cout << "La guia insertada " << endl
		 << g << endl;
	cout << "Dime un nombre sobre el que quieres obtener el telefono" << endl;
	string n;
	getline(cin, n);

	cout << "Buscando " << n << "..." << endl;
	string tlf = g.gettelefono(n);
	if (tlf == "")
		cout << "No existe el nombre en la guia" << endl;
	else
		cout << "El telefono es " << tlf << endl;

	cin.clear();
	cout << "Dime el nombre que quieres borrar (NO para finalizar)" << endl;

	getline(cin, n);
	while (n != "NO")
	{
		g.borrar(n);
		cout << "La guía queda: " << endl;
		cout << g;
		cout << "Dime el nombre que quieres borrar (NO para finalizar)" << endl;
		getline(cin, n);
	}

	cin.clear();
	Guia_Tlf otraguia;
	cout << "Leyendo segunda guía..." << endl;
	in.close();
	in.open(argv[2]);

	in >> otraguia;

	Guia_Tlf un = g + otraguia;
	Guia_Tlf dif = g - otraguia;

	cout << "La union de las dos guias: " << endl
		 << un << endl;

	cout << "La diferencia de las dos guias:" << endl
		 << dif << endl;

	Guia_Tlf inter = g.Interseccion(otraguia);
	cout << "La intersección de las dos guias: " << endl
		 << inter << endl;

	char caracter;
	cout << "Inserte la letra para filtrar contactos (se mostrarán los que empiezan por la indicada)" << endl;
	cin >> caracter;
	caracter = toupper(caracter);
	Guia_Tlf letra = g.EmpiezaPor(caracter);

	cout << "Nombres que comienzan por la letra " << caracter << endl;
	cout << letra << endl;

	// Cambiar número de contacto
	
	string nombre;

	cout << "Desea cambiar el número de algún contacto? (NO para cancelar): ";
	
	cin.ignore();
	getline(cin, nombre);
	
	while (nombre != "NO")
	{
		cout << "Introduzca el nuevo número: ";
		string numero;
		cin >> numero;
		cout << "Numero leido " << numero << endl;
		if (g.ModificarNumero(nombre, numero)) {
			cout << "Modificado" << endl;
			cout << "La guía queda " << endl;
			cout << g << endl;
		}
		else
			cout << "El contacto no se encuentra en su guía" << endl;
		cin.ignore();
		cout << "Desea cambiar el número de algún contacto más? (NO para cancelar)";

		getline(cin, nombre);
	}

	// Sacar rango
	string minimo, maximo;
	cout << "Introduzca el intervalo de nombres a extraer: " << endl;
	getline(cin, minimo);
	getline(cin, maximo);

	Guia_Tlf rango = g.Rango(minimo, maximo);
	cout << "Rango desde " << minimo << " hasta " << maximo << endl;
	cout << rango << endl;


}
