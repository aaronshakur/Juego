#include "..\include\comun\glut.h"
#include "..\include\juego\Mundo.h"
#include <math.h>

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	balon.Dibuja();
	hombre1.Dibuja();
	hombre2.Dibuja();
	bonus.Dibuja();
	campo.Dibuja();

}

void Mundo::Mueve()
{
	hombre1.Mueve(0.05f);
	hombre2.Mueve(0.05f);
	balon.Mueve(0.05f);

}

void Mundo::Inicializa()  //Inicializamos los objetos con otros valores iniciales que no sean los de por defecto.
{
	x_ojo=1.5;
	y_ojo=7.5;
	z_ojo=40;

	hombre1.SetColor(255, 0, 0);
	hombre1.SetAltura(1.8f);
	hombre1.posicion.x = 6;
	hombre1.posicion.y = 0;
	hombre2.SetColor(0, 0, 255);
	hombre2.SetAltura(1.8f);
	hombre2.posicion.x = -6;
	hombre2.posicion.y = 0;

	bonus.posicion.x = 8;
	bonus.posicion.y = 8;

	balon.SetColor(255, 255, 0);
	balon.SetRadio(0.5f);
	balon.posicion.x = 1;
	balon.posicion.y = 6;


}

void Mundo::Tecla(unsigned char key)
{

}
