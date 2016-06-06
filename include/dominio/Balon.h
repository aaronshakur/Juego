#pragma once
#include <stdlib.h>
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;




class Balon :public ObjetoMovil
{
private:

	Sprite sprite;
	Sprite sprite2;
<<<<<<< HEAD
=======


>>>>>>> refs/remotes/origin/master

public:
	Balon();
	~Balon();

	//Metodos
	void Dibuja();
	void Mueve(float);
	friend class Interaccion;
};

