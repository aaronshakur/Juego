#include "..\..\include\dominio\Balon.h"
#include "..\..\include\comun\glut.h"

Balon::Balon() //constructor de balon. Damos valores iniciales
{
	rojo = verde = azul = 255; //blanco
	radio = 1.0f;
	aceleracion.y = -9.8f;
}

Balon::~Balon()
{
}

void Balon::Dibuja(){

	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);

}

void Balon::Mueve(float t){

	posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	velocidad.x = velocidad.x + aceleracion.x*t;
	velocidad.y = velocidad.y + aceleracion.y*t;

}

void Balon::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	rojo = r;
	verde = g;
	azul = b;
};

void Balon::SetRadio(float rad){

	radio = rad;

}