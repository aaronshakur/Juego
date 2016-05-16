#include "..\include\comun\glut.h"
#include "..\include\juego\Mundo.h"
#include "..\..\include\dominio\Interaccion.h"
#include "..\..\include\dominio\Pared.h"

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
	hombre1.Mueve(0.075f);
	hombre2.Mueve(0.075f);
	balon.Mueve(0.05f);
	Interaccion::Rebote(hombre1, campo); //Se llama con :: y su cabecera porque es un metodo estatico
	Interaccion::Rebote(hombre2, campo);
	Interaccion::Rebote(balon, campo);
	Interaccion::Rebote(balon, hombre1);
	Interaccion::Rebote(balon, hombre2);

	if (Interaccion::Rebote(balon, hombre1)){

		balon.SetVel(-10,balon.GetVel_y());
	
	}

	if (Interaccion::Rebote(balon, hombre2)){

		balon.SetVel(+10, balon.GetVel_y());

	}
}

void Mundo::Inicializa()  //Inicializamos los objetos con otros valores iniciales que no sean los de por defecto.
{
	//Los hago privados, pero no hace falt hacer Set, porque pertenecen al propio mundo.
	x_ojo = 1.5;

	y_ojo = 9;

	y_ojo = 9.0;

	z_ojo = 42;

	hombre1.SetColor(255, 0, 0);
	hombre1.SetAltura(1.8f);
	hombre1.SetPos(6, 1);

	hombre2.SetColor(0, 0, 255);
	hombre2.SetAltura(1.8f);
	hombre2.SetPos(-6, 1);

	bonus.SetPos(8, 8);

	balon.SetColor(255, 255, 0);
	balon.SetRadio(0.75f);
	balon.SetPos(1, 6);

}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case 'a':
		hombre2.SetVel(-5.0f, 0.0f);
		break;
	case 'd':
		hombre2.SetVel(5.0f, 0.0f);
		break;
	case 'w':
	{
						if(Interaccion::Rebote(hombre2,campo.suelo)) // para que solo pueda saltar una vez
							hombre2.SetVel(0.0f, 7.0f);
						break;
	}

	}
}

void Mundo::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre1.SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre1.SetVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
	{
						if (Interaccion::Rebote(hombre1,campo.suelo)) //para que solo pueda saltar una vez
							hombre1.SetVel(0.0f, 7.0f);
						break;
	}
	}
}