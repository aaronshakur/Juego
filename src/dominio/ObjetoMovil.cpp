#include "..\..\include\dominio\ObjetoMovil.h"

ObjetoMovil::ObjetoMovil(){}

ObjetoMovil::~ObjetoMovil(){}

void ObjetoMovil::SetPos(float posx, float posy){

	posicion.x = posx;
	posicion.y = posy;
}

void ObjetoMovil::SetColor(unsigned char r, unsigned char g, unsigned char b){

		rojo = r;
		verde = g;
		azul = b;
}

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

