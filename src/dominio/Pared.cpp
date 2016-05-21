#include "..\..\include\dominio\Pared.h"
#include "..\..\include\comun\glut.h"

Pared::Pared()   //constructor de pared. Damos valores iniciales
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

void Pared::Dibuja(){

	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 20);
	glVertex3d(limite2.x, limite2.y, 20);
	glVertex3d(limite2.x, limite2.y, -20);
	glVertex3d(limite1.x, limite1.y, -20);
	glEnd();
	glEnable(GL_LIGHTING);

}

void Pared::SetColor(unsigned char r, unsigned char g, unsigned char b){

	rojo = r;
	verde = g;
	azul = b;

}
void Pared::SetLim(float x1, float y1, float x2, float y2){

	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendra?
//el vector unitario saliente que indica la direccion de la
//recta ma?s corta entre el punto y la pared.

float Pared::Distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u*v;
	float distancia = 0;
	if (valor<0)
		dir = u;
	else if (valor>longitud)
		dir = (punto - limite2);
	else
		dir = u - v*valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector...
		*direccion = dir.Unitario();
	return distancia;
}