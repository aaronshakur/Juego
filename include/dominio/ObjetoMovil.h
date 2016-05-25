#pragma once
#include "..\..\include\comun\Vector2D.h"

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();
	//void Mueve(float);
	void SetPos(float, float);
	void SetColor(unsigned char, unsigned char, unsigned char);


protected:
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
};
