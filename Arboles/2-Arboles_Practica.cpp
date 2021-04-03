/*Arboles practica*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int date;
	Node *izq;
	Node *der;
	Node *padre;
};

//Function prototype
void menu();
Node *createNode(Node *,int,Node *);
void insertNode(Node *&,int,Node *);
void showAllNode(Node *);
bool searchNode(Node *,int);
void travelTreePre(Node *);
void travelTreeIn(Node *);
void travelTreePost(Node *);
void remove(Node *,int);
void eliminateNode(Node*);
Node *minimum(Node *);
void replace(Node *,Node *);
void destroyNode(Node*);


Node *arbol = NULL;
int main(){
	
	menu();
	
	
	
	return 0;
}
void menu(){
	int opc,date;
	
	do{
		cout<<":::::MENU:::::\n"<<endl;
		cout<<"1. Ingresar elemento al arbol\n";
		cout<<"2. Mostrar todos los elementos del arbol\n";
		cout<<"3. Buscar un elemento en el arbol\n";
		cout<<"4. Recorrer el arbol en PreOrden\n";
		cout<<"5. Recorrer el arbol en InOrden\n";
		cout<<"6. Recorrer el arbol en PostOrden\n";
		cout<<"7. Eliminar un elemento del arbol\n";
		cout<<"8. Salir\n";
		cout<<"Opcion: ";
		cin>>opc;
		
		switch(opc){
			case 1:
				cout<<"\nIngrese un elemento al arbol: ";
				cin>>date;
				insertNode(arbol,date,NULL);
			break;
			
			case 2: 
				showAllNode(arbol);
			break;
			
			case 3: 
				cout<<"Ingrese el dato a buscar"<<endl;
				cin>>date;
				if(searchNode(arbol,date)){
					cout<<"El elemento "<<date<<" SI esta en el arbol"<<endl;
				}else{
					cout<<"El elemento "<<date<<" NO esta en el arbol"<<endl;
				}
			break;
			
			case 4: 
				travelTreePre(arbol);
			break;
			
			case 5: 
				travelTreeIn(arbol);
			break;
			
			case 6: 
				travelTreePost(arbol);
			break;
			
			case 7: 
				cout<<"Ingrese el elemento a eliminar: ";
				cin>>date;
				remove(arbol,date);
				
		}
		
		system("pause"); system("cls");
	}while(opc != 8);
}
Node *createNode(Node *arbol,int n,Node *padre){
	Node *nodeNew = new Node();
	
	nodeNew->date = n;
	nodeNew->izq = NULL;
	nodeNew->der = NULL;
	nodeNew->padre = padre;
	
	return nodeNew;
}

void insertNode(Node *&arbol,int n,Node *padre){
	if(arbol==NULL){
		Node *nodeNew = createNode(arbol,n,padre);
		arbol = nodeNew;
	}else if(n < arbol->date){
		insertNode(arbol->izq,n,arbol);
	}else{
		insertNode(arbol->der,n,arbol);
	}
}
void showAllNode(Node *arbol){
	if(arbol==NULL){
		return;
	}else{
		showAllNode(arbol->der);
		cout<<arbol->date<<" - ";
		showAllNode(arbol->izq);
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
void travelTreePre(Node *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->date<<" - ";
		travelTreePre(arbol->izq);
		travelTreePre(arbol->der);
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
void eliminateNode(Node*arbol){
	if((arbol->izq) && (arbol->der)){
		Node *menor = minimum(arbol->der);
		
		arbol->date = menor->date;
		
		eliminateNode(menor);
	}else if(arbol->izq){
		replace(arbol,arbol->izq);
		destroyNode(arbol);
		
		
	}else if(arbol->der){
		replace(arbol,arbol->der);
		destroyNode(arbol);
	}else{
		replace(arbol,NULL);
		destroyNode(arbol);
	}
}
Node *minimum(Node *arbol){
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimum(arbol->izq);
	}else{
		return arbol;
	}
}
void replace(Node *nodeEliminate,Node *nodeNew){
	if(nodeEliminate->date == nodeEliminate->padre->izq->date){
		nodeEliminate->padre->izq = nodeNew;
		
	}else if(nodeEliminate->date == nodeEliminate->padre->der->date){
		nodeEliminate->padre->der = nodeNew;
	}
	
	
	if(nodeNew){
		nodeNew->padre = nodeEliminate->padre;	
	}
}
void destroyNode(Node *arbol){
	arbol->izq = NULL;
	arbol->der = NULL;
	
	delete arbol;
}
