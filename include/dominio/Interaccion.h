#pragma once
#include "Hombre.h"
#include "Campo.h"

class Interaccion {

public:
	Interaccion();
	~Interaccion();

	//Metodos de rebote
	static void Rebote(Hombre &h, Campo c); 
	static bool Rebote(Hombre &h, Pared p);


private:


};