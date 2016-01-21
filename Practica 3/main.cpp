#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "arboles.h"
#include "listas.h"
#include <iostream>

#define intermedio 1000

using namespace std;

// Variables y declaraciones globales
ArbolABB arbolInt;
Lista pesos;
bool hayLista = false;

// Calculamos aleatoriamente el valor que se va a insertar en el árbol
int pesoAleatorio() {
	int a = rand() % 6;
	switch (a)
	{
		case 0:	cout << "la bola con peso 1" << endl; return  1; break;
		case 1: cout << "la bola con peso 2" << endl; return  2; break;
		case 2: cout << "la bola con peso 3" << endl; return  3; break;
		case 3:	cout << "la bola con peso 5" << endl; return  5; break;
		case 4:	cout << "la bola con peso 7" << endl; return  7; break;
		default: cout << "la bola con peso 10" << endl; return	10; break;
	}
}

// Calculamos el número con el cual insertaremos la bola dentro del árbol
int numeroDerecha(int ND, int PD) {
	int aux = (int)(intermedio / ND);
	return (aux*PD);
}

// Calculamos el número con el cual insertaremos la bola dentro del árbol
int numeroIzquierda(int NI, int PI) {
	int aux = (int)(intermedio / NI);
	return (aux*PI);
}

// Añadimos bolas hasta que se cumpla la condición de equilibrio
void equilibrar() {
	//variables para los cálculos
	int dato;
	int peso;
	int NI = 2;	//Nivel
	int ND = 2;
	int DI = 1;	//Divisiones o veces a realizar
	int DD = 1;
	int PI = 1;	//Posición
	int PD = 3;
	int CD = 1;	//Contador veces
	int CI = 1;
	pNodoLista aux;
	aux = pesos.getPrimero();

    // Podamos el árbol para crear uno nuevo
    arbolInt.podar(arbolInt.getRaiz());

    // Borra la lista
    if(!hayLista) pesos.~Lista();

    // Inicializa los valores del árbol
    arbolInt.inicializar();

    // Inicializa los valores de la lista
    if(!hayLista) pesos.inicializar();

	//iniciamos el nodo raíz con el valor intermedio y peso 0 para que no cuente en el total
	arbolInt.insertar(intermedio, 0);

	//realizamos las operaciones hasta que el arbol este equilibrado
	do
	{
		if (arbolInt.getPesoDerecha()<arbolInt.getPesoIzquierda())	//Insertamos en la derecha por tener un peso inferior
		{
			cout << "Insertamos en el lado derecho ";
			dato = numeroDerecha(ND,PD);
			if(!hayLista) peso = pesoAleatorio();
			if(hayLista)
            {
                if(aux)
                {
                    peso = aux->getPeso();
                    cout << "la bola con peso " << peso << endl;
                    aux = aux->getSiguiente();
                } else hayLista = false;
            }
			arbolInt.insertar(dato, peso);
			if(!hayLista) pesos.insertarFinalNodoLista(dato, peso);
			cout << "Actualizamos informacion: " << endl;
			cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
			cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
			cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
			cout << endl;
			if (CD==DD)			//Se igualan los valores contador y divisiones y pasamos al próx nivel
			{
				ND = ND * 2;	//Pasamos de nivel
				DD = DD * 2;	//Aumento el número de divisiones
				PD = PD + 2;	//Aumento de la posisción de 2 en 2 para evitar usar el número del padre
				CD = 1;			//Iniciamos contador
			}
			else {				//Si el contador no es igual al número de divisiones
				PD = PD + 2;	//Aumento de la posiscion de 2 en 2 para evitar usar el número del padre
				CD++;			//Aumento contador
			}
		}
		else {													//Si no insertamos en la izquierda
			cout << "Insertamos en el lado izquierdo ";
			dato = numeroIzquierda(NI,PI);
			if(!hayLista) peso = pesoAleatorio();
			if(hayLista)
            {
                if(aux)
                {
                    peso = aux->getPeso();
                    cout << "la bola con peso " << peso << endl;
                    aux = aux->getSiguiente();
                } else hayLista = false;
            }
			arbolInt.insertar(dato, peso);
			if(!hayLista) pesos.insertarFinalNodoLista(dato, peso);
			cout << "Actualizamos informacion: " << endl;
			cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
			cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
			cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
			cout << endl;
			if (CI == DI)		//Se igualan los valores contador y divisiones y pasamos al próx nivel
			{
				NI = NI * 2;	//Pasamos de nivel
				DI = DI * 2;	//Aumento el número de divisiones
				PI = 1;			//Inicializamos la posición
				CI = 1;			//Iniciamos contador
			}
			else {				//Si el contador no es igual al número de divisiones
				PI = PI + 2;	//Aumento de la posisción de 2 en 2 para evitar usar el número del padre
				CI++;			//Aumento contador
			}
		}
	} while (!arbolInt.estaEquilibrado());//Repetir hasta que se cumpla

	arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);

	cout << endl;
	cout << "El arbol ha sido equilibrado" << endl;
	cout << endl;

	hayLista = false;
}

