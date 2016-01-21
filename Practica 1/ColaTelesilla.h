#ifndef COLATELESILLA_H
#define COLATELESILLA_H

#include<iostream>

class NodoTelesilla				//Declaracion del nodotelesilla con su informacion
{
private:
	char valor[6];		//informacion en un char de tamaño 6 5+fin
	NodoTelesilla *siguiente;	//puntero al siguiente nodo
	friend class ColaTelesilla;	//clase amiga

public:
	NodoTelesilla(char v[6], NodoTelesilla *sig = NULL)	//constructor
	{
		valor[0] = v[0];		//asignacion de los valores
		valor[1] = v[1];
		valor[2] = v[2];
		valor[3] = v[3];
		valor[4] = v[4];
		siguiente = sig;		//asignacion del puntero sig = NULL al iniciar, luego se modifica al añadir o borrar
	}
};
typedef NodoTelesilla *pnodoTelesilla;//un *pnodoTelesilla es un tipo definido de NodoTelesilla

class ColaTelesilla				//clase ColaTelesilla
{
public:							//funciones
	ColaTelesilla() :fin(NULL), frente(NULL) ,elementos(0){}	//constructor con fin y frente a NULL ya que empieza con 0 nodos y 0 elementosa
	~ColaTelesilla();
	void encolarTelesilla(char v[6]);
	void desencolarTelesilla(int bajar);
	bool vaciaTelesilla();
	void mostrarPrimeroTelesilla();
	int tamanioTelesilla();
	void mostrarTelesilla();

private:						//variables de la cola
	pnodoTelesilla frente, fin;	//nodotelesilla frente y fin de la cola para poder trabajar con los nodos
	int elementos;				//elementos
};


#endif
