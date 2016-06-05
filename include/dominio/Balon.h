#pragma once
#include <stdlib.h>
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

<<<<<<< HEAD
using ETSIDI::Sprite;
=======

//using ETSIDI::Sprite;
>>>>>>> origin/RamaMiguelHerencia

class Balon :public ObjetoMovil
{
private:
<<<<<<< HEAD
	Sprite sprite;
	Sprite sprite2;
=======
	//Sprite sprite;
>>>>>>> origin/RamaMiguelHerencia

public:
	Balon();
	~Balon();

	//Metodos
	void Dibuja();
	void Mueve(float);
	friend class Interaccion;
};

