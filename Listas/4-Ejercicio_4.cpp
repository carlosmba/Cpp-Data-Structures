/*Ejercicio 2: Crear una lista que almacene "n" numeros reales y calcular la suma y su promedio*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	float date;
	Node *next;
};

//Function protoype
void menu();
void pop(Node *&,float);
void showAllItems(Node *);
void calculateSumAverage(Node *);

Node *list = NULL;
int main(){
	menu();
	
	
	return 0;
}
void menu(){
	int opc;
	float date;
	
	do{
		cout<<"\t::MENU::\n"<<endl;
		cout<<"1. Insertar elementos en la lista\n";
		cout<<"2. Mostrar todos los elementos de la lista\n";
		cout<<"3. Mostrar la suma y el promedio\n";
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
				showAllItems(list);
			break;
			
			case 3:
				calculateSumAverage(list);
			break;
		}
		cout<<endl;
		system("pause"); system("cls");
	}while(opc != 4);
	
	
	
	
}
void pop(Node *&list,float n){
	Node *newNode = new Node();
	Node *aux;
	
	newNode->date = n;
	newNode->next = NULL;
	
	if(list==NULL){
		list = newNode;
	}else{
		aux = list;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = newNode;
	}
	cout<<"Se agrego el elemento correctamente"<<endl;
}
void showAllItems(Node *list){
	Node *actual = list;
	
	if(actual != NULL){
		while(actual != NULL){
			cout<<actual->date<<"->";
			actual = actual->next;
		}
		
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
}
void calculateSumAverage(Node *list){
	float promedio = 0,suma = 0;
	int cont = 0;
	
	while(list != NULL){
		suma += list->date;
		cont++;
		list = list->next;
	}
	promedio = suma/cont;
	
	cout<<"La suma es: "<<suma<<endl;
	cout<<"El promedio es: "<<promedio<<endl;
}
