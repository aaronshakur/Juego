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
	void SetLim(float, float,float,float);
	float Distancia(Vector2D punto, Vector2D *direccion = 0);
	float Pared::get_limity2(){ return limite2.y; };


friend class Interaccion;
friend class Mundo;

};

