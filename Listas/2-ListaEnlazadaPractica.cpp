#include<iostream>
#include<stdlib.h>
using namespace std;


struct Node{
	int date;
	Node *next;
};

//Function prototype
void menu();
void insertItems(Node *&,int);
void showItems(Node *);
void searchItem(Node *,int);
void nodeDelete(Node *&,int);

Node *list = NULL;

int main(){
	menu();
	
}
void menu(){
	int opc;
	int date;
	do{
		cout<<"\tBIENVENIDO A LISTAS ENLAZADAS\n"<<endl;
		cout<<"1. Insertar elemento en la lista"<<endl;
		cout<<"2. Mostrar elementos de la lista"<<endl;
		cout<<"3. Buscar un elemento en la lista"<<endl;
		cout<<"4. Eliminar un elemento de la lista"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case 1: cout<<"Ingrese el elemento a insertar: ";
				cin>>date;
				insertItems(list,date);
			break;
			
			case 2: showItems(list);
			break;
			
			case 3: cout<<"Ingrese el elemento a buscar: ";
				cin>>date;
				searchItem(list,date);
			break;
			
			case 4: cout<<"Ingrese el elemento a eliminar: ";
				cin>>date;
				nodeDelete(list,date);
			break;
		}
		system("pause"); system("cls");
	}while(opc != 5);
	
}
void insertItems(Node *&list,int n){
	Node *nodeNew = new Node();
	nodeNew->date = n;
	
	Node *aux1 = list;
	Node *aux2;
	
	
	while((aux1 != NULL) && (aux1->date < n)){
		aux2 = aux1;
		aux1 = aux1->next;
	}
	
	if(aux1==list ){
		list = nodeNew;
	}else{
		aux2->next = nodeNew;
	}
	nodeNew->next = aux1;
	
	cout<<"Se agrego el elemento correctamente"<<endl;
}
void showItems(Node *list){
	Node *actual = list;
	
	if(list!=NULL){
		while(actual != NULL){
		cout<<actual->date<<"->";
		actual = actual->next;
		}
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
}
void searchItem(Node *list,int n){
	Node *actual = list;
	bool band = false;
	
	if(actual != NULL){
		while((actual != NULL)&&(actual->date <= n)){
				if(actual->date == n){
					band = true;
				}
			actual = actual->next;
		}
	
		if(band){
			cout<<"Se encontro el elemento "<<n<<" en la lista"<<endl;
		}else{
			cout<<"No se econtro el elemento "<<n<<" en la lista"<<endl;
		}
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
	
	
}
void nodeDelete(Node *&list,int n){
	if(list != NULL){
		Node *aux_delete;
		Node *aux2 = NULL;
		
		aux_delete = list;
		while((aux_delete != NULL) && (aux_delete->date != n)){
			aux2 = aux_delete;
			aux_delete = aux_delete->next;
		};
		
		if(aux2==NULL){
			list = list->next;
			delete aux_delete;
			cout<<"Se elimino el elemento correctamente"<<endl;
		}else if(aux_delete==NULL){
			cout<<"No existe el elemento en la lista"<<endl;
		}else{
			aux2->next = aux_delete->next;
			delete aux_delete;
			cout<<"Se elimino el elemento correctamente"<<endl;
		}
			
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
	
	
	
}
