#pragma once
#include "..\..\include\comun\Vector2D.h"

class Balon
{
private:

	float radio;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
public:
	Balon();
	~Balon();
	//Metodos
	void Dibuja();
	void Mueve(float);
	void SetColor(unsigned char, unsigned char, unsigned char);
	void SetRadio(float);
	void SetPos(float, float);
	void SetVel(float velx, float vely);
	float GetVel_y();

	friend class Interaccion;
};

