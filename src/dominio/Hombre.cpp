#include "..\..\include\dominio\Hombre.h"
#include "..\..\include\comun\glut.h"


Hombre::Hombre()  //constructor de hombre. Damos valores iniciales
{
	rojo = verde = azul = 255; //blanco
	aceleracion.y = -9.8;
}

Hombre::~Hombre()
{
}

void Hombre::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(rojo, verde, azul);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}

void Hombre::Mueve(float t){

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);   //no puede ser escalar*vector!!! debe ser Vector2D* escalar!! debido a la declaracion en Vector2D.cpp
	velocidad = velocidad + aceleracion*t;
	if (posicion.y <= 0.9) // para que el jugador no desaparezca al ponerle aceleracion negativa para el salto.
		posicion.y = 0.9;
	
}

void Hombre::SetAltura(float rad){ //ALTURA=RADIO ESFERAS HOMBRES

	altura = rad;

}

void Hombre::SetVel(float vx, float vy){ //Sera llamado por Mundo cada vez que pulsemos una tecla para mover a los jugadores

	velocidad.x = vx;
	velocidad.y = vy;
}
void Hombre::SetAce(float ax, float ay){ //Sera llamado por Mundo cada vez que pulsemos una tecla para mover a los jugadores

	aceleracion.x = ax;
	aceleracion.y = ay;
}
