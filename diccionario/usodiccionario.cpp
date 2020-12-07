#include <iostream>
#include "diccionario.h"

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
listas de listas y otro sobre listas
*/
ostream &operator<<(ostream &os, const Diccionario<string, string> &D)
{

	typename Diccionario<string, string>::const_iterator it;

	for (it = D.cbegin(); it != D.cend(); ++it)
	{

		list<string>::const_iterator it_s;

		os << endl
		   << (*it).clave << endl
		   << " informacion asociada:" << endl;
		for (it_s = (*it).info_asoci.begin(); it_s != (*it).info_asoci.end(); ++it_s)
		{
			os << (*it_s) << endl;
		}
		os << "**************************************" << endl;
	}

	return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asocimakadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream &operator>>(istream &is, Diccionario<string, string> &D)
{
	int np;
	is >> np;
	is.ignore(); //quitamos \n
	Diccionario<string, string> Daux;
	for (int i = 0; i < np; i++)
	{
		string clave;

		getline(is, clave);

		int ns;
		is >> ns;
		is.ignore(); //quitamos \n
		list<string> laux;
		for (int j = 0; j < ns; j++)
		{
			string s;
			getline(is, s);

			// cout<<"Significado leido "<<s<<endl;
			laux.insert(laux.end(), s);
		}
		Daux.Insertar(clave, laux);
	}
	D = Daux;
	return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string> &l)
{
	list<string>::const_iterator it_s;

	for (it_s = l.begin(); it_s != l.end(); ++it_s)
	{
		cout << *it_s << endl;
	}
}

/*Lee un diccioario e imprime datos asociados a una clave. 
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
                  ./usodiccionario < data.txt 
*/
int main()
{
	Diccionario<string, string> D;


	cin >> D;
	cout << "DICCIONARIO 1 : " << endl;
	cout<<D;

	
	Diccionario<string, string> D2;
	cin >> D2;
	cout << "DICCIONARIO 2 : " << endl;
	cout << D2;
/*
	string a;
	*/
	/*
	cout << "Union de diccionarios" << endl;
	Diccionario<string, string> U = D.unionDiccionarios(D2);

	cout << U << endl;
	*/

	/*

	string inicio;
	cout << "Clave de inicio: " << endl;
	cin >> inicio;

	string fin;
	cout << "Clave de final: " << endl;
	cin >> fin;

	Diccionario<string,string> rango = D.sacarRango(inicio, fin);
	cout << rango;
	*/

	cout << "Diferencia D1-D2 : " << endl;
	cout << D.diferenciaDiccionarios(D2) << endl;


}
