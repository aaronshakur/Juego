#pragma once
#include "Pared.h"

class Campo
{
public:
	Campo();
	~Campo();

	Pared suelo, techo, pared_izq, pared_dcha;
	void Dibuja();
};

