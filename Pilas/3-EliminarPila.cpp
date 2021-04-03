#include<iostream>
#include <stdlib.h>
using namespace std;


struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo de funcion 
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int& );

int main(){
	Nodo *pila = NULL;
	int dato;
	cout<<"\nIngrese un valor: ";cin>>dato;
	agregarPila(pila, dato);
	cout<<"\nIngrese otro valor: ";cin>>dato;
	agregarPila(pila, dato);
	cout<<"\n\n";
	cout<<"Sacando elementos de la Pila: ";
	while(pila != NULL){
		sacarPila(pila,dato);
		if(pila!=NULL){
			cout<<dato<<" , ";
		}else{
			cout<<dato<<" .";
		}
	}
	
	cout<<"\n\n";
	system("pause");
	return 0;
}
void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\n\tSe agrego el valor "<<n<<" Correctamente"<<endl;	
}
void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
