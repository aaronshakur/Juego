#include "..\..\include\dominio\Campo.h"


Campo::Campo()  //constructor de campo. Damos valores iniciales
{
	suelo.SetLim(20.0f, 0.0f, -20.0f, 0.0f);
	/*suelo.limite1.x = 20.0f;
	suelo.limite2.x = -20.f;
	suelo.limite1.y = 0.0f;
	suelo.limite2.y = 0.0f;*/
	suelo.SetColor(45, 100, 25);
	

	techo.SetLim(20.0f, 20.0f, -20.0f, 20.0f);
	/*techo.limite1.x = 20.0f;
	techo.limite2.x = -20.f;
	techo.limite1.y = 20.0f;
	techo.limite2.y = 20.0f;*/
	techo.SetColor(45, 100, 25);

	pared_dcha.SetLim(20.0f, 0.0f, 20.0f, 20.0f);
	/*pared_dcha.limite1.x = 20.0f;
	pared_dcha.limite2.x = 20.f;
	pared_dcha.limite1.y = 0.0f;
	pared_dcha.limite2.y = 20.0f;*/
	pared_dcha.SetColor(85, 220, 35);

	pared_izq.SetLim(-20.0f, 0.0f, -20.0f, 20.0f);
	/*pared_izq.limite1.x = -20.0f;
	pared_izq.limite2.x = -20.f;
	pared_izq.limite1.y = 0.0f;
	pared_izq.limite2.y = 20.0f;*/
	pared_izq.SetColor(85, 220, 35);

	red.SetLim(0.0f, 0.0f, 0.0f, 5.0f);
	/*red.limite1.x = 0.0f;
	red.limite2.x = 0.0f;
	red.limite1.y = 0.0f;
	red.limite2.y = 5.0f;*/
	red.SetColor(80,50, 150);
	
}

Campo::~Campo()
{
}

void Campo::Dibuja(){

	suelo.Dibuja();
	techo.Dibuja();
	pared_dcha.Dibuja();
	pared_izq.Dibuja();
	red.Dibuja();

}