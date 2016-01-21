#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include "Lista.h"

#include <vector>
#include <iostream>

using namespace std;

//Creacion de las listas (Trenes) global para poder usarlos en las funciones recolocar y crear contenedores
Lista tren1;
Lista tren2;
Lista tren3;
Lista tren4;
Lista tren5;

//variables Globales con los destinos y cargas para poder operar con los nodos apuntando a estos parametros
char o1[] = "Sevilla";
char o2[] = "Zamora";
char o3[] = "Badajoz";
char o4[] = "Cuenca";
char o5[] = "Albacete";

char d1[] = "Valladolid";
char d2[] = "Zaragoza";
char d3[] = "Burgos";
char d4[] = "Orense";
char d5[] = "Bilbao";

char c1[] = "Coches";
char c2[] = "Comida";
char c3[] = "Combustible";
char c4[] = "Dinero";
char c5[] = "Medicamentos";

vector<int> repetidos;	//vector con los numero de los vagones creados para comprobar si estan repetidos

//funciones auxiliares
char * dE() {	//Auxiliar para elegir aleatoriamente el destino
	int a = rand() % 5;
		switch (a)
		{
		case 0:	return  d1; break;
		case 1: return  d2; break;
		case 2: return  d3; break;
		case 3:	return  d4; break;
		default: return	d5; break;
		}
}

char * cA() {	//Auxiliar para elegir aleatoriamente la carga
	int a = rand() % 5;
		switch (a)
		{
		case 0:	return  c1; break;
		case 1: return  c2; break;
		case 2: return  c3; break;
		case 3:	return  c4; break;
		default: return	c5; break;
		}
}

bool noRepetidoVagon(int aux) {		//verificacion que los vagones no tienen los numeros repetidos entre ellos
	if (repetidos.empty())
	{
		repetidos.push_back(aux);	//si es el primero le almacenamos y retornamos que no esta repetido
		return false;
	}
	else							//con el resto comprobamos si esta o no repetido y actuamos acorde
	{
		for (size_t i = 0; i < repetidos.size(); i++)//buscamos si esta en la lista
		{
			if (repetidos[i] == aux)
			{
				return true;		//si se repite no almacenamos y mandamos el aviso
			}
		}
		repetidos.push_back(aux);	//si por el contrario no esta entonces guardamos y ok
		return false;
	}
}

int nuVa() {	//Numero aleatorio de vagon
	int aux;
	do
	{
		aux = rand() % 9000 + 1000;	//aleatorio de 4 cifras 1000-9999
	} while (noRepetidoVagon(aux));
	return aux;
}

void crearContenedores() {		//metodo que crea aleatoriamente los vagones con su informacion y los añade a uno de los trenes
	int num = rand() % 4 + 2;	//para añadir mas vagones cambiar el valor 5 por uno a su eleccion
	for (int i = 0; i < num; i++)
	{
		tren1.insertarNodoVagon(nuVa(), cA(), tren1.origenTren(), dE(), false);
	}
	num = rand() % 4 + 2;
	for (int i = 0; i < num; i++)
	{
		tren2.insertarNodoVagon(nuVa(), cA(), tren2.origenTren(), dE(), false);
	}
	num = rand() % 4 + 2;
	for (int i = 0; i < num; i++)
	{
		tren3.insertarNodoVagon(nuVa(), cA(), tren3.origenTren(), dE(), false);
	}
	num = rand() % 4 + 2;
	for (int i = 0; i < num; i++)
	{
		tren4.insertarNodoVagon(nuVa(), cA(), tren4.origenTren(), dE(), false);
	}
	num = rand() % 4 + 2;
	for (int i = 0; i < num; i++)
	{
		tren5.insertarNodoVagon(nuVa(), cA(), tren5.origenTren(), dE(), false);
	}
}

