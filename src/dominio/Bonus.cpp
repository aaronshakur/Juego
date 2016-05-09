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

	posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	velocidad.x = velocidad.x + aceleracion.x*t;
	velocidad.y = velocidad.y + aceleracion.y*t;

}
void Bonus::SetPos(float posx, float posy){

	posicion.x = posx;
	posicion.y = posy;
}