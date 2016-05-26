#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Hombre :public ObjetoMovil
{
private:

<<<<<<< HEAD
	float altura;
	//unsigned char rojo, verde, azul;
	//Vector2D posicion, velocidad, aceleracion;

=======
>>>>>>> refs/remotes/origin/RamaMiguelHerencia
public:
	Hombre();
	~Hombre();
	//Metodos
	void Dibuja();
	void Mueve(float);
<<<<<<< HEAD
	//void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetAltura(float);
	//void SetPos(float, float);
	void SetVel(float, float);
	void SetAce(float ax, float ay);

=======
>>>>>>> refs/remotes/origin/RamaMiguelHerencia
	float GetVelx(){ return velocidad.x;};

	friend class Interaccion;
};

