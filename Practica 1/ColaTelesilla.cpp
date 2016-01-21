#include "ColaTelesilla.h"
#include <iostream>

using namespace std;

//Destructor de la cola
ColaTelesilla::~ColaTelesilla()
{
}


void ColaTelesilla::encolarTelesilla(char v[6])	//Funcion encolar la cual recibe un char de tamaño 6 ya que necesita 5 para los esquiadores unidos y 1 par el final de linea
{
	if (elementos==10)						//Mensaje de error en caso de haber ya 10 elementos
	{
		cout << "No se puede encolar la cola esta completa" << endl;
	}
	else
	{
		pnodoTelesilla nuevo;
		nuevo = new NodoTelesilla(v);		//se crea un nuevo nodo con la cadena de los esquiadores
		if (fin) fin->siguiente = nuevo;    //Si cola no vacía, se añade el nuevo a continuación de ultimo
		fin = nuevo;						//El último elemento de la cola es el nuevo nodo
		if (!frente)frente = nuevo;			//Si es el primero poner como frente
		elementos++;						//Aumentamos el numero de elementos encolados
	}
}

void ColaTelesilla::desencolarTelesilla(int bajar)	//Funcion en la cual extraenos los elementos de la cola, se pasa el numero de elementos a extraer
{
	for (size_t i = 0; i < bajar; i++)
	{
		if (vaciaTelesilla())						//Si intentamos sacar mas de los que hay error
		{
			cout << endl;
			cout << "No se puede desencolar porque la cola esta vacia revisar el codigo" << endl;
			break;
		}
		else
		{
			pnodoTelesilla nodo;			//creamos un nodo aux
			nodo = frente;					//le asignamos como si fuera el frente
			cout<<nodo->valor<<" ";			//Operamos con el
			frente = nodo->siguiente;		//reasignamos
			delete nodo;					//borramos el nodo aux
			if (!frente)fin = NULL;			//si es el final
			elementos--;					//decrementa los elementos de la cola
		}
	}
}

bool ColaTelesilla::vaciaTelesilla()	//Funcion que retorna si esta vacia o no la cola
{
	return frente == NULL;
}

void ColaTelesilla::mostrarPrimeroTelesilla()	//Funcion que muestra el telesilla en su primera posicion para posibles comprobaciones
{
	if (vaciaTelesilla()) { cout << "La cola se encuentra vacia por lo que no se puede mostrar nada" << endl; }	//certifica que no esta vacio o da error
	else {
		cout<<frente->valor<<endl;				//muestra el contenido
	}
}

int ColaTelesilla::tamanioTelesilla()		//Funcion que retorna el tamaño ocupado
{
	return elementos;
}

void ColaTelesilla::mostrarTelesilla()		//Funcion que muestra todo el telesilla
{
	if (vaciaTelesilla())					//si esta vacio da error y muestra el mensaje
	{
		cout << "El telesilla se encuentra vacio" << endl;
	}
	else
	{										//en caso contrario muestra
		NodoTelesilla *aux;					//nodoTelesilla aux

		aux = frente;						//asignamos a aux el frente

		while (aux != NULL)					//muestra hasta el final del telesilla
		{
			cout<<aux->valor<<" ";			//muestra el contenido
			aux = aux->siguiente;			//aux pasa al siguiente a mostrar
		}
		cout << endl;
		delete aux;							//eliminamos el aux
	}
}