// Función para enseñar el árbol por capas
void mostrarFormaArbol() {

    if (arbolInt.esVacio(arbolInt.getRaiz())) {

        cout << " Arbol vacio" << endl;
        cout << endl;
        cout << endl;
    }
    else {

        Nodo *aux = arbolInt.getRaiz();//nodo auxiliar para recorrer
        cout << endl;
        for (int i = 0; i < arbolInt.getAltura()+1; i++)//Recorremos todas las capas pidiendo que se muestren
        {
            arbolInt.mostrarNivel(aux, i, i);
            cout << endl << endl << endl << endl;
        }
    }
}

// Función de prueba para recorridos del árbol
void mostrar(int &d)
{
	cout << d << ",";
}

// Muestra la información del árbol
void infoArbol() {

        cout << " Informacion del arbol: " << endl;
        cout << "  Altura del arbol " << arbolInt.getAltura() << endl;
        cout << "  Peso total del arbol " << arbolInt.getPesoTotal() << endl;
        cout << "  Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
        cout << "  Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
        cout << "  N nodos: " << arbolInt.getNumNodos() << endl;
        cout << endl;
        cout << endl;
}

// Muestra información extra del árbol
void infoX() {

    if (arbolInt.esVacio(arbolInt.getRaiz())) {

        cout << " Arbol vacio" << endl;
        cout << endl;
        cout << endl;
    }
    else {

        cout << " Diferentes formas de representacion de la colocacion: " << endl << endl;
        cout << "  InOrden: ";
        arbolInt.inOrden(mostrar);
        cout << endl;
        cout << "  PreOrden: ";
        arbolInt.preOrden(mostrar);
        cout << endl;
        cout << "  PostOrden: ";
        arbolInt.postOrden(mostrar);
        cout << endl;
    }
}

// Quita la bola con el valor especificado y reequilibra
void reequilibrar() {
    int dato;

    cout << " El peso de que dato desea quitar?: ";
    cin >> dato;
    cout << endl;
    if (arbolInt.buscar(dato) && dato!=intermedio)
    {
        arbolInt.borrar(dato);
        mostrarFormaArbol();
        pesos.mostrarLista();
        pesos.borrarNodoLista(dato);
        pesos.mostrarLista();
        hayLista = true;
        equilibrar();
    }
    else
    {
        cout << " Ese dato no se puede borrar" << endl;
        return;
    }

}

