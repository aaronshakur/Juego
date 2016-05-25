#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Hombre :public ObjetoMovil
{
private:

	float altura;
	//unsigned char rojo, verde, azul;
	//Vector2D posicion, velocidad, aceleracion;

public:
	Hombre();
	~Hombre();

	//Metodos
	void Dibuja();
	void Mueve(float);
	//void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetAltura(float);
	//void SetPos(float, float);
	void SetVel(float, float);
	void SetAce(float ax, float ay);

	float GetVelx(){ return velocidad.x;};

	friend class Interaccion;
};

