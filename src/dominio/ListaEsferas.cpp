#include "..\..\include\dominio\ListaEsferas.h"
#include "..\include\comun\glut.h"



ListaEsferas::ListaEsferas()    //constructor de ListaEsferas. Damos valores iniciales
{
	numeroHombres = 0;
	for (int i = 0; i<MAX_HOMBRES; i++)
		listaH[i] = 0;

/*	numeroBalones = 0;
	for (int i = 0; i<MAX_BALONES; i++)
		listaB[i] = 0;
*/
}

ListaEsferas::~ListaEsferas()
{
}

/*
bool ListaEsferas::Agregar(Balon *b)
{
	if (numeroBalones<MAX_BALONES)
		listaB[numeroBalones++] = b;
	else
		return false;
	return true;
}
*/

bool ListaEsferas::Agregar(Hombre *h)
{
	if (numeroHombres<MAX_HOMBRES)
		listaH[numeroHombres++] = h;
	else
		return false;
	return true;
}

void ListaEsferas::Dibuja()
{
	for (int i = 0; i<numeroHombres; i++)
		listaH[i]->Dibuja();
}

void ListaEsferas::Mueve(float t)
{
	for (int i = 0; i<numeroHombres; i++)
		listaH[i]->Mueve(t);
}