//Juego del equilibrado se va alternando entre jugador y la maquina
void equilibrarJuego() {
	//variables para los calculos
	int NI = 2;	//Nivel
	int ND = 2;
	int DI = 1;	//Divisiones o veces a realizar
	int DD = 1;
	int PI = 1;	//Posicion
	int PD = 3;
	int CD = 1;	//Contador veces
	int CI = 1;
	int contadorTurno = 0;
	char direccion;
	int pesoBola = 0;
	bool pesado = true;
	bool direccionado = true;

    // Podamos el árbol para crear uno nuevo
    arbolInt.podar(arbolInt.getRaiz());
    // Inicializa los valores del árbol
    arbolInt.inicializar();
	//iniciamos el nodo raiz con el valor intermedio y peso 0 para que no cuente en el total
	arbolInt.insertar(intermedio, 0);
	//Mensajes de informacion del juego
	cout << "Bienvenido al Juego de equilibrar el arbol" << endl;
	cout <<  endl;
	cout << "Reglas:" << endl;
	cout << "1- El juego consiste ir añadiendo pesos hasta en equilibrar el arbol de tal manera" << endl;
    cout << "   que el oponente no pueda terminarlo y tu si." << endl;
    cout << "2- Solo se pueden insertar caracteres validos en caso contrario volvera a solicitar" << endl;
    cout << "3- La maquina solo genera pesos aleatorios en este nivel" << endl;
    cout << "4- Para ganar el equilibrio tiene que ser exacto" << endl;
    cout << "5- El jugador que coloque la ultima bola sera el ganador" << endl;
    cout <<  endl;

	//realizamos las operaciones hasta que el arbol este equilibrado
	do
	{
		if (contadorTurno % 2 == 0)
		{
			cout << "Jugador" << endl;
			do
			{
				pesado = true;
				cout << "Inserte el peso de la bola (1,2,3,5,7,10)" << endl;
				cin >> pesoBola;
				if (pesoBola==1 || pesoBola==2 || pesoBola==3 || pesoBola==5 || pesoBola==7 || pesoBola==10)
				{
					pesado = false;
				}
			} while (pesado);
			do
			{
				direccionado = true;
				cout << "Seleccione lado Izquierda (I) o Derecha (D)" << endl;
				cin >> direccion;
				if (direccion == 'D' || direccion == 'd' || direccion == 'I' || direccion == 'i')
				{
					direccionado = false;
				}
			} while (direccionado);
			if (direccion=='D' || direccion == 'd')
			{
				cout << "Insertamos en el lado derecho ";
				cout << "la bola con peso " << pesoBola << endl;
				arbolInt.insertar(numeroDerecha(ND, PD), pesoBola);
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CD == DD)			//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					ND = ND * 2;	//Pasamos de nivel
					DD = DD * 2;	//Aumento el numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD++;			//Aumento contador
				}
			}
			else {
				cout << "Insertamos en el lado izquierdo ";
				cout << "la bola con peso " << pesoBola << endl;
				arbolInt.insertar(numeroIzquierda(NI, PI), pesoBola);
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CI == DI)		//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					NI = NI * 2;	//Pasamos de nivel
					DI = DI * 2;	//Aumento el numero de divisiones
					PI = 1;			//Inicializamos la posicion
					CI = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PI = PI + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CI++;			//Aumento contador
				}
			}
			contadorTurno++;
		}
		else {
			cout << "Maquina" << endl;
			if (arbolInt.getPesoDerecha()<arbolInt.getPesoIzquierda())	//Insertamos en la derecha por tener un peso inferior
			{
				cout << "Insertamos en el lado derecho ";
				arbolInt.insertar(numeroDerecha(ND, PD), pesoAleatorio());
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CD == DD)			//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					ND = ND * 2;	//Pasamos de nivel
					DD = DD * 2;	//Aumento el numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD++;			//Aumento contador
				}
			}
			else {													//Si no insertamos en la izquierda
				cout << "Insertamos en el lado izquierdo ";
				arbolInt.insertar(numeroIzquierda(NI, PI), pesoAleatorio());
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CI == DI)		//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					NI = NI * 2;	//Pasamos de nivel
					DI = DI * 2;	//Aumento el numero de divisiones
					PI = 1;			//Inicializamos la posicion
					CI = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PI = PI + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CI++;			//Aumento contador
				}
			}
			cout << endl;
			cout << "Arbol actualizado" << endl;
			mostrarFormaArbol();
			cout << endl;
			contadorTurno++;
		}
	} while (arbolInt.getPesoDerecha()!=arbolInt.getPesoIzquierda());//Repetir hasta que se cumpla
	cout << endl;
	cout << "El arbol ha sido equilibrado. Se termino el juego" << endl;
	if (contadorTurno % 2 == 0) {
		cout << "HA GANADO LA MAQUINA" << endl;
	}else{
		cout << "HA GANADO EL JUGADOR" << endl;
	}
	cout << endl;
}

