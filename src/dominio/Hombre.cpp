#include "..\..\include\dominio\Hombre.h"
#include "..\..\include\comun\glut.h"


Hombre::Hombre()  //constructor de hombre. Damos valores iniciales
{
	altura = 1.8f;
	rojo = verde = azul = 255; //blanco
	//mas adelante cuando salten, pondremos gravedad.
}

Hombre::~Hombre()
{
}

void Hombre::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(rojo, verde, azul);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();

}

void Hombre::Mueve(float t){

	posicion.x = posicion.x + velocidad.x*t + 0.5f*aceleracion.x*t*t;
	posicion.y = posicion.y + velocidad.y*t + 0.5f*aceleracion.y*t*t;
	velocidad.x = velocidad.x + aceleracion.x*t;
	velocidad.y = velocidad.y + aceleracion.y*t;

}

void Hombre::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	rojo = r;
	verde = g;
	azul = b;
};

void Hombre::SetAltura(float rad){ //ALTURA=RADIO ESFERAS HOMBRES

	altura = rad;

}
void Hombre::SetPos(float posx, float posy){

	posicion.x = posx;
	posicion.y = posy;
}