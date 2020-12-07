#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * @brief Elemento Diccionario
 * 
 * Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
 * no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
 * de tipo T. El diccionario está ordenado de menor a mayor clave.
 */
template <class T, class U>
struct data
{
	T clave;
	list<U> info_asoci;
};

/**
 * @brief Comparador de datos
 * 
 * Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 * un funtor.
 */
template <class T, class U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2)
{
	if (d1.clave < d2.clave)
		return true;
	return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/

/** @brief T.D.A Diccionario
 * 
 * Una instancia @e d del tipo de dato abstracto Diccionario sobre un dominio @e T y @e U es una lista de datos de los definidos anteriormente.
 * En un diccionario, las entradas se ordenan en función de la clave, de tipo @e T.
 * 
 * Se implementa mediante una lista de elementos de tipo data, que son parejas de tipo @e T y @e U
 */
template <class T, class U>
class Diccionario
{
private:
	list<data<T, U>> datos;

	// NO SÉ COMO COPIAR CON EL ITERADOR Diccionario::iterator
	void Copiar(const Diccionario<T, U> &D)
	{


		/*typename list<data<T,U> >::const_iterator it_d;
			   typename list<data<T,U> >::iterator it=this->datos.begin();*/

		datos.assign(D.datos.begin(), D.datos.end());
		/*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				     this->datos.insert(it,*it_d);
				     
			   }*/
	}

	void Borrar()
	{

		this->datos.erase(datos.begin(), datos.end());
	}

public:
	class iterator;
	class const_iterator;
	/**
	 * @brief Constructor por defecto
	 * 
	 * Llamará simplemente al constructor por defecto de la clase list (STL)
	 */
	Diccionario() : datos(list<data<T, U>>()) {}

	/**
	 * @brief Constructor de copia
	 * @param D El diccionario a copiar
	 * 
	 * Se usa el método auxiliar privado Copiar 
	 */
	Diccionario(const Diccionario &D)
	{
		Copiar(D);
	}

	/**
	 * @brief Destructor
	 * 
	 * Se llamará automáticamente al destructor de la clase list (STL)
	 */
	~Diccionario() {}

	/**
	 * @brief Operador de asignación
	 * @param D El diccionario a copiar
	 * @return Una referencia al diccionario copiado (para asignaciones encadenadas)
	 * 
	 * Se usan los métodos auxiliares privados Copiar y Borrar
	 */
	Diccionario<T, U> &operator=(const Diccionario<T, U> &D)
	{
		if (this != &D)
		{
			Borrar();
			Copiar(D);
		}
		return *this;
	}

	/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
	/**
	 * @brief Busqueda de una clave
	 * @param p La clave a buscar
	 * @param it_out El iterador con el que recorreremos el diccionario
	 * 
	 * @return True si está // False si no está
	 * 
	 * Busca la clave p en el diccionario. Si está devuelve true y pone el iterador it_out a donde está la clave.
	 * Si no está, devuelve false y deja el iterador de salida apuntando a donde debería estar la clave.
	 * Si el diccionario está vacío, apuntará a end() y también se devolverá false
	 */
	bool Esta_Clave(const T &p, iterator &it_out)
	{

		if (datos.size() > 0)
		{

			iterator it;

			for (it = begin(); it != end(); ++it)
			{
				if ((*it).clave == p)
				{
					it_out = it;
					return true;
				}
				else if ((*it).clave > p)
				{
					it_out = it;
					return false;
				}
			}

			it_out = it;
			return false;
		}
		else
		{
			it_out = end();
			return false;
		}
	}

	/**
	 * @brief Insercción de una clave con su información asociada
	 * @param clave La clave
	 * @param info La lista de informaciones asociadas
	 * 
	 * Inserta un nuevo registro en el diccionario. Lo hace a través de la clave e inserta la lista
	 * con toda la información asociada a esa clave. Si el diccionario no estuviera ordenado habría que usar
	 * la función sort()
	 * 
	 */
	void Insertar(const T &clave, const list<U> &info)
	{

		iterator it;

		// En el método Esta_Clave pone it a donde debe insertarse p (end() si está vacía o después del inmediantamente menor si hay elementos)
		if (!Esta_Clave(clave, it))
		{
			data<T, U> p;
			p.clave = clave;
			p.info_asoci = info;

			datos.insert(it.dit, p);
		}
	}

	/**
	 * @brief Añade información
	 * @param s La información a añadir
	 * @param p La clave a la que añadírsela
	 * 
	 * Añade una nueva información asociada a una clave que está en el diccionario al final de la lista de información.
	 * Si no está la clave la inserta
	 */
	void AddSignificado_Palabra(const U &s, const T &p)
	{
		typename list<data<T, U>>::iterator it;

		if (!Esta_Clave(p, it))
		{
			datos.insert(it, p);
		}

		//Insertamos el siginificado al final
		(*it).info_asoci.insert((*it).info_asoci.end(), s);
	}

	/* Devuelve la información (una lista) asociada a una clave p. Podrían 
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
    /**
	 * @brief Consultor de información asociada
	 * @param p La clave a la que consultarle la información
	 * @return La lista de informaciones
	 * 
	 * Devuelve la información (una lista) asociada a una clave p. Podrían 
	 * haberse definido operator[] como
	 * data<T,U> & operator[](int pos){ return datos.at(pos);}
	 * const data<T,U> & operator[](int pos)const { return datos.at(pos);}
	 */
	list<U> getInfo_Asoc(const T &p)
	{
		iterator it;

		if (!Esta_Clave(p, it))
		{
			return list<U>();
		}
		else
		{
			return (*it).info_asoci;
		}
	}

	/**
	 * @brief Consultor del tamaño del diccionario
	 * @return El número de elementos de la lista
	 */
	int size() const
	{
		return datos.size();
	}


	// ----------------------------------------------------------------------
	// Iterador Diccionario::iterator
	class iterator {
		private:
		typename list<data<T,U>>::iterator dit;
		iterator(typename list<data<T,U>>::iterator it);
		friend class Diccionario<T,U>;

		public:
		iterator();
		iterator(const iterator &it);

		iterator &operator=(const iterator &it);
		
		iterator& operator++();
		bool operator!=(const iterator &it);
		data<T,U>& operator*();

	};

	// Iterador Diccionario::const_iterator
	class const_iterator {
		private:
		typename list<data<T,U>>::const_iterator cdit;
		const_iterator(typename list<data<T,U>>::const_iterator cit);
		friend class Diccionario<T,U>;

		public:
		const_iterator();
		const_iterator(const const_iterator &it);

		const_iterator &operator=(const const_iterator& it);

		const_iterator &operator++();
		bool operator!=(const const_iterator& it) const;
		const data<T,U>& operator*() const;
	};

	/*Funciones begin y end asociadas al diccionario*/
	/**
	 * @brief Iterador del principio de la lista
	 * @return Un objeto de la clase Diccionario::iterator que apunta al inicio de datos
	 */
	iterator begin();

	/**
	 * @brief Iterador del final de la lista
	 * @return Un objeto de la clase Diccionario::iterator que apunta al fin de datos
	 */
	iterator end(); 

	/**
	 * @brief Iterador constante del principio de la lista
	 * @return Un objeto de la clase list::const_iterator que apunta al inicio de datos 
	 */
	const_iterator cbegin() const;
    /**
	 * @brief Iterador constante del final de la lista
	 * @return Un objeto de la clase list::const_iterator que apunta al final de datos 
	 */
	const_iterator cend() const;


	/**
	 * MÉTODOS ADICIONALES
	 */

	/**
	 * 
	 */
	bool borrarClave (T clave);

	/**
	 * 
	 */
	Diccionario<T,U> unionDiccionarios (const Diccionario<T,U>& otro);

	/**
	 * 
	 */
	Diccionario<T,U> sacarRango (T inicio, T final);

	/**
	 * 
	 */
	Diccionario<T,U> diferenciaDiccionarios (const Diccionario<T,U>& otro);

};

#include "diccionario.cpp"

#endif