//Juego del equilibrado se va alternando entre jugador y la maquina
void equilibrarJuegoAvanzado() {
	//variables para los calculos
	int NI = 2;	//Nivel
	int ND = 2;
	int DI = 1;	//Divisiones o veces a realizar
	int DD = 1;
	int PI = 1;	//Posicion
	int PD = 3;
	int CD = 1;	//Contador veces
	int CI = 1;
	int contadorTurno = 0;
	int diferenciaPesos = 0;
	int pesoMaquina = 0;
	char direccion;
	int pesoBola = 0;
	bool pesado = true;
	bool direccionado = true;
	bool nosDaVentaja = true;

    // Podamos el árbol para crear uno nuevo
    arbolInt.podar(arbolInt.getRaiz());
    // Inicializa los valores del árbol
    arbolInt.inicializar();
	//iniciamos el nodo raiz con el valor intermedio y peso 0 para que no cuente en el total
	arbolInt.insertar(intermedio, 0);
	//Mensajes de informacion del juego
	cout << "Bienvenido al Juego de equilibrar el arbol" << endl;
	cout <<  endl;
	cout << "Reglas:" << endl;
	cout << "1- El juego consiste ir añadiendo pesos hasta en equilibrar el arbol de tal manera" << endl;
    cout << "   que el oponente no pueda terminarlo y tu si." << endl;
    cout << "2- Solo se pueden insertar caracteres validos en caso contrario volvera a solicitar" << endl;
    cout << "3- La maquina seleciona los valores a conciencia en este nivel" << endl;
    cout << "4- Para ganar el equilibrio tiene que ser exacto" << endl;
    cout << "5- El jugador que coloque la ultima bola sera el ganador" << endl;
    cout << "6- Suerte y que dios nos pille confesados" << endl;
    cout <<  endl;

	//realizamos las operaciones hasta que el arbol este equilibrado
	do
	{
		if (contadorTurno % 2 == 0)
		{
			cout << "Jugador" << endl;
			do
			{
				pesado = true;
				cout << "Inserte el peso de la bola (1,2,3,5,7,10)" << endl;
				cin >> pesoBola;
				if (pesoBola==1 || pesoBola==2 || pesoBola==3 || pesoBola==5 || pesoBola==7 || pesoBola==10)
				{
					pesado = false;
				}
			} while (pesado);
			do
			{
				direccionado = true;
				cout << "Seleccione lado Izquierda (I) o Derecha (D)" << endl;
				cin >> direccion;
				if (direccion == 'D' || direccion == 'd' || direccion == 'I' || direccion == 'i')
				{
					direccionado = false;
				}
			} while (direccionado);
			if (direccion=='D' || direccion == 'd')
			{
				cout << "Insertamos en el lado derecho ";
				cout << "la bola con peso " << pesoBola << endl;
				arbolInt.insertar(numeroDerecha(ND, PD), pesoBola);
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CD == DD)			//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					ND = ND * 2;	//Pasamos de nivel
					DD = DD * 2;	//Aumento el numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD++;			//Aumento contador
				}
			}
			else {
				cout << "Insertamos en el lado izquierdo ";
				cout << "la bola con peso " << pesoBola << endl;
				arbolInt.insertar(numeroIzquierda(NI, PI), pesoBola);
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CI == DI)		//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					NI = NI * 2;	//Pasamos de nivel
					DI = DI * 2;	//Aumento el numero de divisiones
					PI = 1;			//Inicializamos la posicion
					CI = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PI = PI + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CI++;			//Aumento contador
				}
			}
			contadorTurno++;
		}
		else {
			cout << "Maquina" << endl;
			//Calculamos la diferencia de los pesos para saber que numero insertar
			if  (arbolInt.getPesoDerecha()<arbolInt.getPesoIzquierda())
            {
                diferenciaPesos=arbolInt.getPesoIzquierda()- arbolInt.getPesoDerecha();
            }else{
                diferenciaPesos=arbolInt.getPesoDerecha()-arbolInt.getPesoIzquierda();
            }
			if(nosDaVentaja){
                cout << "Te voy a dar ventaja" << endl;
				switch (diferenciaPesos)
				{
					case 1:	pesoMaquina = 5; break;
					case 2: pesoMaquina = 10; break;
					case 3: pesoMaquina = 3; break;
					case 5:	pesoMaquina = 7; break;
					case 7:	pesoMaquina = 1; break;
					default:pesoMaquina = 1; break;
				}
                nosDaVentaja=false;
			}else {
			    //Obtenemos el valor del peso a insertar
                switch (diferenciaPesos)
                {
                    case 1:	pesoMaquina=1; break;
                    case 2: pesoMaquina=2; break;
                    case 3: pesoMaquina=3; break;
                    case 4:	pesoMaquina=10; break;
                    case 5:	pesoMaquina=5; break;
                    case 6:	pesoMaquina=2; break;
                    case 7:	pesoMaquina=7; break;
                    case 8:	pesoMaquina=3; break;   //Solo se puede vencer llegando a la diferencia de 8
                    case 9:	pesoMaquina=1; break;
                    case 10:pesoMaquina=10; break;
                    case 11:pesoMaquina=2; break;
                    default:pesoMaquina=1; break;
                }
			}

			if (arbolInt.getPesoDerecha()<arbolInt.getPesoIzquierda())	//Insertamos en la derecha por tener un peso inferior
			{
				cout << "Insertamos en el lado derecho ";
				arbolInt.insertar(numeroDerecha(ND, PD), pesoMaquina);
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CD == DD)			//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					ND = ND * 2;	//Pasamos de nivel
					DD = DD * 2;	//Aumento el numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PD = PD + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CD++;			//Aumento contador
				}
			}
			else {													//Si no insertamos en la izquierda
				cout << "Insertamos en el lado izquierdo ";
				arbolInt.insertar(numeroIzquierda(NI, PI), pesoMaquina);
				arbolInt.calcularAlturaArbol(arbolInt.getRaiz(), 0);
				cout << "Actualizamos informacion: " << endl;
				cout << "Peso total del arbol " << arbolInt.getPesoTotal() << endl;
				cout << "Peso total de la derecha " << arbolInt.getPesoDerecha() << endl;
				cout << "Peso total de la izquierda " << arbolInt.getPesoIzquierda() << endl;
				cout << endl;
				if (CI == DI)		//Se igualan los valores contador y divisiones y pasamos al prox nivel
				{
					NI = NI * 2;	//Pasamos de nivel
					DI = DI * 2;	//Aumento el numero de divisiones
					PI = 1;			//Inicializamos la posicion
					CI = 1;			//Iniciamos contador
				}
				else {				//Si el contador no es igual al numero de divisiones
					PI = PI + 2;	//Aumento de la posiscion de 2 en dos para evitar usar el numero del padre
					CI++;			//Aumento contador
				}
			}
			cout << endl;
			cout << "Arbol actualizado" << endl;
			mostrarFormaArbol();
			cout << endl;
			contadorTurno++;
		}
	} while (arbolInt.getPesoDerecha()!=arbolInt.getPesoIzquierda());//Repetir hasta que se cumpla
	cout << endl;
	cout << "El arbol ha sido equilibrado. Se termino el juego" << endl;
	if (contadorTurno % 2 == 0) {
		cout << "HA GANADO LA MAQUINA" << endl;
	}else{
		cout << "HA GANADO EL JUGADOR" << endl;
	}
	cout << endl;
}

