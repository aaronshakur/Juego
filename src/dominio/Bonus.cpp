#include <stdlib.h>
#include "..\..\include\dominio\Bonus.h"
#include "glut.h"


Bonus::Bonus()    //constructor de bonus. Damos valores iniciales
{
	rojo = verde = 0;
	azul = 255;
	lado = 1.0f;
	//aceleracion.y = -9.8f; 
	velocidad.y = -15.0f;
}

Bonus::~Bonus()
{
}

void Bonus::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);//posicion.x, posicion.y
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio 
	glutSolidCube(lado);
	glPopMatrix();

}

void Bonus::Mueve(float t){

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);
	velocidad = velocidad + aceleracion*t;

}

