#include "Cola.h"
#include <iostream>

using namespace std;

//Destructor
Cola::~Cola()
{
	while (frente) desencolar();//Va desencolando hasta que se terminan los objetos dentro de la cola
}

//Añadir elementos a la Cola
void Cola::encolar(char v)				//funcion para encolar los elementos a la que se le pasa si es adulto o niño
{
	pnodo nuevo;
	nuevo = new Nodo(v);				//se crea un nuevo nodo con la variable que dice si es A adulto o N niño

	if (fin) fin->siguiente = nuevo;	// Si cola no vacía, se añade el nuevo a continuación de ultimo
	fin = nuevo;						//El último elemento de la cola es el nuevo nodo
	if (!frente)frente = nuevo;			//Si es el primero poner como frente
}

char Cola::desencolar()					//funcion para eliminar de la lista el primer elemento y retornar el valor que tiene si es niño o adulto
{
	if (vacia())						//Si esta vacia e intentamos da error
	{
		cout << endl;
		cout << "No se puede desencolar porque la cola esta vacia revisar el codigo" << endl;
		return ' ';
	}
	else
	{
		pnodo nodo;							//nodo aux
		char v;								//variable para guardar el valor de lo extraido
		nodo = frente;						//asignamos el frente
		frente = nodo->siguiente;			//se pasa el valor para el proximo despues de desencolar
		v = nodo->valor;					//se extrae el valor
		delete nodo;						//se elimina
		if (!frente)fin = NULL;				//si es el ultimo se pasa a null
		return v;							//retornamos el valor
	}
}

bool Cola::vacia()							//funcion para saber si esta vacio
{
	return frente == NULL;
}

char Cola::mostrarPrimero()					//Funcion que muestra el primero de la cola
{
	Nodo *aux;								//nodo aux
	aux = frente;							//asignamos el frente
	return aux->valor;						//retornamos el valor
}

int Cola::tamanio()							//Funcion que retorna el tamaño mismo planteamiento que las otras
{
	Nodo *aux;
	int suma = 0;
	aux = frente;

	while (aux != NULL)
	{
		aux = aux->siguiente;
		suma++;
	}
	return suma;
	delete aux;
}

void Cola::mostrar()					//Muestra todos los compoentes
{
	Nodo *aux;							//nodo aux

	aux = frente;						//asignamos el frente

	cout << "Contenido de la cola " << numCola << ": ";
	if (aux==NULL)						//Si esta vacia mensaje de error
	{
		cout << "La cola esta vacia.";
	}
	else
	{
		while (aux != NULL)				//Si no va mostrando hasta terminar la cola
		{
			cout << aux->valor << " ";
			aux = aux->siguiente;
		}
	}
	cout << endl;
	delete aux;							//se elimina el aux
}
