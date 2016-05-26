#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Hombre :public ObjetoMovil
{
private:
	float altura;

public:
	Hombre();
	~Hombre();
	//Metodos
	void Dibuja();
	void Mueve(float);
	void SetAltura(float);
	void SetVel(float, float);
	void SetAce(float ax, float ay);
	float GetVelx(){ return velocidad.x;};

	friend class Interaccion;
};

