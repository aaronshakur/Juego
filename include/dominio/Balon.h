#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Balon :public ObjetoMovil
{
private:

public:
	Balon();
	~Balon();
	//Metodos
	void Dibuja();
	void Mueve(float);
	friend class Interaccion;
};

