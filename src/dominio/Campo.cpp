#include "..\..\include\dominio\Campo.h"


Campo::Campo()  //constructor de campo. Damos valores iniciales
{
	suelo.limite1.x = 20.0f;
	suelo.limite2.x = -20.f;
	suelo.limite1.y = 0.0f;
	suelo.limite2.y = 0.0f;
	suelo.azul = 45;
	suelo.verde = 100;
	suelo.rojo = 25;


	techo.limite1.x = 20.0f;
	techo.limite2.x = -20.f;
	techo.limite1.y = 20.0f;
	techo.limite2.y = 20.0f;
	techo.azul = 85;
	techo.verde = 220;
	techo.rojo = 35;

	pared_dcha.limite1.x = 20.0f;
	pared_dcha.limite2.x = 20.f;
	pared_dcha.limite1.y = 0.0f;
	pared_dcha.limite2.y = 20.0f;
	pared_dcha.azul = 85;
	pared_dcha.verde = 220;
	pared_dcha.rojo = 35;

	pared_izq.limite1.x = -20.0f;
	pared_izq.limite2.x = -20.f;
	pared_izq.limite1.y = 0.0f;
	pared_izq.limite2.y = 20.0f;
	pared_izq.azul = 85;
	pared_izq.verde = 220;
	pared_izq.rojo = 35;


}


Campo::~Campo()
{
}
