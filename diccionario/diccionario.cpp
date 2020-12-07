#include "diccionario.h"

using namespace std;

// Diccionario::iterator
template <class T, class U>
Diccionario<T, U>::iterator::iterator(typename list<data<T, U>>::iterator it) : dit(it) {}

template <class T, class U>
Diccionario<T, U>::iterator::iterator(): dit() {}

template <class T, class U>
Diccionario<T, U>::iterator::iterator(const iterator &it) : dit(it.dit) {}

template <class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator=(const iterator &it)
{
    if (this != &it)
        dit = it.dit;
    return *this;
}

template <class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator++()
{
    dit++;
    return *this;
}

template <class T, class U>
bool Diccionario<T, U>::iterator::operator!=(const iterator &it)
{
    return (this->dit != it.dit);
}

template <class T, class U>
data<T, U> & Diccionario<T, U>::iterator::operator*()
{
    return (*dit);
}

// Clase Diccionario::const_iterator
template <class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(typename list<data<T, U>>::const_iterator cit) : cdit(cit) {}

template <class T, class U>
Diccionario<T, U>::const_iterator::const_iterator() : cdit() {}

template <class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(const const_iterator &cit) : cdit(cit.cdit) {}

template <class T, class U>
typename Diccionario<T, U>::const_iterator& Diccionario<T, U>::const_iterator::operator=(const const_iterator &cit)
{
    if (this != &cit)
        this->cdit = cit.cdit;
    return *this;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator++()
{
    cdit++;
    return *this;
}

template <class T, class U>
bool Diccionario<T, U>::const_iterator::operator!=(const const_iterator &it) const
{
    return (this->cdit != it.cdit);
}

template <class T, class U>
const data<T, U>& Diccionario<T, U>::const_iterator::operator*() const
{
    return (*cdit);
}

// Begin y end

template <class T, class U>
typename Diccionario<T, U>::iterator Diccionario<T, U>::begin()
{
    return Diccionario<T, U>::iterator(datos.begin());
}

template <class T, class U>
typename Diccionario<T, U>::iterator Diccionario<T, U>::end()
{
    return Diccionario<T, U>::iterator(datos.end());
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::cbegin() const
{
    return Diccionario<T, U>::const_iterator(datos.cbegin());
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::cend() const
{
    return Diccionario<T, U>::const_iterator(datos.cend());
}

/**
 * MÉTODOS ADICIONALES
 */

template <class T, class U>
bool Diccionario<T, U>::borrarClave(T clave)
{
    iterator it = begin();
    bool eliminado = false;

    if (Esta_Clave(clave, it))
    {
        for (it = begin(); it != end() && !eliminado; it++) {
            if ((*it).clave == clave) {
                datos.erase(it.dit);
                eliminado = true;
            }
        }
    }
    return eliminado;
}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::unionDiccionarios(const Diccionario<T,U>& otro) {
    Diccionario<T,U> union(*this);

    const_iterator it;

    fo (it=otro.cbegin(); it != otro.cend(); it++) {
        iterator it2;
        // Si está en el primer y el segundo diccionario
        // se unen los significados.
        if (Esta_Clave((it*).clave, it2) {
            for (typename list<U>::iterator sit= otro.datos.info_asoci.begin(); sit != otro.datos.info_asoci.end(); sit++) {
                (it*).datos.info_asoci.insert((it*).datos.info_asoci.end(), (it*).)
            }
        }
        // Si está en el segundo y no en elprimero se añade
        else {
            union.Insertar((it*).clave, (it*).info_asoci);
        }
    }
}


