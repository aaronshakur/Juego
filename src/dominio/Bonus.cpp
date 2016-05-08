#include "..\..\include\dominio\Bonus.h"


Bonus::Bonus()    //constructor de bonus. Damos valores iniciales
{
	rojo = verde = azul = 255; //Blanco
	lado = 0.5f;
	aceleracion.y = 0.0f; //Para que se quede parado por ahora
}


Bonus::~Bonus()
{
}
