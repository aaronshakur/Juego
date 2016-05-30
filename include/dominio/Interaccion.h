#pragma once
#include "Hombre.h"
#include "Campo.h"
#include "Balon.h"
#include "Bonus.h"

class Interaccion {

public:
	Interaccion();
	~Interaccion();

	//Metodos de rebote
	static void Rebote(Hombre &h, Campo c); 
	static bool Rebote(Hombre &h, Pared p);
	static void Rebote(Balon &b, Campo c);
	static bool Rebote(Balon &b, Pared p);
	static bool ReboteSuelo(Balon &b, Pared suelo);
	static bool Rebote(Balon &b, Hombre &h);

	//Metodos de colision
	//static void Colision(Bonus &bon, Hombre &h);

	//funciones de informacion, no cambian los objetos (no referencias), solo devuelven true si hay colision
	static bool Colision(Balon b, Pared suelo);
	static bool Colision(Bonus bon , Hombre h );

};