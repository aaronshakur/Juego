#pragma once
#include "..\..\include\comun\Vector2D.h"
<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/RamaMiguelHerencia

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();
	void SetPos(float , float );
	void SetColor(unsigned char , unsigned char , unsigned char );
	void SetRadio(float);
	void SetVel(float, float);
	void SetAce(float, float);
	//void Mueve(float);
	void SetPos(float, float);
	void SetColor(unsigned char, unsigned char, unsigned char);


protected:
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
	unsigned char rojo, verde, azul;
	float radio;
};
