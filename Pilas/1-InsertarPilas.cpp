#include<iostream>
#include <stdlib.h>
using namespace std;


struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo de funcion 
void agregarPila(Nodo *&, int);

int main(){
	Nodo *pila = NULL;
	int n1;
	cout<<"\nIngrse un valor: ";cin>>n1;
	
	agregarPila(pila, n1);
	
	cout<<"\n\n";
	system("pause");
	return 0;
}
void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\n\tSe agrego el valor "<<n<<" Correctamente";	
}
