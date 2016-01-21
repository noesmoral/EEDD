#include "arboles.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Insertar un int en el árbol ABB
void ArbolABB::insertar(const int dat, int ps)
{
	Nodo *padre = NULL;
	Nodo *aux = raiz;

	// Buscar el int en el árbol, manteniendo un puntero al nodo padre
	while (!esVacio(aux) && dat != aux->dato) {
		padre = aux;
		if (dat > aux->dato) aux = aux->derecho;
		else if (dat < aux->dato) aux = aux->izquierdo;
	}

	// Si se ha encontrado el elemento, regresar sin insertar
	if (!esVacio(aux)) return;
	// Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
	// el nodo raiz
	if (esVacio(padre)) {
		raiz = new Nodo(dat, ps);
		numNodos = 1;
		pesoTotal += ps;
	}
	// Si el int es menor que el que contiene el nodo padre, lo insertamos
	// en la rama izquierda
	else if (dat < padre->dato) {
		if (dat<raiz->dato)
		{
			pesoIzquierda += ps;
		}
		else {
			pesoDerecha += ps;
		}
		padre->izquierdo = new Nodo(dat, ps);
		numNodos++;
		pesoTotal += ps;
	}
	// Si el int es mayor que el que contiene el nodo padre, lo insertamos
	// en la rama derecha
	else if (dat > padre->dato) {
		if (dat<raiz->dato)
		{
			pesoIzquierda += ps;
		}
		else {
			pesoDerecha += ps;
		}
		padre->derecho = new Nodo(dat, ps);
		numNodos++;
		pesoTotal += ps;
	}
}


