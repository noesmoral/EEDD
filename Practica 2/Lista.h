#ifndef LISTA_H
#define LISTA_H

#include<iostream>

class Nodo							//Declaracion del nodo que forman las colas
{
private:							//Variables y punteros a informacion
	int nVagon;
	char *carga;
	int nTren;
	bool locomotora;
	char *origen;
	char *destino;
	Nodo *siguiente;				//puntero al siguiente
	friend class Lista;				//clase amiga

public:
	Nodo(int v, char *cV, int nT, char *o, char * d,bool valor, Nodo *sig = NULL)	//constructor con la informacion y *sig se pasa como inicial NULL y luego va cambiando
	{
		nVagon = v;					//variables con la informacion del tren
		carga = cV;
		nTren = nT;
		locomotora = valor;
		origen = o;
		destino = d;
		siguiente = sig;
	}
};
typedef Nodo *pnodo;				//un *Pnodo es un tipo definido de nodo

class Lista
{
public:
	Lista() : frente(NULL), fin(NULL), actual(NULL), tamanio(0) {}//constructor con fin y frente a NULL ya que empieza con 0 nodos
	~Lista();							//destructor
	void insertarNodoVagon(int v, char *cV, char *o, char * d,bool valor);			//funciones insercion del vagon
	void insertarNodoTren(int v, char *cV, int nT, char *o, char * d, bool valor);	//insercion de la locomotora
	void insertarFinal(pnodo auxiliar);	//inserta un nodo concreto al final de un tren
	pnodo borrarNodo(int v);			//elimina un nodo concreto (numero de vagon)
	bool listaVacia();					//comprueba si esta vacia
	void mostrarLista();				//muestra todo el tren (llama a mostrar contenido)
	void esSiguiente();
	void esPrimero();
	void esUltimo();
	bool esActual();
	int valorActual();					//numero del vagon en el que estamos
	int numTren();						//numero del tren
	char *origenTren();					//info origen tren
	char *destinoTren();				//info destino tren
	char *destinoVagon();				//info destino vagon
	void mostrarContenido(pnodo x);		//muestra los valores del nodo
	int tamanioTren();					//da el tamaño total del tren
	bool comprobarVagones();			//comprueba que no hay ningun vagon erroneo si es asi false si no true
	int vagonErroneoUltimo();			//da el numero del vagon erroneo ultimo para su busqueda
	char *destinoVagonPosicion(int x);   //devuelve el destino del vagon pasado como parametro
	int numeroCargas(char *y);         //devuelve y muestra la cantidad e informacion de los vagones con esa carga

private:
	pnodo frente, fin, actual;			//definimos dos pnodo frente y fin
	int tamanio;						//variable para el tamaño
};

#endif
