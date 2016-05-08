#pragma once
#include "Pared.h"

class Campo
{
public:
	Campo();
	~Campo();

	Pared suelo, techo, pared_izq, pared_dcha,red; //MAS ADELANTE ANADIR PLATAFORMAS PARA QUE REBOTE EL BALON

	//Metodos
	void Dibuja();

};

