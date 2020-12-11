#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
#include <list>
using namespace std;

istream &operator>>(istream &is, pair<string, string> &d)
{

	getline(is, d.first, '\t');
	getline(is, d.second);
	return is;
}

/**
 * @brief TDA Guia_Tlf
 * 
 * Una instancia @e guia de la clase @e Guia_Tlf es un conjunto de datos organizados de dos en dos en forma de:\n
 * clave: de tipo string, que será el nombre del contacto\n
 * numero: de tipo string, que será el número de teléfono\n
 */
class Guia_Tlf
{
private:
	map<string, string> datos; //si admites que haya nombres repetidos tendr�as que usar un
							   //multimap

public:
	/**
	 * @brief Constructor por defecto
	 * 
	 * Se deja como default pues se usará el de la clase map de la STL
	 */
	Guia_Tlf() = default;

	/**
	 * @brief Constructor de copia
	 * @param gt La guía a copiar
	 * 
	 * También default pues se usará el de la clase map de STL
	 */
	Guia_Tlf(const Guia_Tlf &gt) = default;

	/**
	 * @brief Destructor
	 * 
	 * Default para que se llame al destructor de map
	 */
	~Guia_Tlf() = default;

	/**
	 * @brief Operador de asignación
	 * @param gt Guía a copiar
	 * 
	 * Se llamará simplemente al operador de asignación de la clase map
	 */
	Guia_Tlf &operator=(const Guia_Tlf &gt)
	{
		if (this != &gt)
			datos = gt.datos;
	}

	/**
	 * @brief Acceso a un elemento
	 * @param nombre: nombre del elemento  elemento acceder
	 * @return devuelve el valor asociado a un nombre, es decir el teléfono
 	 */
	string &operator[](const string &nombre)
	{
		return datos[nombre];
	}

	/**
	 * @brief Consultor de teléfono a partir del nombre
	 * @param nombre El nombre a buscar
	 * @return El teléfono del nombre buscado
	 * 
	 * Se mantendrá el uso de los iteradores map::iterator en los métodos que ya se nos dan implementados. Sólo se usarán los iteradores
	 * Guia_Tlf::iterator en los nuevos métodos implementados por mí
	 */
	string gettelefono(const string &nombre)
	{
		map<string, string>::iterator it = datos.find(nombre);
		if (it == datos.end())
			return string("");
		else
			return it->second;
	}

	/**
	 * @brief Insert un nuevo telefono 
	 * @param nombre: nombre clave del nuevo telefono
	 * @param tlf: numero de telefono
	 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
	 */
	pair<map<string, string>::iterator, bool> insert(string nombre, string tlf)
	{
		pair<string, string> p(nombre, tlf);
		pair<map<string, string>::iterator, bool> ret;

		ret = datos.insert(p);
		return ret;
	}

	/**
	 * @brief Insert un nuevo telefono 
	 * @param p: pair con el nombre y el telefono asociado
	 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
	 */
	pair<map<string, string>::iterator, bool> insert(pair<string, string> p)
	{

		pair<map<string, string>::iterator, bool> ret;

		ret = datos.insert(p);
		return ret;
	}

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar
	 * @note: en caso de que fuese un multimap borraria todos con ese nombre
	 */
	void borrar(const string &nombre)
	{
		map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
		map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
		datos.erase(itlow, itupper);									   //borramos todos aquellos que tiene dicho nombre
	}

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar y telefono asociado
	 * @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
	 */
	//con map siempre hay uno con multimap puede existir mas de uno
	void borrar(const string &nombre, const string &tlf)
	{
		map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
		map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
		map<string, string>::iterator it;
		bool salir = false;
		for (it = itlow; it != itupper && !salir; ++it)
		{
			if (it->second == tlf)
			{
				datos.erase(it);
				salir = true;
			}
		}
	}
	/**
	 * @brief  Numero de telefonos
	 * @return el numero de telefonos asociados
     */
	int size() const
	{
		return datos.size();
	}

	/**
	 * @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
	 * @param nombre: nombre sobre el que queremos consultar
	 * @return numero de telefonos asociados a un nombre      
     */
	//al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas de uno
	unsigned int contabiliza(const string &nombre) const
	{
		return datos.count(nombre);
	}

	/**
	 * @brief Limpia la guia
	 */
	void clear()
	{
		datos.clear();
	}