void intercambiar() {

	int nVagon = 0;
	char *auxDestino = NULL;
	pnodo auxVagon;

	cout << "Examinamos el tren 1" << endl;
	while (tren1.comprobarVagones())	//mientras tenga vagones error repetir
	{
		cout << "Error en el tren 1" << endl;
		nVagon = tren1.vagonErroneoUltimo();	//sacamos cual es el que esta mal
		auxDestino = tren1.destinoVagonPosicion(nVagon);
		cout << "Numero de vagon erroneo: " << nVagon << " Con destino a "<< auxDestino  << endl;
		auxVagon = tren1.borrarNodo(nVagon);	//eliminamos el vagon del tren (aux) y recuperamos dicho nodo para su posterior adicion a otro tren PROBAR
		cout << "" << endl;
		if (auxDestino == tren2.destinoTren())
		{
			cout << "Colocado en el tren 2 con destino a "<< tren2.destinoTren() << endl;
			tren2.insertarFinal(auxVagon);
		}
		if (auxDestino == tren3.destinoTren())
		{
			cout << "Colocado en el tren 3 con destino a " << tren3.destinoTren() << endl;
			tren3.insertarFinal(auxVagon);
		}
		if (auxDestino == tren4.destinoTren())
		{
			cout << "Colocado en el tren 4 con destino a " << tren4.destinoTren() << endl;
			tren4.insertarFinal(auxVagon);
		}
		if (auxDestino == tren5.destinoTren())
		{
			cout << "Colocado en el tren 5 con destino a " << tren5.destinoTren() << endl;
			tren5.insertarFinal(auxVagon);
		}
	}
	cout << "Tren 1 examinado" << endl;
	cout << endl;
	cout << "Examinamos el tren 2" << endl;
	while (tren2.comprobarVagones())	//mientras tenga vagones error repetir
	{
		cout << "Error en el tren 1" << endl;
		nVagon = tren2.vagonErroneoUltimo();	//sacamos cual es el que esta mal
		auxDestino = tren2.destinoVagonPosicion(nVagon);
		cout << "Numero de vagon erroneo: " << nVagon << " Con destino a " << auxDestino << endl;
		auxVagon = tren2.borrarNodo(nVagon);	//eliminamos el vagon del tren (aux) y recuperamos dicho nodo para su posterior adicion a otro tren PROBAR

		if (auxDestino == tren1.destinoTren())
		{
			cout << "Colocado en el tren 1 con destino a " << tren1.destinoTren() << endl;
			tren1.insertarFinal(auxVagon);
		}
		if (auxDestino == tren3.destinoTren())
		{
			cout << "Colocado en el tren 3 con destino a " << tren3.destinoTren() << endl;
			tren3.insertarFinal(auxVagon);
		}
		if (auxDestino == tren4.destinoTren())
		{
			cout << "Colocado en el tren 4 con destino a " << tren4.destinoTren() << endl;
			tren4.insertarFinal(auxVagon);
		}
		if (auxDestino == tren5.destinoTren())
		{
			cout << "Colocado en el tren 5 con destino a " << tren5.destinoTren() << endl;
			tren5.insertarFinal(auxVagon);
		}
	}
	cout << "Tren 2 examinado" << endl;
	cout << endl;
	cout << "Examinamos el tren 3" << endl;
	while (tren3.comprobarVagones())	//mientras tenga vagones error repetir
	{
		cout << "Error en el tren 3" << endl;
		nVagon = tren3.vagonErroneoUltimo();	//sacamos cual es el que esta mal
		auxDestino = tren3.destinoVagonPosicion(nVagon);
		cout << "Numero de vagon erroneo: " << nVagon << " Con destino a " << auxDestino << endl;
		auxVagon = tren3.borrarNodo(nVagon);	//eliminamos el vagon del tren (aux) y recuperamos dicho nodo para su posterior adicion a otro tren PROBAR

		if (auxDestino == tren1.destinoTren())
		{
			cout << "Colocado en el tren 1 con destino a " << tren1.destinoTren() << endl;
			tren1.insertarFinal(auxVagon);
		}
		if (auxDestino == tren2.destinoTren())
		{
			cout << "Colocado en el tren 2 con destino a " << tren2.destinoTren() << endl;
			tren2.insertarFinal(auxVagon);
		}
		if (auxDestino == tren4.destinoTren())
		{
			cout << "Colocado en el tren 4 con destino a " << tren4.destinoTren() << endl;
			tren4.insertarFinal(auxVagon);
		}
		if (auxDestino == tren5.destinoTren())
		{
			cout << "Colocado en el tren 5 con destino a " << tren5.destinoTren() << endl;
			tren5.insertarFinal(auxVagon);
		}
	}
	cout << "Tren 3 examinado" << endl;
	cout << endl;
	cout << "Examinamos el tren 4" << endl;
	while (tren4.comprobarVagones())	//mientras tenga vagones error repetir
	{
		cout << "Error en el tren 4" << endl;
		nVagon = tren4.vagonErroneoUltimo();	//sacamos cual es el que esta mal
		auxDestino = tren4.destinoVagonPosicion(nVagon);
		cout << "Numero de vagon erroneo: " << nVagon << " Con destino a " << auxDestino << endl;
		auxVagon = tren4.borrarNodo(nVagon);	//eliminamos el vagon del tren (aux) y recuperamos dicho nodo para su posterior adicion a otro tren PROBAR

		if (auxDestino == tren1.destinoTren())
		{
			cout << "Colocado en el tren 1 con destino a " << tren1.destinoTren() << endl;
			tren1.insertarFinal(auxVagon);
		}
		if (auxDestino == tren2.destinoTren())
		{
			cout << "Colocado en el tren 2 con destino a " << tren2.destinoTren() << endl;
			tren2.insertarFinal(auxVagon);
		}
		if (auxDestino == tren3.destinoTren())
		{
			cout << "Colocado en el tren 3 con destino a " << tren3.destinoTren() << endl;
			tren3.insertarFinal(auxVagon);
		}
		if (auxDestino == tren5.destinoTren())
		{
			cout << "Colocado en el tren 5 con destino a " << tren5.destinoTren() << endl;
			tren5.insertarFinal(auxVagon);
		}
	}
	cout << "Tren 4 examinado" << endl;
	cout << endl;
	cout << "Examinamos el tren 5" << endl;
	while (tren5.comprobarVagones())	//mientras tenga vagones error repetir
	{
		cout << "Error en el tren 5" << endl;
		nVagon = tren5.vagonErroneoUltimo();	//sacamos cual es el que esta mal
		auxDestino = tren5.destinoVagonPosicion(nVagon);
		cout << "Numero de vagon erroneo: " << nVagon << " Con destino a " << auxDestino << endl;

		auxVagon = tren5.borrarNodo(nVagon);	//eliminamos el vagon del tren (aux) y recuperamos dicho nodo para su posterior adicion a otro tren

		if (auxDestino == tren1.destinoTren())
		{
			cout << "Colocado en el tren 1 con destino a " << tren1.destinoTren() << endl;
			tren1.insertarFinal(auxVagon);
		}
		if (auxDestino == tren2.destinoTren())
		{
			cout << "Colocado en el tren 2 con destino a " << tren2.destinoTren() << endl;
			tren2.insertarFinal(auxVagon);
		}
		if (auxDestino == tren3.destinoTren())
		{
			cout << "Colocado en el tren 3 con destino a " << tren3.destinoTren() << endl;
			tren3.insertarFinal(auxVagon);
		}
		if (auxDestino == tren4.destinoTren())
		{
			cout << "Colocado en el tren 4 con destino a " << tren4.destinoTren() << endl;
			tren4.insertarFinal(auxVagon);
		}
	}
	cout<<endl;
	cout << "Tren 5 examinado" << endl;
	cout << "FIN DEL INTERCAMBIO" << endl;
}

