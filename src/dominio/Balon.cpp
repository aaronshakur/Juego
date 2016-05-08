#include "..\..\include\dominio\Balon.h"

Balon::Balon() //constructor de balon. Damos valores iniciales
{
	rojo = verde = azul = 255; //blanco
	radio = 1.0f;
	aceleracion.y = -9.8f;
}


Balon::~Balon()
{
}