	/**
	 * @brief Union de guias de telefonos
	 * @param g: guia que se une
	 * @return: una nueva guia resultado de unir el objeto al que apunta this y g
     */
	Guia_Tlf operator+(const Guia_Tlf &g)
	{
		Guia_Tlf aux(*this);
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			aux.insert(it->first, it->second);
		}
		return aux;
	}

	/**
	 * @brief Diferencia de guias de telefonos
	 * @param g: guia que se une
	 * @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
	 */
	Guia_Tlf operator-(const Guia_Tlf &g)
	{
		Guia_Tlf aux(*this);
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			aux.borrar(it->first, it->second);
		}
		return aux;
	}

	/**
	 * @brief Escritura de la guia de telefonos
	 * @param os: flujo de salida. Es MODIFICADO
	 * @param g: guia de telefonos que se escribe
	 * @return el flujo de salida
	 */

	friend ostream &operator<<(ostream &os, Guia_Tlf &g)
	{
		map<string, string>::iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			os << it->first << "\t" << it->second << endl;
		}
		return os;
	}

	/**
	 * @brief Lectura de  la guia de telefonos
	 * @param is: flujo de entrada. ES MODIFICADO
	 * @param g: guia de telefonos. ES MODIFICADO
	 * @return el flujo de entrada
	 */

	friend istream &operator>>(istream &is, Guia_Tlf &g)
	{
		pair<string, string> p;
		Guia_Tlf aux;

		while (is >> p)
		{
			aux.insert(p);
		}
		g = aux;
		return is;
	}

	// ----------------------------------------------------------------
	/**
	 * @brief TDA Guia_Tlf::iterator
	 * 
	 * Para el recorrido de una guía de teléfonos (usará la clase map::iterator)
	 */
	class iterator
	{
	private:
		typename map<string, string>::iterator it;
		friend class Guia_Tlf;
		iterator(typename map<string, string>::iterator mit)
		{
			it = mit;
		};

	public:
		iterator() : it(){};
		iterator(const iterator &git)
		{
			it = git.it;
		};

		iterator &operator=(const iterator &git)
		{
			if (this != &git)
				it = git.it;
			return *this;
		};

		iterator &operator++()
		{
			++it;
			return *this;
		};

		bool operator!=(const iterator &git)
		{
			return (it != git.it);
		};

		pair<string, string> operator*()
		{
			return (*it);
		};
	};

	iterator begin()
	{
		iterator ret(datos.begin());
		return ret;
	};
	iterator end()
	{
		iterator ret(datos.end());
		return ret;
	};

	class const_iterator
	{
		typename map<string, string>::const_iterator cit;
		friend class Guia_Tlf;
		const_iterator(typename map<string, string>::const_iterator mcit)
		{
			cit = mcit;
		};

	public:
		const_iterator() : cit(){};
		const_iterator(const const_iterator &cgit)
		{
			cit = cgit.cit;
		};

		const_iterator &operator=(const const_iterator &cgit)
		{
			if (this != &cgit)
				cit = cgit.cit;
		};

		const_iterator &operator++()
		{
			++cit;
			return *this;
		};
		bool operator!=(const const_iterator &cgit)
		{
			return (cit != cgit.cit);
		};
		const pair<string, string> operator*() const
		{
			return (*cit);
		};
	};

	const_iterator cbegin() const
	{
		const_iterator ret(datos.cbegin());
		return ret;
	};
	const_iterator cend() const
	{
		const_iterator ret(datos.cend());
		return ret;
	};

	// Métodos adicionales
	/**
	 * @brief Intersección de guías
	 * 
	 * Devuelve una guía que incluye sólo los contactos que están en ambas guías.
	 */
	Guia_Tlf Interseccion(const Guia_Tlf &otra)
	{
		Guia_Tlf nueva;
		if (size() == 0 || otra.size() == 0)
			return nueva;
		for (const_iterator it = cbegin(); it != cend(); ++it)
		{
			if (otra.contabiliza((*it).first) > 0)
			{
				pair<string, string> p((*it).first, (*it).second);
				nueva.insert(p);
			}
		}
		return nueva;
	}

	/**
	 * @brief Devuelve teléfonos cuyos nombres empiecen por una letra
	 * @param letra La letra a buscar
	 */
	Guia_Tlf EmpiezaPor(char letra)
	{
		Guia_Tlf guia;
		for (iterator it = begin(); it != end(); ++it)
		{
			if ((*it).first[0] == letra) {
				pair<string,string> p((*it).first, (*it).second);
				guia.insert(p);
			}
		}
		return guia;
	};

	/**
	 * @brief Modificar el teléfono asociado a un nombre
	 * @param nombre El nombre al que cambiar el teléfono
	 * @param num el nuevo número
	 */
	bool ModificarNumero(const string &nombre, const string &num)
	{
		bool terminar = false;
		for (iterator dit = begin(); dit != end() && !terminar; ++dit)
		{
			if ((*dit).first == nombre)
			{
				(*(dit.it)).second = num;
				terminar = true;
			}
		}
		return terminar;
	};

	/**
	 * @brief Saca todos los contactos entre dos nombres (alfabéticamente)
	 * @param inicio el primer nombre del rango
	 * @param fin el último nombre del rango
	 * @return Una guía que incluye los nombres entre inicio y fin ambos inclusive
	 */
	Guia_Tlf Rango(const string &inicio, const string &fin)
	{
		Guia_Tlf rango;
		if (contabiliza(inicio) <= 0 || contabiliza(fin) <= 0)
			return rango;
		for (iterator it = begin(); it != end(); ++it)
		{
			string nombre = (*it).first;
			if ((nombre >= inicio) && (nombre <= fin))
			{
				pair<string, string> p(nombre, (*it).second);
				rango.insert(p);
			}
		}
		return rango;
	};
};

#endif
