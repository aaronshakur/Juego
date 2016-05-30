#pragma once
#include "..\..\include\comun\Vector2D.h"

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();

	void SetColor(unsigned char , unsigned char , unsigned char );
	void SetRadio(float);
	void SetPos(float, float);
	void SetVel(float, float);
	void SetAce(float, float);
	void SetPos(Vector2D pos);

	float GetRadio();
	Vector2D GetPos();	




//Polimorfismo de Mueve() para Balon, Hombre y Bonus
	virtual void Mueve(float){};

//Polimorfismo de Dibuja() para Balon, Hombre y Bonus
	virtual void Dibuja(){};
	
protected:
	unsigned char rojo, verde, azul;
	Vector2D posicion,velocidad, aceleracion;
	float radio;

};
