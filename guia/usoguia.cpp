#include "guiatlf.h"

int main(){
Guia_Tlf g;
 cout<<"Introduce una guia"<<endl;
 cin>>g;
 //cout<<"La guia insertada "<<g<<endl;
 cin.clear();
// cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;
/* while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else 
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }	
 cin.clear();
 cout<<"Dime el nombre que quieres borrar"<<endl;
 
 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }
 
 cout<<"Dime el nombre que quieres borrar"<<endl;
 
 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }
 */
 cin.clear();
 Guia_Tlf otraguia;
 cout<<"Introduce otra guia"<<endl;

 cin>>otraguia; cin.clear();
 Guia_Tlf un = g+otraguia;
 Guia_Tlf dif = g-otraguia;

 cout<<"La union de las dos guias: "<<endl <<un<<endl;
 
 cout<<"La diferencia de las dos guias:"<<endl <<dif<<endl;
 

 
}