void cantidadCarga(char * y) {
	int cantidad = 0;
	cantidad = cantidad + tren1.numeroCargas(y);
	cantidad = cantidad + tren2.numeroCargas(y);
	cantidad = cantidad + tren3.numeroCargas(y);
	cantidad = cantidad + tren4.numeroCargas(y);
	cantidad = cantidad + tren5.numeroCargas(y);
	cout << "El numero de vagones con la carga " << y << " es de " << cantidad << endl;
}

int main() {
	//Random
	srand(time(NULL));

	int valorMenu = 9;

	//Creacion de las locomotoras
	tren1.insertarNodoTren(-1, NULL, 124, o1, d1, true);
	tren2.insertarNodoTren(-1, NULL, 456, o2, d2, true);
	tren3.insertarNodoTren(-1, NULL, 224, o3, d3, true);
	tren4.insertarNodoTren(-1, NULL, 801, o4, d4, true);
	tren5.insertarNodoTren(-1, NULL, 652, o5, d5, true);

	//creacion y asignacion de los contenedores automaticamente
	crearContenedores();


	while (valorMenu!=0)
	{
		cout << "MENU RENFE" << endl;
		cout << endl;
		cout << "1: Intercambiar trenes" << endl;
		cout << "2: Informacion trenes" << endl;
		cout << "0: Salir" << endl;
		cin >> valorMenu;
		cout << endl;
		switch (valorMenu)
		{
		case 1:	intercambiar(); break;
		case 2:	cout << "MENU Informacion" << endl;
				cout << endl;
				cout << "1: Mostrar trenes" << endl;
				cout << "2: Numero de trenes con coches" << endl;
				cout << "3: Numero de trenes con comida" << endl;
				cout << "4: Numero de trenes con medicamentos" << endl;
				cout << "5: Numero de trenes con combustible" << endl;
				cout << "6: Numero de trenes con dinero" << endl;
				cin >> valorMenu;
				cout << endl;
				switch (valorMenu)
				{
				case 1: tren1.mostrarLista();
						tren2.mostrarLista();
						tren3.mostrarLista();
						tren4.mostrarLista();
						tren5.mostrarLista();
						break;
				case 2: cantidadCarga(c1);break;
				case 3: cantidadCarga(c2);break;
				case 4: cantidadCarga(c5);break;
				case 5: cantidadCarga(c3);break;
				case 6: cantidadCarga(c4);break;
				default: break;
				}
				break;
		default: cout << "Buen viaje" << endl;break;
		}
	}

	system("Pause");
	return 0;
}