int main()
{
	//Random
	srand(time(NULL));

	int valorMenu = 9;

	while (valorMenu!=0)
	{
	    cout << endl;
		cout << "       MENU ARBOLES" << endl;
		cout << endl;
		cout << " 1: Informacion arbol" << endl;
		cout << " 2: Mostrar arbol" << endl;
		cout << " 3: Crear y equilibrar arbol" << endl;
		cout << " 4: Informacion extra" << endl;
		cout << " 5: Quitar peso y reequilibrar" << endl;
		cout << " 6: Juego" << endl;
		cout << " 7: Juego Avanzado solo para los mas valientes" << endl;
		cout << " 0: Salir" << endl;
		cout << endl;
		cout << " Elija opcion: ";
		cin >> valorMenu;
		cout << endl;
		switch (valorMenu)
		{
		    case 0: cout << " Bye!" << endl << endl; break;
            case 1: infoArbol(); break;
            case 2:	mostrarFormaArbol(); break;
            case 3:	equilibrar(); break;
            case 4:	infoX(); break;
            case 5:	reequilibrar(); break;
            case 6:	equilibrarJuego(); break;
            case 7: equilibrarJuegoAvanzado(); break;
            default: cout << " Opcion erronea" << endl << endl; break;
		}
	}
	return 0;
}
