#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "Campo.h"

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();
	//void Mueve(float);

protected:
	Vector2D posicion, velocidad, aceleracion;
};
