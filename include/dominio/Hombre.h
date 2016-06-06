#pragma once
#include <stdlib.h>
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Hombre :public ObjetoMovil
{
private:
<<<<<<< HEAD
	Sprite spriteHombre1Nor, spriteHombre2Nor;
	Sprite spriteHombre1Grande, spriteHombre2Grande, spriteHombre1Peq, spriteHombre2Peq;
=======

	Sprite spriteHombre1Grande, spriteHombre2Grande, spriteHombre1Peq, spriteHombre2Peq, spriteHombre1Nor, spriteHombre2Nor;

>>>>>>> refs/remotes/origin/master

public:
	Hombre();
	~Hombre();
	//Metodos
	void Dibuja();
	void Mueve(float);
	float GetVelx(){ return velocidad.x;};

	friend class Interaccion;

};

