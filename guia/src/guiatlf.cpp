#include "guiatlf.h"

// ---------------------------------------------
// Guia_Tlf::iterator
Guia_Tlf::iterator(typename map<string, string>::iterator mit)
{
    it = mit;
}

Guia_Tlf::iterator() : it() {}

Guia_Tlf::iterator(const iterator &git)
{
    it = git.it;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator=(const iterator &git)
{
    if (this != &git)
        it = git.it;
    return *this;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator++()
{
    ++it;
    return *this;
}

bool Guia_Tlf::iterator::operator!=(const iterator &git)
{
    return (it != git.it);
}

pair<string, string> &Guia_Tlf::iterator::operator*()
{
    return (*it);
}

// --------------------------------------------------
// Guia_Tlf::const_iterator
Guia_Tlf::const_iterator(typename map<string, string>::const_iterator mci)
{
    cit = mcit;
}

Guia_Tlf::const_iterator() : cit(){};

Guia_Tlf::const_iterator(const Guia_Tlf::const_iterator &cgit)
{
    cit = cgit.cit;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator=(const Guia_Tlf::const_iterator &cgit)
{
    if (this != &cgit)
        cit = cgit.cit;
    return *this;
}

Guia_Tlf::const_iterator& Guia_Tlf::const_iterator::operator++() {
    ++cit;
    return *this;
}

bool Guia_Tlf::const_iterator::operator!=(const const_iterator& cgit) {
    return (cit != cgit.cit);
}

const pair<string,string>& operator*() const {
    return (*it);
}

// ------------------------------------------------
Guia_Tlf::iterator Guia_Tlf::begin() {
    iterator it;
    it.it = datos.begin();
    return it;
}

Guia_Tlf::iterator Guia_Tlf::end() {
    iterator it;
    it.it = datos.end();
    return it;
} 

Guia_Tlf::const_iterator Guia_Tlf::cbegin() {
    const_iterator cit;
    cit.cit = datos.cbegin();
    return cit;
}

Guia_Tlf::const_iterator Guia_Tlf::cend() {
    const_iterator cit;
    cit.cit = datos.cend();
    return cit;
}
// Métodos adicionales

Guia_Tlf Guia_Tlf::Interseccion(const Guia_Tlf& otra) const {
    Guia_Tlf nueva;
    if (size() == 0 || otra.size() == 0)
        return nueva;
    for (iterator it = begin(); it != end(); ++it) {
        if (otra.contabiliza((*it).first) > 0) {
            pair<string, string> p ((*it).first, (*first).second);
            nueva.insert(p);
        }
    }
    return nueva;
}

list<string> Guia_Tlf::EmpiezaPor(char letra) {
    list<string> lista;
    for (iterator it = begin(); it != end(); ++it) {
        if ((*it).second[0] == letra)
            lista.push_back((*it).second);
    }
    return lista;
}

bool ModificarNumero (const string& nombre, const string& num) {
    bool terminar = false;
    for (iterator it = begin(); it != end() && !terminar; ++it) {
        if ((*it).first == nombre) {
            (*it).second = num;
            terminar = true;
        }
    }
    return terminar;    
}

Guia_Tlf Guia_Tlf::Rango(const string& inicio, const string& fin) {
    Guia_Tlf rango;
    if (contabiliza(inicio) <= 0 || contabiliza(fin) <= 0)
        return rango;
    for (iterator it = begin(); it != end(); it++) {
        string nombre = (*it).first;
        if ((nombre >= inicio) && (nombre <= fin)) {
            pair<string,string> p (nombre, (*it).second);
            rango.insert(p);
        }
    }
    return rango;
}

