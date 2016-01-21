#ifndef ARBOLES_H
#define ARBOLES_H

#include<iostream>


class Nodo{
private:
	int dato;
	Nodo *izquierdo;
	Nodo *derecho;
	int peso;
	friend class ArbolABB;

public:
	Nodo(const int dat, int ps, Nodo *izq = NULL, Nodo *der = NULL) : dato(dat), izquierdo(izq), derecho(der) ,peso(ps) {}
};
typedef Nodo *pNodo;

class ArbolABB {
public:
	// Constructor y destructor b�sicos:
	ArbolABB() {raiz = NULL; pesoTotal = 0; pesoIzquierda = 0; pesoDerecha = 0; numNodos = 1; altura = 0;}
	~ArbolABB() { podar(raiz); }

	// Insertar en �rbol ordenado
	void insertar(const int dat, int ps);

	// Borrar un elemento del �rbol:
	void borrar(const int dat);

	// Funci�n de b�squeda:
	bool buscar(const int dat);

	// Comprobar si est� un nodo vac�o:
	bool esVacio(Nodo *r) { return r==NULL; }

	// Comprobar si el nodo es una hoja:
	bool esHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }

	// Devuelve n�mero de nodos
	int getNumNodos();

	// Devuelve altura del �rbol
	int getAltura();

	// Calcula la altura del �rbol
	void calcularAlturaArbol(Nodo *nodo, int a);

	// Devuelve la altura de un nodo:
	int alturaNodo(const int dat);

	// Devuelve el valor del peso total del arbol
	int getPesoTotal();

	// Devuelve el valor que pesa la izq
	int getPesoIzquierda();

	// Devuelve el valor que pesa la der
	int getPesoDerecha();

	// Devolver el peso de un nodo concreto
	int pesoEspecifico(const int dat);

	// Comprobar que se cumple el margen de peso
	bool estaEquilibrado();

	// Funci�n que muestra un nivel del �rbol
	void mostrarNivel(Nodo *raid, int level, int i);

	// Funci�n que retorna la ra�z para realizar algunos c�lculos
	Nodo *getRaiz();

	// Poda: borrar todos los nodos a partir de uno, inclu�do
	void podar(Nodo *nodo);

	// Inicializa valores del �rbol
	void inicializar();

	// Funciones que muestran los nodos en diferentes �rdenes
	void inOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
	void preOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
	void postOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);

private:
	Nodo *raiz;
    int pesoTotal;
	int pesoDerecha;
	int pesoIzquierda;
	int numNodos;
	int altura;
};

#endif
