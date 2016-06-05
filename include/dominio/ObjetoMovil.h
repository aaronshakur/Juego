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
	float GetRadio();
	void SetPos(Vector2D pos);
	void SetVel(Vector2D vel);

	int PosxRandom1();
	int PosxRandom2();
	int PosxRandom3();
	int PosxRandom4();

	int PosyRandom1();
	int PosyRandom2();
	int PosyRandom3();
	int PosyRandom4();

	int VelxRandom();
	float GetPosx(){ return posicion.x; };
	Vector2D GetPos();	
	float GetPos_x(){ return posicion.x; };
	float GetPos_y(){ return posicion.y; };
//Polimorfismo de Mueve() para Balon, Hombre y Bonus
	virtual void Mueve(float){};

//Polimorfismo de Dibuja() para Balon, Hombre y Bonus
	virtual void Dibuja(){};
	
protected:
	unsigned char rojo, verde, azul;
	Vector2D posicion,velocidad, aceleracion;
	float radio;


};
