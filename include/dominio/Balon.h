#pragma once
#include "..\..\include\comun\Vector2D.h"
#include "ObjetoMovil.h"


class Balon :public ObjetoMovil
{
private:

<<<<<<< HEAD
	float radio;
	//unsigned char rojo, verde, azul;
	//Vector2D posicion, velocidad, aceleracion;
=======
>>>>>>> refs/remotes/origin/RamaMiguelHerencia
public:
	Balon();
	~Balon();
	//Metodos
	void Dibuja();
	void Mueve(float);
<<<<<<< HEAD
	//void SetColor(unsigned char, unsigned char, unsigned char);
	void SetRadio(float);
	//void SetPos(float, float);


=======
>>>>>>> refs/remotes/origin/RamaMiguelHerencia
	friend class Interaccion;
};

