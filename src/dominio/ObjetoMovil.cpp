#include "..\..\include\dominio\ObjetoMovil.h"

ObjetoMovil::ObjetoMovil()
{
}


ObjetoMovil::~ObjetoMovil()
{
}

/*
void ObjetoMovil::Mueve(float t){

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);   //no puede ser escalar*vector!!! debe ser Vector2Dx escalar!! debido a la declaracion en Vector2D.cpp
	velocidad = velocidad + aceleracion*t;
	if (posicion.y <= 0.9) // para que el jugador no desaparezca al ponerle aceleracion negativa para el salto.
		posicion.y = 0.9;
	if (posicion.y <= 0.5) // para que la pelota no desaparezca nunca.
		posicion.y = 0.5;
}
*/