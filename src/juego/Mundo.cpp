#include "..\include\comun\glut.h"
#include "..\include\juego\Mundo.h"
#include "..\include\dominio\Balon.h"
#include "..\include\dominio\Bonus.h"
#include "..\include\dominio\Campo.h"
#include "..\include\dominio\Hombre.h"
#include <math.h>

Balon balon;
Bonus bonus;
Campo campo;
Hombre hombre;




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
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	balon.Dibuja();
	bonus.Dibuja();
	hombre.Dibuja();
	campo.Dibuja();
}

void Mundo::Mueve()
{
	balon.Mueve(0.025f);
}

void Mundo::Inicializa()
{


	x_ojo =0;
	y_ojo =8;
	z_ojo = 60;

	balon.posicion.x = 2;
	balon.posicion.y = 4;
	balon.radio = 1.5f;
	balon.rojo = 0;
	balon.verde = 0;
	balon.azul = 255;
	bonus.posicion.x = 5.0f;
	bonus.posicion.y = 5.0f;
}

void Mundo::Tecla(unsigned char key)
{

}
