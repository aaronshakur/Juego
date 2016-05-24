#pragma once
#include "Hombre.h"
#include "Balon.h"

#define MAX_HOMBRES 3	//Posible espontaneo mas adelante
//#define MAX_BALONES 2	//Posible doble balon mas adelante

class ListaEsferas
{
private:

	Hombre *listaH[MAX_HOMBRES];
	int numeroHombres;

/*	Balon *listaB[MAX_BALONES];
	int numeroBalones;
*/	

public:
	ListaEsferas();
	~ListaEsferas();
	//Metodos

//	bool Agregar(Balon *b);
	bool Agregar(Hombre *h);
	void Dibuja();
	void Mueve(float );

	
};
