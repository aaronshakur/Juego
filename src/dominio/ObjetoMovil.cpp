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

int ObjetoMovil::PosxRandom1(){
	
	int xrandom;
	srand(time(NULL)); //semilla 
	xrandom = (-rand()%39 + (rand() % 38)); //rellena con numeros aleatorios en el eje X dentro del campo
	return xrandom;
}
int ObjetoMovil::PosxRandom2(){

	int xrandom2;
	srand(time(NULL)); //semilla 
	xrandom2 = (-rand()%39 + (rand() % 38)); //rellena con numeros aleatorios en el eje X dentro del campo
	return xrandom2;
}
int ObjetoMovil::PosxRandom3(){

	int xrandom3;
	srand(time(NULL)); //semilla 
	xrandom3 = (-rand() % 39 + (rand() % 38)); //rellena con numeros aleatorios en el eje X dentro del campo
	return xrandom3;
}

int ObjetoMovil::PosxRandom4(){

	int xrandom4;
	srand(time(NULL)); //semilla 
	xrandom4 = (-rand() % 39 + (rand() % 38)); //rellena con numeros aleatorios en el eje X dentro del campo
	return xrandom4;
}

int ObjetoMovil::PosyRandom1(){

	int yrandom;
	srand(time(NULL)); //semilla 
	yrandom = (-rand() % 75 + (rand() % 75)); //rellena con numeros aleatorios en el eje y dentro del campo
	return yrandom;
}
int ObjetoMovil::PosyRandom2(){

	int yrandom2;
	srand(time(NULL)); //semilla 
	yrandom2 = (-rand() % 75 + (rand() % 75)); //rellena con numeros aleatorios en el eje y dentro del campo
	return yrandom2;
}
int ObjetoMovil::PosyRandom3(){

	int yrandom3;
	srand(time(NULL)); //semilla 
	yrandom3 = (-rand() % 75 + (rand() % 75)); //rellena con numeros aleatorios en el eje y dentro del campo
	return yrandom3;
}

int ObjetoMovil::PosyRandom4(){

	int yrandom4;
	srand(time(NULL)); //semilla 
	yrandom4 = (-rand() % 75 + (rand() % 75)); //rellena con numeros aleatorios en el eje y dentro del campo
	return yrandom4;
}

int ObjetoMovil::VelxRandom(){
	int velxrandom;
	srand(time(NULL)); //semilla 

	velxrandom = (-8 + (rand() % 15)); //rellena con numeros aleatorios en el eje X dentro del campo
	return velxrandom;
}

