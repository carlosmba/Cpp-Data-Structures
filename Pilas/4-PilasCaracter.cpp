/*Hacer un programa en C++, utilizando Pilas que contenga el siguiente menú: 

1. Insertar un carácter a la pila
2. Mostrar todos los elementos de la pila
3. Salir 
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Nodo{
	char n;
	Nodo *siguiente;
};

//Prototipos de Funciones
void menu();
void insertarPila(Nodo*&,char);
void mostrar(Nodo *&,char&);


int main(){
	int opc;
	char valor;
	Nodo *pila = NULL;
	
	do{
		menu();cin>>opc;
		
		switch(opc){
			case 1: 
				cout<<"Ingresa el carater: ";
				cin>>valor;
				insertarPila(pila,valor);
			break;
			case 2: 
				while(pila!=NULL){
					mostrar(pila,valor);
					if(pila!=NULL){
						cout<<valor<<", ";
					}else{
						cout<<valor<<". ";
					}
				}
			break;	
		}
		cout<<"\n\n";
		system("pause"); system("cls");	
	}while(opc!=3);
	
	
	
	return 0;
}
void menu(){
	cout<<"**PILAS**"<<endl;
	cout<<"1. Insertar un Caracter a la pila"<<endl;
	cout<<"2. Mostrar todos los elementos de la pila"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"opcion: ";
}
void insertarPila(Nodo *&pila,char dato){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->n = dato;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	cout<<"Se agrego el Elemento Correctamente"<<endl;
}
void mostrar(Nodo *&pila,char &dato){
	Nodo *aux;
	aux = pila;
	dato = aux->n;
	pila = aux->siguiente;
	delete aux;
}
	
