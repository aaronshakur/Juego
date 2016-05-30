#pragma once
#include "Bonus.h"

class BonusEspecial :public Bonus
{

public:
	BonusEspecial();
	~BonusEspecial();
	void Mueve(float t);// Sin polimorfismo se llamaba 'mueve_esp'. Ahora se llama tambien Mueve()

private:
	float pulso, ladomax, ladomin;

	friend class Interaccion;
};

