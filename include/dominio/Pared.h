#pragma once
#include "..\..\include\comun\Vector2D.h"

class Pared
{
public:
	Pared();
	~Pared();

	unsigned char rojo, verde, azul;
	Vector2D limite1, limite2;

	//Metodos
	void Dibuja();


};

