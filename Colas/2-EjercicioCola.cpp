/*Ejercicio 1: Hacer un programa en C++, utilizando colas que contenga el siguiente menu: 

1. Insertar un caracter a una cola.
2. Mostrar todos los elementos
3. Salir
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo{
	char a;
	Nodo *siguiente;
};
//Prototipo de funcion
void menu();
void push(Nodo *&,Nodo*&,char);
void pop(Nodo *&,Nodo*&,char&);
bool cola_vacio(Nodo *);
int main(){
	
	menu();
	
	return 0;
}
void menu(){
	Nodo *frente = NULL;
	Nodo *final = NULL;
	int opc;
	char dato;
	do{
		cout<<"\t**COLAS**"<<endl;
		cout<<"1. Insertar un caracter a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"opcion: ";
		cin>>opc;
		
		switch(opc){
			case 1:
					cout<<"Ingrese el caracter: ";cin>>dato;
					push(frente,final,dato);
					cout<<endl;
			break;
			case 2:cout<<"**Mostrando todos los elementos**"<<endl;
				while(frente!=NULL){
					pop(frente,final,dato); 
					if(frente!=NULL){
						cout<<dato<<", ";
					}else{
						cout<<dato<<". "<<endl;
					}
				}
			break;
		}
		cout<<"\n";
		system("pause"); system("cls");	
	}while(opc!=3);	
}
void push(Nodo *&frente,Nodo *&final,char c){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->a = c;
	nuevo_nodo->siguiente= NULL;
	
	if(cola_vacio(frente)){
		frente = nuevo_nodo;
		final = nuevo_nodo;
	}else{
		final->siguiente = nuevo_nodo;
	}
	final = nuevo_nodo;
	cout<<"Se inserto el elemento Correctamente "<<endl;
}
void pop(Nodo *&frente,Nodo *&final,char &c){
	c = frente->a;
	Nodo *aux = frente;
	
	if (frente==final){
		frente = NULL;
		final = NULL;
	}else{
		frente = frente->siguiente;
	}
	delete aux;
}
bool cola_vacio(Nodo *frente){
	return (frente==NULL)?true:false;
}
