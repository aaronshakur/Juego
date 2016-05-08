#include "..\..\include\dominio\Bonus.h"
#include "..\..\include\comun\glut.h"


Bonus::Bonus()    //constructor de bonus. Damos valores iniciales
{
	rojo = verde = azul = 255; //Blanco
	lado = 0.5f;
	aceleracion.y = 0.0f; //Para que se quede parado por ahora
}


Bonus::~Bonus()
{
}

void Bonus::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0); glRotatef(30, 1, 1, 1);
	glColor3ub(255, 255, 255);
	glutSolidCube(lado);
	glPopMatrix();

}