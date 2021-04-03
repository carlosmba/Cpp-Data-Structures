/*Ejercicio 1: Crear una lista que almacene "n" numeros enteros y calcular el menor y mayor de ellos.*/
#include<iostream>
#include<stdlib.h>
using namespace std;


struct Node{
	int date;
	Node *next;
};

//Function Prototype
void menu();
void pop(Node *&,int);
void showItems(Node *);
void calculateMinorHigher(Node *);

Node *list = NULL;
int main(){
	menu();
	
	
	return 0;
}
void menu(){
	int opc,date;
	
	do{
		cout<<"\t:MENU:\n"<<endl;
		cout<<"1. Insertar elemento en la lista\n";
		cout<<"2. Mostrar todos los elementos de la lista\n";
		cout<<"3. Mostrar el menor y mayor elemento de la lista\n";
		cout<<"4. Salir\n";
		cout<<"Opcion: ";
		cin>>opc;
		
		
		switch(opc){
			case 1: 
				cout<<"Ingrese el elemento: ";
				cin>>date;
				pop(list,date);
			break;
			
			case 2:
				showItems(list);
			break;
			
			case 3: 
				calculateMinorHigher(list);
			break; 
		}
		system("pause"); system("cls");
		
	}while(opc != 4);
}
void pop(Node *&list,int n){
	Node *nodeNew = new Node();
	Node *aux;
	nodeNew->date = n;
	nodeNew->next = NULL;
	
	if(list==NULL){
		list = nodeNew;
	}else{
		aux = list;
		
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = nodeNew;
	}
	cout<<"El elemento se agrego correctamente"<<endl;
	
	
}
void showItems(Node *list){
	Node *actual = list;
	if(actual!=NULL){
		while(actual != NULL){
			cout<<actual->date<<"->";
			actual = actual->next;
		}
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
	
}
void calculateMinorHigher(Node *list){
	int menor = 99999,mayor=0;
	Node *actual = list;
	while(actual != NULL){
		if(actual->date < menor){
			menor = actual->date;
		}
		if(actual->date > mayor){
			mayor = actual->date;
		}
		actual = actual->next;
	}
	cout<<"El menor elemento es: "<<menor<<endl;
	cout<<"El mayor elemento es: "<<mayor<<endl;
}
