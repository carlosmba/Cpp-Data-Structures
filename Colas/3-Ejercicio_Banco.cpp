/*Ejercicio 2: Hacer un programa que guarde datos de clientes de un banco, los almacene en cola, y por ultimo muestre los 
clientes en el orden correcto.*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Cliente{
	char dni[20];
	char nombre[100];
	char telefono[20];
		
};
struct Nodo{
	Cliente clientes;
	Nodo *sigiente;
};
//Prototipo de funcion
void menu();
void push(Nodo *&,Nodo *&,Cliente);
void pop(Nodo *&,Nodo *&, Cliente &);
bool cola_vacia(Nodo *);


int main(){
	menu();
	
	
	
	
	system("pause");
	return 0;
}
void menu(){
	Nodo *frente = NULL;
	Nodo *final = NULL;
	Cliente datos;
	int i = 1;
	int opc;
	do{
		cout<<"\t****Banco de Venezuela****"<<endl;
		cout<<"1. Registrar Cliente"<<endl;
		cout<<"2. Mostrar Clientes"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		fflush(stdin);
		switch(opc){
			case 1: 
				cout<<"*Registrando Cliente"<<endl;
				cout<<"Ingrese su dni: ";
				cin.getline(datos.dni,20,'\n');
				cout<<"Ingrese su nombre: ";
				cin.getline(datos.nombre,100,'\n');
				cout<<"Ingrese su Telefono: ";
				cin.getline(datos.telefono,20,'\n');
				push(frente,final,datos);
			break;
			case 2:cout<<"*Mostrando los clientes"<<endl;
				while(frente!=NULL){
					pop(frente,final,datos);
					cout<<"Cliente NRO. "<<i++<<endl;
					cout<<"DNI: "<<datos.dni<<endl;
					cout<<"Nombre: "<<datos.nombre<<endl;
					cout<<"Telefono: "<<datos.telefono<<endl;
					cout<<"\n\n";
				}
			break;
		}
		system("pause"); system("cls");
	}while(opc!=3);
	
}
void push(Nodo *&frente,Nodo *&final,Cliente datos){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->clientes = datos;
	nuevo_nodo->sigiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
		
	}else{
		final->sigiente = nuevo_nodo;
	}
	final = nuevo_nodo;
}
void pop(Nodo *&frente,Nodo *&final,Cliente &datos){
	datos = frente->clientes;
	Nodo *aux = frente;
	
	if(frente==final){
		frente = NULL;
		final = NULL;
	}else{
		frente = frente->sigiente;
	}
	delete aux;
}
bool cola_vacia(Nodo *frente){
	return (frente==NULL)?true:false;
}
