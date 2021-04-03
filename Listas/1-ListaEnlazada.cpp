#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int date;
	Node *next;
};


//Function prototype
void menu();
void pop(Node *&,int);
void show(Node *);
void search(Node *,int);
void deleteNode(Node *&,int);
void deleteAll(Node *&,int &);

Node *list = NULL;
int main(){
	menu();
	
	
	return 0;
}
void menu(){
	int date;
	int opc;
	do{
		cout<<"\t*****Listas Enlazadas*****"<<endl;
		cout<<"1. Ingresar elemento a la lista\n";
		cout<<"2. Mostrar elementos de la lista\n";
		cout<<"3. Buscar Elemento de la lista\n";
		cout<<"4. Eliminar un nodo de la lista\n";
		cout<<"5. Eliminar la lista completa\n";
		cout<<"6. Salir\n";
		cout<<"Opcion: ";
		cin>>opc;
	
		switch(opc){
			case 1:
				cout<<"Ingrese un numero: ";
				cin>>date;
				pop(list,date);
			break;
			case 2:
				cout<<"\nMostrando Elementos de la lista: "<<endl;
				show(list);
			break;
			case 3:
				cout<<"Ingrese el elemento a buscar: ";
				cin>>date;
				search(list,date);
			break;
			case 4:
				cout<<"Ingrese el elemento a eliminar: ";
				cin>>date;
				deleteNode(list,date);
			
			case 5:
				while(list != NULL){
					deleteAll(list,date);
					cout<<date<<"->";
				}
			break;
		}
		cout<<endl;
		system("pause"); system("cls");
	}while(opc != 6);
		
}
void pop(Node *&list ,int n){
	Node *new_node = new Node();
	new_node->date = n;
	
	Node *aux = list;
	Node *aux2;
	
	while((aux != NULL) && (aux->date < n)){
		aux2 = aux;
		aux = aux->next;
	}
	
	if(aux==list){
		list = new_node;
	}else{
		aux2->next = new_node;
	}
	new_node->next = aux;
	
	cout<<"Se agrego el Elemento Correctamente"<<endl;
}
void show(Node *list){
	Node *actual = new Node();
	actual = list;
	if(actual != NULL){
		while(actual != NULL){
			cout<<actual->date<<"->";
			actual = actual->next;
		}
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
	
}
void search(Node *list,int date){
	Node *actual = new Node();
	actual = list;
	bool band = false;
	
	while((actual != NULL) && (actual->date <= date)){
		if(actual->date == date){
			band = true;
		}
		actual = actual->next;
	}
	
	if(band){
		cout<<"El elemento "<<date<<" SI esta en la lista"<<endl;
	}else{
		cout<<"El elemento "<<date<<" NO esta en la lista"<<endl;
	}
	
}
void deleteNode(Node *&list,int date){
	if(list!=NULL){
		Node *aux_delete;
		Node *previous = NULL;
		
		aux_delete = list;
		while((aux_delete != NULL)&&(aux_delete->date != date)){
			previous = aux_delete;
			aux_delete = aux_delete->next;
		}
		
		if(aux_delete==NULL){
			cout<<"No se encontro el Elemento"<<endl;
		}else if(previous==NULL){
			list = list->next;
			delete aux_delete;
			cout<<"Se elimino el elemento correctamente"<<endl;
		}else{
			previous->next = aux_delete->next;
			delete aux_delete;
			cout<<"Se elimino el elemento correctamente"<<endl;
		}
		
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
}
void deleteAll(Node *&list,int &n){
	Node *aux = list;
	n = aux->date;
	list = aux->next;
	delete aux;
	
}
