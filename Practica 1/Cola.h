#ifndef COLA_H
#define COLA_H

#include<iostream>

class Nodo							//Declaracion del nodo que forman las colas
{
private:							//variables y punteros
	char valor;
	Nodo *siguiente;
	friend class Cola;				//clase amiga

public:
	Nodo(char v, Nodo *sig = NULL)	//constructor *sig se pas como inicial NULL y luego va cambiando
	{
		valor = v;
		siguiente = sig;
	}
};
typedef Nodo *pnodo;				//un *Pnodo es un tipo definido de nodo

class Cola
{
public:
	Cola(int a) :fin(NULL), frente(NULL), numCola(a) {}//constructor con fin y frente a NULL ya que empieza con 0 nodos y el numero de cola que es
	~Cola();
	void encolar(char v);			//funciones varias
	char desencolar();
	bool vacia();
	char mostrarPrimero();
	int tamanio();
	void mostrar();

private:
	pnodo frente, fin;				//definimos dos pnodo frente y fin
	int numCola;					//numero de cola que es para poder ver mejor el programa
};


#endif
