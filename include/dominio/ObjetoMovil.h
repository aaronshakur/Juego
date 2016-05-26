#pragma once
#include "..\..\include\comun\Vector2D.h"

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();

	void SetColor(unsigned char , unsigned char , unsigned char );
	void SetRadio(float);
	void SetPos(float, float);
	void SetVel(float, float);
	void SetAce(float, float);
	
protected:
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
	float radio;
};
