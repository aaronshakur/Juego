#pragma once
#include "..\..\include\comun\Vector2D.h"

class Balon
{
public:
	Balon();
	~Balon();

	float radio;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;

	//Metodos
	void Dibuja();
	void Mueve(float);
};

