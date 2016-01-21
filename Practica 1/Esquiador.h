#ifndef ESQUIADOR_H
#define ESQUIADOR_H

#include<iostream>

//Se penso en hacer que las colas contuviesen objetos del tipo esquiador pero se descarto la idea ya que complicaba la forma de mostrar los datos

class Esquiador		//Clase esquiador
{
public:
	Esquiador();	//constructor
	~Esquiador();	//Destructor
	char categoria();//Muestra el tipo de categoria
private:
	char edad = 'Z';//A para adulto N para niño
	int grupo = 0;	//1=A 0=N
};

#endif;
