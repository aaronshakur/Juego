#pragma once
#include "Bonus.h"

class BonusEspecial :public Bonus
{

public:
	BonusEspecial();
	~BonusEspecial();
	void mueve_esp(float t);

private:
	float pulso, ladomax, ladomin;
};

