#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "..\..\include\dominio\ObjetoMovil.h"
#include <time.h>

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
void ObjetoMovil::SetPos(Vector2D pos)
{
	posicion = pos;
}

void ObjetoMovil::SetVel(Vector2D vel)
{
	velocidad = vel;
}

Vector2D ObjetoMovil::GetPos()
{
	return posicion;
}

float ObjetoMovil::GetRadio()
{
	return radio;
}

int ObjetoMovil::PosxRandom(){
	int xrandom;
	srand(time(NULL)); //semilla 
	xrandom = (-19 + (rand() % 38)); //rellena con numeros aleatorios en el eje X dentro del campo
	return xrandom;
}

int ObjetoMovil::VelxRandom(){
	int velxrandom;
	srand(time(NULL)); //semilla 
	velxrandom = (-8 + (rand() % 15)); //rellena con numeros aleatorios en el eje X dentro del campo
	return velxrandom;
}
