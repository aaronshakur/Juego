#pragma once
#include "..\..\include\comun\Vector2D.h"

class Bonus
{
public:
	Bonus();
	~Bonus();

	float lado;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
};

