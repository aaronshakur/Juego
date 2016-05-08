#pragma once
#include "..\..\include\comun\Vector2D.h"

class Pared
{
private:

	unsigned char rojo, verde, azul;
	Vector2D limite1, limite2;

public:
	Pared();
	~Pared();

	//Metodos
	void Dibuja();
	void SetColor(unsigned char, unsigned char, unsigned char);


};

