#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Balon :public ObjetoMovil
{
private:

	float radio;

public:
	Balon();
	~Balon();

	//Metodos
	void Dibuja();
	void Mueve(float);
	void SetRadio(float);
	
	friend class Interaccion;
};

