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

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);   //no puede ser escalar*vector!!! debe ser Vector2D* escalar!! debido a la declaracion en Vector2D.cpp
	velocidad = velocidad + aceleracion*t;
	
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

void Hombre::SetVel(float vx, float vy){ //Sera llamado por Mundo cada vez que pulsemos una tecla para mover a los jugadores

	velocidad.x = vx;
	velocidad.y = vy;
}