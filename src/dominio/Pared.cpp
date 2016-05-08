#include "..\..\include\dominio\Pared.h"
#include "..\..\include\comun\glut.h"


Pared::Pared()   //constructor de campo. Damos valores iniciales
{
	rojo = azul= verde= 255;
	
	limite1.x = 0.0f;
	limite1.y = 0.0f;
	limite2.x = 0.0f;
	limite1.y = 0.0f;

}


Pared::~Pared()
{

}

void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}