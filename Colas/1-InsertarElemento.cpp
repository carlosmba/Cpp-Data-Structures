/*Insertar Elementos en una cola*/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo de funcion

void push(Nodo *&,Nodo *&,int);
void pop(Nodo *&,Nodo *&,int &);
bool cola_vacia(Nodo *);


int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
	char c;
	do{
		cout<<"Ingrese un dato: ";
		cin>>dato;
		push(frente,fin,dato);
		cout<<"Deseas ingresar otro dato (s/n): ";
		cin>>c;	
	}while(c != 'N' && c != 'n');
	cout<<endl;
	cout<<"Eliminando Elementos: "<<endl;
	cout<<endl;
	while(frente!=NULL){
		pop(frente,fin,dato);
		if(frente!=NULL){
			cout<<dato<<", ";
		}else{
			cout<<dato<<". ";
		}
	}
	
	
	cout<<"\n\n";
	system("pause");
	return 0;
}
void push(Nodo *&frente,Nodo *&fin,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	cout<<endl;
	cout<<"Se agrego el elemento correctamente "<<endl;
}
bool cola_vacia(Nodo *frente){
	return (frente==NULL)?true:false;
}
void pop(Nodo *&frente,Nodo *&fin,int &dato){
	dato = frente->dato;
	Nodo *aux = frente;
	
	if(frente==fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente;	
	}
	delete aux;
}
