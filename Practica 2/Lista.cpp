#include "Lista.h"
#include <iostream>

using namespace std;

Lista::~Lista()				//destructor
{
	pnodo aux;
	while (frente)
	{
		aux = frente;
		frente = frente->siguiente;
		delete aux;
	}
	actual = NULL;
}

void Lista::insertarNodoVagon(int v, char *cV, char *oV, char * dV, bool valor)//añade un nuevo nodo en este caso vagon el cual recibe el numero del tren de aquel al que se engancha se añaden a partir del tren
{
	pnodo aux;
	aux = new Nodo(v, cV, frente->nTren, oV, dV, valor, NULL);
	fin->siguiente = aux;
	fin = aux;
	tamanio++;
}

void Lista::insertarNodoTren(int v, char * cV, int nT, char * o, char * d, bool valor)//añadimos el nodo tren que es el primero
{
	frente = new Nodo(v, cV, nT, o, d, valor, NULL);
	fin = frente;
	tamanio++;
}

void Lista::insertarFinal(pnodo auxiliar)			//añade un nodo concreto al final
{
	fin->siguiente = auxiliar;
	fin = auxiliar;
	auxiliar->nTren = frente->nTren;				//actualizamos el numero del tren en el que esta enganchado
	tamanio++;
}

pnodo Lista::borrarNodo(int v)			//elimina uno de los nodos
{
	pnodo anterior=NULL;
	pnodo auxiliar = NULL;

	actual = frente;
	while (actual->nVagon!=v && (actual->siguiente)!=NULL)
	{
		anterior = actual;
		actual = actual->siguiente;
	}
	if (actual==frente)
	{
		frente = actual->siguiente;
	}
	else
	{
		anterior->siguiente = actual->siguiente;
		if (actual==fin)
		{
			fin = anterior;
		}
	}
	tamanio--;
	actual->siguiente = NULL;
	auxiliar = actual;
	return auxiliar;
}

bool Lista::listaVacia()				//comprueba si esta vacia la lista
{
	return frente==NULL;
}

void Lista::mostrarLista()				//muestra todo el contenido
{
	Nodo *aux;

	aux = frente;
	while (aux)
	{
		mostrarContenido(aux);			//llamada a mostrar la informacion
		aux = aux->siguiente;
	}
	delete aux;
	cout << endl;
}

void Lista::esSiguiente()				//avanza en 1 el actual
{
	if (actual)
	{
		actual = actual->siguiente;
	}
}

void Lista::esPrimero()					//pone actual al principio sin contar el tren 1 (inicialmente se ponia a frente)
{
	actual = frente->siguiente;
}

void Lista::esUltimo()
{
	esPrimero();
	if (!listaVacia())
	while (actual->siguiente)
	esSiguiente();
}

bool Lista::esActual()
{
	return actual !=NULL;
}

int Lista::valorActual()				//numero del vagon en el que estamos
{
	return actual->nVagon;
}

int Lista::numTren()					//retorna el numero del tren vagon 1
{
	return frente->nTren;
}

char * Lista::origenTren()				//retorna el origen del tren usado para asignar a los vagones cuando se añaden al principio destino aleatorio
{
	return frente->origen;
}

char * Lista::destinoTren()				//retorna el destino del tren 1 vagon
{
	return frente->destino;
}

char * Lista::destinoVagon()			//retorna el destino del vagon
{
	return actual->destino;
}

void Lista::mostrarContenido(pnodo x)	//muestra los datos en funcion del tipo
{
	if (x->locomotora) {
        cout<<"Numero de locomotora: "<<x->nTren<<"  ";
        cout<<"  Origen:	"<<x->origen<<"  ";
        cout<<"  Destino: "<<x->destino<<endl;
	}
	else {
		cout<<"Numero de vagon:  "<<x->nVagon<<"  ";
		cout<<"  Numero de locomotora: "<<x->nTren<<"  ";
		cout<<"  Carga:	"<<x->carga<<"  ";
		cout<<"  Origen:	"<<x->origen<<"  ";
		cout<<"  Destino: "<<x->destino<<endl;
	}
}

int Lista::tamanioTren()				//retorna el tamaño del tren
{
	return tamanio;
}

bool Lista::comprobarVagones()			//comprueba si hay algun vagon erroneo
{
	Nodo *aux;
	bool distinto = false;

	aux = frente->siguiente;

	while (aux)
	{
		if (frente->destino!=aux->destino)
		{
			distinto = true;
		}
		aux = aux->siguiente;
	}
	delete aux;
	return distinto;
}

int Lista::vagonErroneoUltimo()		//da el numero del vagon erroneo ultimo
{
	Nodo *aux;
	int num = 0;
	aux = frente->siguiente;

	while (aux)
	{
		if (frente->destino != aux->destino)
		{
			num = aux->nVagon;
		}
		aux = aux->siguiente;
	}
	delete aux;
	return num;
}

char * Lista::destinoVagonPosicion(int x)
{
	pnodo aux;

	aux = frente;
	while (aux->nVagon != x)
	{
		aux = aux->siguiente;
	}
	return aux->destino;
}

int Lista::numeroCargas(char *y)
{
    int cantidad = 0;
    Nodo *aux;

    aux = frente;
    while (aux)
    {
        if (aux->carga == y)
        {
            mostrarContenido(aux);
            cantidad++;
        }
        aux = aux->siguiente;
    }
    delete aux;
    return cantidad;
}
