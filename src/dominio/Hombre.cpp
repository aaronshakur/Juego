#include "..\..\include\dominio\Hombre.h"
#include "..\..\include\comun\glut.h"


Hombre::Hombre()  //constructor de hombre. Damos valores iniciales
{
	altura = 1.8f;
	//mas adelante cuando salten, pondremos gravedad.
}

Hombre::~Hombre()
{
}

void Hombre::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();

}

void Hombre::Mueve(float t){

	posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	velocidad.x = velocidad.x + aceleracion.x*t;
	velocidad.y = velocidad.y + aceleracion.y*t;

}