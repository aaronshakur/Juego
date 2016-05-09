#include "..\..\include\dominio\Bonus.h"
#include "..\..\include\comun\glut.h"
#include <stdlib.h>

Bonus::Bonus()    //constructor de bonus. Damos valores iniciales
{
	rojo = verde = azul = 255; //Blanco
	lado = 0.5f;
	aceleracion.y = 0.0f; //Para que se quede parado por ahora
}

Bonus::~Bonus()
{
}

void Bonus::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio 
	//glColor3f(rojo,verde,azul); //otro color no aleatorio
	glutSolidCube(lado);
	glPopMatrix();

}

void Bonus::Mueve(float t){

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);
	velocidad = velocidad + aceleracion*t;

}
void Bonus::SetPos(float posx, float posy){

	posicion.x = posx;
	posicion.y = posy;
}