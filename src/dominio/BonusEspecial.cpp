#include "..\..\include\dominio\BonusEspecial.h"


BonusEspecial::BonusEspecial()
{
	pulso = 2.5f;
	ladomax = 2.0f;
	ladomin = 0.5f;
	
}


BonusEspecial::~BonusEspecial()
{
}

void BonusEspecial::Mueve(float t) // Sin polimorfismo se llamaba 'mueve_esp'. Ahora se llama tambien Mueve()
{
	Bonus::Mueve(t);  //Es una herencia de Bonus y tiene sus atributos pero un 'Mueve' diferente.
	
	if (lado>ladomax)
		pulso = -pulso;
	if (lado<ladomin)
		pulso = -pulso;
	lado += pulso*t;
	rojo = lado * 255;
	verde = 255 - lado * 100;
	azul = 100 + lado * 50;
}