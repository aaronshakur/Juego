#include "..\include\comun\glut.h"
#include "..\include\juego\Mundo.h"
#include "..\..\include\dominio\Interaccion.h"
#include "..\..\include\dominio\Pared.h"
#include "..\..\include\dominio\ObjetoMovil.h"
#include "..\include\comun\ETSIDI.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define maxBotes 3


//Polimorfismo
ObjetoMovil  *pobjetosMoviles;

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
	pobjetosMoviles = &balon;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &hombre1;
	pobjetosMoviles->Dibuja();
	
	pobjetosMoviles = &hombre2;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &bonusesp;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &bonusnor;
	pobjetosMoviles->Dibuja();

	campo.Dibuja();

}

void Mundo::Mueve()
{
	
	pobjetosMoviles = &hombre1;
	pobjetosMoviles->Mueve(0.075f);

	pobjetosMoviles = &hombre2;
	pobjetosMoviles->Mueve(0.075f);

	pobjetosMoviles = &balon;
	pobjetosMoviles->Mueve(0.05f);

	pobjetosMoviles = &bonusnor;
	pobjetosMoviles->Mueve(0.009f);

	pobjetosMoviles = &bonusesp;
	pobjetosMoviles->Mueve(0.009f);

	Interaccion::Rebote(hombre1, campo); //Se llama con :: y su cabecera porque es un metodo estatico
	Interaccion::Rebote(hombre2, campo);
	Interaccion::Rebote(balon, campo);
	Interaccion::Rebote(balon, hombre1);
	Interaccion::Rebote(balon, hombre2);

	//for (int i=0; i <maxBotes; i++){

	if (Interaccion::Colision(balon, campo.suelo)){
	contadorBotes++;
	printf("Botes: ");
	printf("%d\n", contadorBotes);
	}

	if (contadorBotes == maxBotes){
		contadorPuntos++;
		printf("Puntos: ");
		printf("%d\n", contadorPuntos);
	}
	
			
}

void Mundo::Inicializa()  //Inicializamos los objetos con otros valores iniciales que no sean los de por defecto.
{
	
	contadorBotes = 0;
	//contadorPuntos = 0;

	//Los hago privados, pero no hace falt hacer Set, porque pertenecen al propio mundo.
	x_ojo = 1.5;

	y_ojo = 9;

	z_ojo = 42;

	hombre1.SetColor(255, 0, 0);
	hombre1.SetRadio(1.8f);
	hombre1.SetPos(6, 1);

	hombre2.SetColor(0, 0, 255);
	hombre2.SetRadio(1.8f);
	hombre2.SetPos(-6, 1);

	bonusnor.SetPos(8, 20);
	bonusesp.SetPos(-8, 20);
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
					hombre2.SetVel(hombre2.GetVelx(), 7.0f);  //para que salte en diagonal si arranca con velocidad	
				    break;
		}
		case 's':
			hombre2.SetVel(0.0f, 0.0f);
			break;
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
						hombre1.SetVel(hombre1.GetVelx(), 7.0f);  //para que salte en diagonal si arranca con velocidad
					break;
		}
		case GLUT_KEY_DOWN:
			hombre1.SetVel(0.0f, 0.0f);
			break;
	
	}
}


