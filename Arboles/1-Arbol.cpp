#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int date;
	Node *der;
	Node *izq;
	Node *padre;
};


//Function prototype
void menu();
Node *createNode(int,Node *);
void insertNode(Node *&,int,Node *);
void showAllNode(Node *);
bool searchNode(Node*,int);
void travelTree(Node *);
void travelTreeIn(Node *);
void travelTreePost(Node *);
void remove(Node *,int);
void eliminateNode(Node*);
Node *small(Node *);
void replace(Node *,Node *);
void destroy(Node*);

Node *arbol = NULL;
int main(){
	menu();
	
	return 0;
}
void menu(){
	int opc,contador = 0,date;
	
	do{
		cout<<"::MENU::\n"<<endl;
		cout<<"1. Insertar elementos en el arbol\n";
		cout<<"2. Mostrar todos los elementos del arbol\n";
		cout<<"3. Buscar un Elemento\n";
		cout<<"4. Recorrer el arbol en PreOrden\n";
		cout<<"5. Recorrer el arbol en InOrden\n";
		cout<<"6. Recorrer el arbol en PostOrden\n";
		cout<<"7. Eliminar un node del arbol\n";
		cout<<"8. Salir\n";
		cout<<"Opcion: ";
		cin>>opc;
		
		switch(opc){
			case 1: cout<<"Ingrese el elemento a ingresar: ";
				cin>>date;
				insertNode(arbol,date,NULL);
			break;
			
			case 2: 
				showAllNode(arbol);
			break;
			
			case 3: 
				cout<<"Ingrese el elemento a buscar: ";
				cin>>date;
				if(searchNode(arbol,date)){
					cout<<"\nEl elemento "<<date<<" a sido encontrado en el arbol\n";
				}else{
					cout<<"\nEl elemento NO a sido encontrado en el arbol\n";
				}
			break;
			
			case 4: travelTree(arbol);
				cout<<"\n\n";
			break;
			
			case 5: travelTreeIn(arbol);
				cout<<"\n\n";
			break;
			
			case 6: travelTreePost(arbol);
				cout<<"\n\n";
			break;
			
			case 7: 
				cout<<"Ingrese el nodo a eliminar: ";
				cin>>date;
				remove(arbol,date);
			break;
		}
		system("pause"); system("cls");
	}while(opc != 8);
}
Node *createNode(int n, Node *padre){
	Node *newNode = new Node();
	newNode->date = n;
	
	newNode->der = NULL;
	newNode->izq = NULL;
	
	newNode->padre = padre;
	
	return newNode;
}
void insertNode(Node *&arbol,int n, Node *padre){	
	if(arbol==NULL){
		Node *nodeNew = createNode(n,padre);
		arbol = nodeNew;
	}else{
		int valorRaiz = arbol->date;
		if(n < valorRaiz){
			insertNode(arbol->izq,n,arbol);
		}else{
			insertNode(arbol->der, n,arbol);
		}
		
	}
}
void showAllNode(Node *arbol){
	if(arbol != NULL){
		showAllNode(arbol->der);
		cout<<arbol->date<<"   ";
		showAllNode(arbol->izq);
	}else{
		return;
	}
	
	
}
bool searchNode(Node *arbol,int n){
	if(arbol==NULL){
		return false;
	}else if(arbol->date == n){
		return true;
	}else if(n < arbol->date){
		searchNode(arbol->izq,n);
	}else{
		searchNode(arbol->der,n);
	}
}
void travelTree(Node *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->date<<" - ";
		travelTree(arbol->izq);
		travelTree(arbol->der);
	}
}
void travelTreeIn(Node *arbol){
	if(arbol==NULL){
		return;
	}else{
		travelTreeIn(arbol->izq);
		cout<<arbol->date<<" - ";
		travelTreeIn(arbol->der);
	}
}
void travelTreePost(Node *arbol){
	if(arbol==NULL){
		return;
	}else{
		travelTreePost(arbol->izq);
		travelTreePost(arbol->der);
		cout<<arbol->date<<" - ";
	}
}

void remove(Node *arbol,int n){
	if(arbol==NULL){
		return;
	}else if(n < arbol->date){
		remove(arbol->izq,n);
	}else if(n > arbol->date){
		remove(arbol->der,n);
	}else{
		eliminateNode(arbol);	
	}
}
void eliminateNode(Node *nodeRemove){
	if((nodeRemove->izq) && (nodeRemove->der)){
		Node *menor = small(nodeRemove->der);
		nodeRemove->date = menor->date;
		eliminateNode(menor);
	}else if(nodeRemove->izq){
		
		replace(nodeRemove,nodeRemove->izq);
		destroy(nodeRemove);		
		
	}else if(arbol->der){
		replace(nodeRemove,nodeRemove->der);
		destroy(nodeRemove);
	}else{
		replace(nodeRemove,NULL);
		destroy(nodeRemove);
	}
}
Node *small(Node *arbol){
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return small(arbol->izq);
	}else{
		return arbol;		
	}
}
void replace(Node *arbol,Node *nodeNew){
	if(arbol->padre){
		if(arbol->date == arbol->padre->izq->date){
			arbol->padre->izq = nodeNew;
		}else if(arbol->date == arbol->padre->der->date){
			arbol->padre->der = nodeNew;
		}	
	}
	if(nodeNew){
		nodeNew->padre = arbol->padre;
	}
}
void destroy(Node *arbol){
	arbol->izq = NULL;
	arbol->der = NULL;
	
	delete arbol;
}
