#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Bonus :public ObjetoMovil
{
protected:

	float lado;
	
public:
	Bonus();
	~Bonus();
	//Metodos
	void Dibuja();
	void Mueve(float);
	float GetLado(){ return lado; };

	friend class Interaccion; //Para la interaccion;
};