// Eliminar un elemento de un árbol ABB
void ArbolABB::borrar(const int dat)
{
	Nodo *padre = NULL;
	Nodo *nodo;
	Nodo *actual = raiz;

	int aux;

	pesoTotal -= pesoEspecifico(dat);//restar el peso específico de la bola, en caso de no estar resta 0

	// Mientras sea posible que el valor esté en el árbol
	while (!esVacio(actual)) {
		if (dat == actual->dato) { // Si el valor está en el nodo actual
			if (esHoja(actual)) { // Y si además es un nodo hoja: lo borramos
				if (padre) { // Si tiene padre (no es el nodo raíz)
						   // Anulamos el puntero que le hace referencia
					if (padre->derecho == actual) padre->derecho = NULL;
					else if (padre->izquierdo == actual) padre->izquierdo = NULL;
				}
				delete actual; // Borrar el nodo
				numNodos--;
				return;
			}
			else { // Si el valor está en el nodo actual, pero no es hoja
				   // Buscar nodo
				padre = actual;
				// Buscar nodo más izquierdo de rama derecha
				if (actual->derecho) {
					nodo = actual->derecho;
					while (nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				// O buscar nodo más derecho de rama izquierda
				else {
					nodo = actual->izquierdo;
					while (nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				// Intercambiar valores de nodo a borrar o nodo encontrado
				// y continuar, cerrando el bucle. El nodo encontrado no tiene
				// porqué ser un nodo hoja, cerrando el bucle nos aseguramos
				// de que sólo se eliminan nodos hoja.
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}
		else { // Todavía no hemos encontrado el valor, seguir buscándolo
			padre = actual;
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
}

// Buscar un dato en el árbol
bool ArbolABB::buscar(const int dat)
{
	Nodo *aux = raiz;

	// Todavía puede aparecer, ya que quedan nodos por mirar
	while (!esVacio(aux)) {
		if (dat == aux->dato) return true; // int encontrado
		else if (dat > aux->dato) aux = aux->derecho; // Seguir
		else if (dat < aux->dato) aux = aux->izquierdo;
	}
	return false; // No está en árbol
}

// Devuelve el número de nodos
int ArbolABB::getNumNodos()
{
	return numNodos;
}

// Devuelve la altura del árbol
int ArbolABB::getAltura()
{
    return altura;
}

// Función para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolABB::calcularAlturaArbol(Nodo *nodo, int a)
{
	// Recorrido postorden
	if (nodo->izquierdo) calcularAlturaArbol(nodo->izquierdo, a+1);
	if (nodo->derecho)   calcularAlturaArbol(nodo->derecho, a+1);
	// Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	// árbol, actualizamos la altura actual del árbol
	if (esHoja(nodo) && a > altura) altura = a;
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::alturaNodo(const int dat)
{
	int alt = 0;
	Nodo *aux = raiz;

	// Todavía puede aparecer, ya que quedan nodos por mirar
	while (!esVacio(aux)) {
		if (dat == aux->dato) return alt; // int encontrado
		else {
			alt++; // Incrementamos la altura, seguimos buscando
			if (dat > aux->dato) aux = aux->derecho;
			else if (dat < aux->dato) aux = aux->izquierdo;
		}
	}
	return -1; // No está en árbol
}

// Retorna el valor actual del total del árbol
int ArbolABB::getPesoTotal()
{
	return pesoTotal;
}

// Retorna el valor de lado izquierdo
int ArbolABB::getPesoIzquierda()
{
	return pesoIzquierda;
}

// Retorna el valor del lado derecho
int ArbolABB::getPesoDerecha()
{
	return pesoDerecha;
}

// Da la información de un número concreto del árbol
int ArbolABB::pesoEspecifico(const int dat)
{
	Nodo *aux = raiz;

	// Todavía puede aparecer, ya que quedan nodos por mirar
	while (!esVacio(aux)) {
		if (dat == aux->dato) return aux->peso; // int encontrado devolver el peso
		else if (dat > aux->dato) aux = aux->derecho; // Seguir
		else if (dat < aux->dato) aux = aux->izquierdo;
	}
	return 0; // No está en árbol así que peso 0
}

// Verifica que está equilibrado
bool ArbolABB::estaEquilibrado()
{
	//variable aux para los cálculos
	double resultado = 0.0;

	//calculamos el % de variación entre los dos lados
	if (pesoIzquierda > pesoDerecha){
        resultado = pesoIzquierda - pesoDerecha;
	}
	else{
        resultado = pesoDerecha - pesoIzquierda;
	}

	cout << "La diferencia de pesos es de " << resultado << endl;
	resultado = resultado * 100;
	resultado = resultado / pesoTotal;
	cout << "Lo que supone un desequilibrio del " << resultado << "%" << endl;
	cout << endl;

	//devolver si ha terminado o no
	if (resultado<2.0){
		return true;
	}
	else {
		return false;
	}
}

// Muestra todos los nodos de un nivel concreto
void ArbolABB::mostrarNivel(Nodo *raid, int level, int i)
{
    int esp;

    switch (i)
	{   // Ajustes de espacios para mostrar según el nivel
		case 0:	esp = 49; break;
		case 1: esp = 31; break;
		case 2: esp = 17; break;
		case 3:	esp = 8; break;
		case 4:	esp = 3; break;
		default: esp = 0; break;
	}

	if (raid==NULL)	//Si es nulo mostrar una equis para evitar fallos lo que quiere decir que ahí no hay nada ni en sus inferiores y termina
	{
		cout << setw (esp+3) << "X";
	}
	else {
		if (level == 0) {	//si ya hemos llegado donde queremos mostramos
			cout << setw (esp) << raid->dato << "(" << raid->peso << ")";
		}
		else {		//si aún no hemos llegado entonces volvemos a llamar pasando otro nivel inferior
			mostrarNivel(raid->izquierdo, level - 1, i);
			mostrarNivel(raid->derecho, level - 1, i);
		}
	}
}

// Retorna la raíz
Nodo *ArbolABB::getRaiz()
{
	return raiz;
}

// Poda: borrar todos los nodos a partir de la raíz, incluída
void ArbolABB::podar(Nodo *nodo)
{
//	// Algoritmo recursivo, recorrido en postorden
    if (nodo) {
        podar(nodo->izquierdo);
        podar(nodo->derecho);
        delete nodo;
        nodo = NULL;
    }
}

void ArbolABB::inicializar() {
    raiz = NULL; pesoTotal = 0; pesoIzquierda = 0; pesoDerecha = 0; numNodos = 1; altura = 0;
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::inOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) inOrden(func, nodo->izquierdo, false);
	func(nodo->dato);
	if (nodo->derecho) inOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::preOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	func(nodo->dato);
	if (nodo->izquierdo) preOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) preOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::postOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) postOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) postOrden(func, nodo->derecho, false);
	func(nodo->dato);
}
