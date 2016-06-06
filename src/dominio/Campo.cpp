#include "..\..\include\dominio\Campo.h"

Campo::Campo()  //constructor de campo. Damos valores iniciales
{
	suelo_d.SetLim(0.0f, 0.0f, 20.0f, 0.0f);//(x1,y1,x2,y2)
	suelo_d.SetColor(166, 94, 46);

	suelo_i.SetLim(-20.0f, 0.0f, 0.0f, 0.0f);//(x1,y1,x2,y2)
	suelo_i.SetColor(166,94,46);
	
	techo.SetLim(20.0f, 20.0f, -20.0f, 20.0f);//(x1,y1,x2,y2)
	techo.SetColor(25, 158, 218);

	pared_dcha.SetLim(20.0f, 0.0f, 20.0f, 20.0f);//(x1,y1,x2,y2)
	pared_dcha.SetColor(85, 220, 35);

	pared_izq.SetLim(-20.0f, 0.0f, -20.0f, 20.0f);//(x1,y1,x2,y2)
	pared_izq.SetColor(85, 220, 35);

	red.SetLim(0.0f, 0.0f, 0.0f, 5.0f);//(x1,y1,x2,y2)
	red.SetColor(192, 192, 192);

}

Campo::~Campo()
{
}

void Campo::Dibuja(){

	suelo_d.Dibuja();
	suelo_i.Dibuja();
	techo.Dibuja();
	pared_dcha.Dibuja();
	pared_izq.Dibuja();
	red.Dibuja();
}