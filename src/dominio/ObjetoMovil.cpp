#include "..\..\include\dominio\ObjetoMovil.h"

ObjetoMovil::ObjetoMovil()
{
}


ObjetoMovil::~ObjetoMovil()
{
}

/*
void ObjetoMovil::Mueve(float t){

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);   //no puede ser escalar*vector!!! debe ser Vector2Dx escalar!! debido a la declaracion en Vector2D.cpp
	velocidad = velocidad + aceleracion*t;
	if (posicion.y <= 0.9) // para que el jugador no desaparezca al ponerle aceleracion negativa para el salto.
		posicion.y = 0.9;
	if (posicion.y <= 0.5) // para que la pelota no desaparezca nunca.
		posicion.y = 0.5;
}
*/
<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/RamaMiguelHerencia
void ObjetoMovil::SetPos(float posx, float posy){

	posicion.x = posx;
	posicion.y = posy;
}

<<<<<<< HEAD
void ObjetoMovil::SetColor(unsigned char r, unsigned char g, unsigned char b){
		rojo = r;
		verde = g;
		azul = b;
}
=======
void ObjetoMovil::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	rojo = r;
	verde = g;
	azul = b;
};

void ObjetoMovil::SetRadio(float rad){

	radio = rad;

}

void ObjetoMovil::SetVel(float vx, float vy){ //Sera llamado por Mundo cada vez que pulsemos una tecla para mover a los jugadores

	velocidad.x = vx;
	velocidad.y = vy;
}
void ObjetoMovil::SetAce(float ax, float ay){ //Sera llamado por Mundo cada vez que pulsemos una tecla para mover a los jugadores

	aceleracion.x = ax;
	aceleracion.y = ay;
}
>>>>>>> refs/remotes/origin/RamaMiguelHerencia
