#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string>

#include "Cola.h"
#include "ColaTelesilla.h"
#include "Esquiador.h"

#include <iostream>
#include <ctime>

using namespace std;

//Declaracion Gobal de las colas para evitar errores en las ejecuciones de las funciones

//creamos las colas de las filas
Cola cola1(1);
Cola cola2(2);
Cola cola3(3);
Cola cola4(4);
Cola cola5(5);

//Se crea el telesilla
ColaTelesilla Telesilla;

void mostrarColas() {	//Funcion que muestra las colas
	cout << "Estado actual de las colas: " << endl;
	cola1.mostrar();
	cola2.mostrar();
	cola3.mostrar();
	cola4.mostrar();
	cola5.mostrar();
}

void montar(int num) {	//funcion a la que le pasamos el numero de elementos a sacar de las colas y a encolar en el telesilla (max=10)

	int veces = 0;	//variables

	cout << "Enpieza el traspaso de los esquiadores a sus gondolas: " << endl;

		for (size_t i = 0; i < num;)	//bucle para el numero dado
		{
			if (cola1.vacia() || cola2.vacia() || cola3.vacia() || cola4.vacia() || cola5.vacia())	//si estan las colas vacias error
			{
				cout << endl;
				cout << "Error al intentar sacar de alguna de las filas por encontrarse vacias" << endl;
				cout << endl;
				break;
			}
			else if (cola1.mostrarPrimero() == 'N' && cola2.mostrarPrimero() == 'N' && cola3.mostrarPrimero() == 'N' && cola4.mostrarPrimero() == 'N' && cola5.mostrarPrimero() == 'N' && veces<3)
                //en caso de entrar 5 niños se pasan al final de la cola 2 de ellos, con un limite de 3 veces para evitar que ocurra el caso de que queden 5 niños al final de las colas
			{
				cout << endl;
				cout << "No pueden montar 5 ninios por lo que los ninios 1 y 3 pasan al final de la cola" << endl;
				cola1.encolar(cola1.desencolar());
				cola3.encolar(cola3.desencolar());
				mostrarColas();
				cout << endl;
				cout << "Continuamos con la ejecucion" << endl;
				cout << endl;
				veces++;
			}
			else    //Continua normal
			{
				if (Telesilla.tamanioTelesilla() == 10 )	//si el telesilla esta lleno error
				{
					cout << endl;
					cout << "Error al intentar añadir al telesilla ya que esta completo" << endl;
					cout << endl;
					break;
				}
				else         //si no desmonta y monta a los esquiadores en el telesilla y de las colas respectivamente
				{
					char auzz[6] = "     ";
					auzz[0] = cola1.desencolar();
					auzz[1] = cola2.desencolar();
					auzz[2] = cola3.desencolar();
					auzz[3] = cola4.desencolar();
					auzz[4] = cola5.desencolar();
					printf("Extraemos a los esquiadores: %s\n", auzz);
					Telesilla.encolarTelesilla(auzz);
					i++;
				}
			}
		}
}

void crearMontar(int total) {		//crea y mete a los esquiadores en las colas se pasa el numero de esquiadores que queremos y si se pasan un numero distinto de 100 habria que cambiar la simulacion

	//Declaracioon de variables
	int caso, veces = 0;
	srand(time(NULL));	//variable para el randon

	cout << "Se crean y adjudica a cada esquiador una fila" << endl;

	//Creamos y metemos a 50 esquiadores aleatorios en 5 filas de forma aleatoria
	for (size_t i = 0; i < total; i++)
	{
		Esquiador esquiador;	//crea el esquiador
		switch (i % 5)			//insertado en las filas
		{
		case 0: cola1.encolar(esquiador.categoria()); break;
		case 1: cola2.encolar(esquiador.categoria()); break;
		case 2: cola3.encolar(esquiador.categoria()); break;
		case 3: cola4.encolar(esquiador.categoria()); break;
		case 4: cola5.encolar(esquiador.categoria()); break;
		default:				//en el caso de que algo falle se destruye el esquiador
			esquiador.~Esquiador();
			break;
		}
	}
}

int main()	//Funcion MAIN	SIMULACION
{

	//informacion de la ejecucion simulada del programa

	cout << "EMPEZAMOS" << endl;
	cout << "Se ha creado el telesilla" << endl;
	cout << "Se han creado las colas" << endl;
	cout << endl;

	//creamos y encolamos los esquiadores pasando el numero de esquiadores a crear
	crearMontar(100);	//SI  SE PASAN MENOS DE 100 DARA AVISO DE QUE NO SE PUEDEN SACAR MAS ESQUIADORES (PROBAR CON 70-95 PARA VER EL RESULTADO)
	cout << endl;

	//Mostramos las colas
	mostrarColas();

	cout << endl;
	cout << endl;
	cout << "SE ABREN LAS PISTAS" << endl;
	cout << endl;
	cout << endl;

	montar(10);		//SI SE INTENTAN MONTAR MAS DE 10 DARA AVISO DE ERROR (PROBAR CON UN NUMERO MAYOR A 10 PARA VER LO QUE OCURRE)

	cout << endl;
	cout << "El telesilla y su contenido es: " << endl;
	Telesilla.mostrarTelesilla();
	cout << endl;

	cout << "Bajan 5 esquiadores del telesilla " << endl;
	Telesilla.desencolarTelesilla(5); //SI SE INTENTAN DESMONTAR MAS DE LOS QUE HAY MOSTRARA UN AVISO DEL PROBLEMA (PROBAR CON 11 PARA VER EL RESULTADO)

	cout << endl;
	cout << endl;
	cout << "El telesilla despues de descender su contenido es: " << endl;
	Telesilla.mostrarTelesilla();
	cout << endl;

	cout << "Bajan otros 5 esquiadores del telesilla " << endl;
	Telesilla.desencolarTelesilla(5);

	cout << endl;
	cout << endl;
	cout << "El telesilla despues de descender su contenido es: " << endl;
	Telesilla.mostrarTelesilla();
	cout << endl;

	//Segundo viaje
	cout << "Segundo viaje" << endl;
	mostrarColas();
	cout << endl;
	cout << endl;
	montar(10);
	cout << endl;
	cout << endl;

	cout << endl;
	cout << "El telesilla y su contenido es: " << endl;
	Telesilla.mostrarTelesilla();
	cout << endl;

	mostrarColas();

	cout << endl;
	cout << endl;
	cout << "Bajan los ultimos esquiadores del telesilla " << endl;
	Telesilla.desencolarTelesilla(10);

	cout << endl;
	cout << endl;
	cout << "El telesilla despues de descender su contenido es: " << endl;
	Telesilla.mostrarTelesilla();
	cout << endl;
	cout << endl;

	cout << "Pulsa cualquier tecla para terminar" << endl;
	getchar();
	return 0;
}
