#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Hombre :public ObjetoMovil
{
private:

public:
	Hombre();
	~Hombre();
	//Metodos
	void Dibuja();
	void Mueve(float);
	float GetVelx(){ return velocidad.x;};

	friend class Interaccion;
};

