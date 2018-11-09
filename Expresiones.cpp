#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;
struct Nodo{
	char dato;
	struct Nodo *siguiente;
}*inicio,*aux,*actual,*anterior;

void insertarNodo(char);
void eliminarNodo(char);
void mostrarNodos();
int main(int argc, char** argv) {
	inicio=NULL;
	int opcion;
	char eliminarCaracter;
	string expresion;
	do{
        system("cls");
		cout<<"\n Menu "<<endl;
		cout<<"1.- insertar expresion"<<endl;
		cout<<"2.- eliminar caracter"<<endl;
		cout<<"3.- Mostrar expresion"<<endl;
		cout<<"4.- salir"<<endl;
		cin>>opcion;
		switch (opcion){
        case 1:
            cout<<"Inserte expresion: ";
            cin.ignore();
			getline(cin, expresion);
			for(int i=0; i<expresion.length(); i++){
                    insertarNodo(expresion[i]);
			}
			break;
        case 2:
            cout<<"Valor del nodo a borrar: ";
			cin >> eliminarCaracter;
			eliminarNodo(eliminarCaracter);
			break;
        case 3:
            mostrarNodos();
            break;
        case 4:
            break;
        default:
            system("cls");
            break;
		}//fin de switch

	}while(opcion!=4);
	cin.get();
	return 0;
}
void insertarNodo(char valor){
	actual=inicio;
	if(actual==NULL){
			aux=new Nodo();
			aux->dato=valor;
			aux->siguiente=NULL;
			inicio=aux;
	}else{
		while(actual->siguiente!=NULL)
		{
			actual=actual->siguiente;
			}
		aux=new Nodo();
		aux->dato=valor;
		aux->siguiente=NULL;
		actual->siguiente=aux;
	}
}

void eliminarNodo(char valor){
	if(inicio!=NULL){
		aux=NULL;
		actual=inicio;
		while((actual!=NULL) && (actual->dato!=valor)){
			aux=actual;
			actual=actual->siguiente;
		}
		if(actual==NULL){
			cout<<"no encontrado"<<endl;
		}else if(aux==NULL){
			inicio=inicio->siguiente;
			delete actual;
		}else{
			aux->siguiente=actual->siguiente;
			delete actual;
		}
	}
}
void mostrarNodos(){
	actual=inicio;
	cout<<" \nMostrar\n ";
	while(actual!=NULL){
		cout<<" "<<actual->dato<<" ";
		actual=actual->siguiente;
	}
	cout<<"\n";
	system("pause");
}
