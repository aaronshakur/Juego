#pragma once
#include "Pared.h"

class Campo
{
private:

	Pared suelo_d,suelo_i, techo, pared_izq, pared_dcha,red; //MAS ADELANTE ANADIR PLATAFORMAS PARA QUE REBOTE EL BALON

public:
	Campo();
	~Campo();

	//Metodos
	void Dibuja();

friend class Interaccion;
friend class Mundo;

};

