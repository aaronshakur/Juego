#pragma once
#include "..\..\include\comun\Vector2D.h"

class Bonus
{
private:

	float lado;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;

public:
	Bonus();
	~Bonus();
	//Metodos
	void Dibuja();
	void Mueve(float);
	void SetPos(float, float);

};

