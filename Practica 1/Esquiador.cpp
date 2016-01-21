#include<time.h>
#include <ctime>
#include <cstdlib>

#include "Esquiador.h"

Esquiador::Esquiador()//Constructor de la clase esquiador
{
	grupo = rand() % 2;//seleccion de Adulto o Niño con la funcion rand()
	if (grupo == 1)
	{
		edad = 'A';
	}
	else {
		edad = 'N';
	}
}

Esquiador::~Esquiador()//Destructor
{
}

char Esquiador::categoria()//Retorna si es A o N
{
	return edad;
}
