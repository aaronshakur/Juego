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

	posicion= posicion + velocidad*t + aceleracion*(t*t*0.5f); // usando metodos sobrecargados de Vector2d
	velocidad= velocidad+ aceleracion*t;
	if (posicion.y <= 0.5) // para que la pelota no desaparezca nunca.
		posicion.y = 0.5;

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
void Balon::SetPos(float posx, float posy){

	posicion.x = posx;
	posicion.y = posy;
}