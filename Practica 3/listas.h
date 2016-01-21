#ifndef LISTAS_H
#define LISTAS_H

#include<iostream>


class NodoLista							//Declaracion del nodo que forman las listas
{
private:							//Variables y punteros a informacion
	int dato;
	int peso;
	NodoLista *siguiente;				//puntero al siguiente
	friend class Lista;				//clase amiga

public:
	NodoLista(int d, int p, NodoLista *sig = NULL)	//constructor con la informacion y *sig se pasa como inicial NULL y luego va cambiando
	{
		dato = d;
		peso = p;
		siguiente = sig;
	}
	int getPeso() {return peso;}
	NodoLista *getSiguiente() {return siguiente;}
};
typedef NodoLista *pNodoLista;				//un *pNodoLista es un tipo definido de NodoLista

class Lista
{
public:
	Lista() : primero(NULL), ultimo(NULL), longitud(0) {}   //constructor
	~Lista();                                               //destructor
	void inicializar();
	pNodoLista getNodoLista(int d);
	pNodoLista getPrimero();
	pNodoLista getUltimo();
	void insertarNodoLista(int d, int p);
	void insertarFinalNodoLista(int d, int p);
	void borrarNodoLista(int d);
	bool esListaVacia();
	void mostrarLista();
	int getLongitud();

private:
	pNodoLista primero, ultimo;			//definimos dos pNodoLista primero y ultimo
	int longitud;						//variable para la longitud
};

#endif
