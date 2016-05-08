#pragma once
#include "..\..\include\comun\Vector2D.h"

class Hombre
{
public:
	Hombre();
	~Hombre();

	float altura;
	Vector2D posicion, velocidad, aceleracion;
	void Dibuja();
};

