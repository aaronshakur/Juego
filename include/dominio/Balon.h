#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Balon :public ObjetoMovil
{
private:

	float radio;
	//unsigned char rojo, verde, azul;
	//Vector2D posicion, velocidad, aceleracion;
public:
	Balon();
	~Balon();
	//Metodos
	void Dibuja();
	void Mueve(float);
	//void SetColor(unsigned char, unsigned char, unsigned char);
	void SetRadio(float);
	//void SetPos(float, float);


	friend class Interaccion;
};

