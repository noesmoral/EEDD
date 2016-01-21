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
	// Constructor y destructor básicos:
	ArbolABB() {raiz = NULL; pesoTotal = 0; pesoIzquierda = 0; pesoDerecha = 0; numNodos = 1; altura = 0;}
	~ArbolABB() { podar(raiz); }

	// Insertar en árbol ordenado
	void insertar(const int dat, int ps);

	// Borrar un elemento del árbol:
	void borrar(const int dat);

	// Función de búsqueda:
	bool buscar(const int dat);

	// Comprobar si está un nodo vacío:
	bool esVacio(Nodo *r) { return r==NULL; }

	// Comprobar si el nodo es una hoja:
	bool esHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }

	// Devuelve número de nodos
	int getNumNodos();

	// Devuelve altura del árbol
	int getAltura();

	// Calcula la altura del árbol
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

	// Función que muestra un nivel del árbol
	void mostrarNivel(Nodo *raid, int level, int i);

	// Función que retorna la raíz para realizar algunos cálculos
	Nodo *getRaiz();

	// Poda: borrar todos los nodos a partir de uno, incluído
	void podar(Nodo *nodo);

	// Inicializa valores del árbol
	void inicializar();

	// Funciones que muestran los nodos en diferentes órdenes
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
