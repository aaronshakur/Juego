#pragma once
#include "..\..\include\comun\Vector2D.h"

class Balon
{
private:

	float radio;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
public:
	Balon();
	~Balon();
	//Metodos
	void Dibuja();
	void Mueve(float);
	void SetColor(unsigned char, unsigned char, unsigned char);
	void SetRadio(float);
	void SetPos(float, float);

<<<<<<< HEAD
	void SetVel(float velx, float vely);
	float GetVel_y();


	float GetPosY(){ return posicion.y; };
	float GetVelX(){ return velocidad.x; };
	float GetVelY(){ return velocidad.y; };
=======
>>>>>>> refs/remotes/origin/master


	friend class Interaccion;
};

