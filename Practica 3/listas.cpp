#include "listas.h"
#include <iostream>
#include <iomanip>

using namespace std;


Lista::~Lista()				//destructor
{
	pNodoLista aux;
	while (primero)
	{
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
}

void Lista::inicializar()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

pNodoLista Lista::getNodoLista(int d)
{
	pNodoLista aux;
	aux = primero;

	while (aux->dato!=d && (aux->siguiente)!=NULL)
	{
		aux = aux->siguiente;
	}
    return aux;
}

pNodoLista Lista::getPrimero()
{
    return primero;
}

pNodoLista Lista::getUltimo()
{
    return ultimo;
}

void Lista::insertarNodoLista(int d, int p)                 //inserta nodoLista por la izquierda
{
	pNodoLista aux;
	aux = new NodoLista(d, p);
	aux->siguiente = primero;
	primero = aux;
	if (ultimo==NULL) ultimo = aux;
	longitud++;
}

void Lista::insertarFinalNodoLista(int d, int p)			//inserta nodoLista por la derecha
{
	pNodoLista aux;
	aux = new NodoLista(d, p);
	if (ultimo!=NULL) ultimo->siguiente = aux;
	ultimo = aux;
	if (primero==NULL) primero = aux;
	longitud++;
}

void Lista::borrarNodoLista(int d)			//elimina uno de los nodos
{
	pNodoLista anterior;
	pNodoLista aux;
	anterior = primero;
	aux = primero;

    if(primero!=NULL)
    {
        while (aux->dato!=d && (aux->siguiente)!=NULL)
        {
            aux = aux->siguiente;
            if (aux==anterior->siguiente->siguiente)
                anterior = anterior->siguiente;
        }
        if(aux->dato==d)
        {
            if (aux==primero)
            {
                primero = aux->siguiente;
            }
            else
            {
                anterior->siguiente = aux->siguiente;
                if (aux==ultimo)
                {
                    ultimo = anterior;
                }
            }
            aux->siguiente = NULL;
            if (longitud!=0) longitud--;
        }
    }
}

bool Lista::esListaVacia()				//comprueba si esta vacia la lista
{
	return primero==NULL;
}

void Lista::mostrarLista()				//muestra todo el contenido
{
	pNodoLista aux;
	aux = primero;
    if(aux == NULL) cout << " Lista Vacia" << endl;
	while (aux)
	{
		cout << "Dato: " << aux->dato;
		cout << "  Peso: " << aux->peso << endl;
		aux = aux->siguiente;
	}
	cout << endl;
}

int Lista::getLongitud()				// Devuelve la longitud
{
	return longitud;
}
