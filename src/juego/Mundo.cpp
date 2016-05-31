#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include "ETSIDI.h"

#include "..\include\juego\Mundo.h"
#include "..\..\include\dominio\Interaccion.h"
#include "..\..\include\dominio\Pared.h"
#include "..\..\include\dominio\ObjetoMovil.h"

#define maxBotes 5
#define maxPuntos 3

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

	if (Interaccion::Colision(bonusnor, hombre1)){

		pobjetosMoviles = &bonusnor;
		pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom(), 30);
		pobjetosMoviles = &hombre1;
		pobjetosMoviles->SetRadio(3.0f);
	}

	if (Interaccion::Colision(bonusnor, hombre2)){

		pobjetosMoviles = &bonusnor;
		pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom(), 15);
		pobjetosMoviles = &hombre2;
		pobjetosMoviles->SetRadio(3.0f);
	}
	pobjetosMoviles = &bonusesp;
	pobjetosMoviles->Mueve(0.009f);

	if (Interaccion::Colision(bonusesp, hombre2)){
		pobjetosMoviles = &bonusesp;
		pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom(), 30);
		pobjetosMoviles = &hombre2;
		pobjetosMoviles->SetRadio(1.0f);
	}
	if (Interaccion::Colision(bonusesp, hombre1)){
		pobjetosMoviles = &bonusesp;
		pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom(), 15);
		pobjetosMoviles = &hombre1;
		pobjetosMoviles->SetRadio(1.0f);
	}



	Interaccion::Rebote(hombre1, campo); //Se llama con :: y su cabecera porque es un metodo estatico
	Interaccion::Rebote(hombre2, campo);
	Interaccion::Rebote(balon, campo);
	Interaccion::Rebote(balon, hombre1);
	Interaccion::Rebote(balon, hombre2);

	if (Interaccion::Colision(balon, campo.suelo_d)){
		contadorBotes_d++;
		printf("Botes derecha : ");
		printf("%d\n", contadorBotes_d);
	}
	
	if (Interaccion::Colision(balon, campo.suelo_i)){
		contadorBotes_i++;
		printf("Botes izquierda: ");
		printf("%d\n", contadorBotes_i);
		}
	

	if (contadorBotes_d == maxBotes){
		contadorPuntos_i++;
		printf("Puntos izquierda: ");
		printf("%d\n", contadorPuntos_i);

		}
	if (contadorBotes_i == maxBotes){
		contadorPuntos_d++;
		printf("Puntos derecha: ");
		printf("%d\n", contadorPuntos_d);


	}
}

void Mundo::Inicializa()  //Inicializamos los objetos con otros valores iniciales que no sean los de por defecto.
{

		contadorBotes_d = 0;
		contadorBotes_i = 0;

		//Los hago privados, pero no hace falt hacer Set, porque pertenecen al propio mundo.
		x_ojo = 1.5;
		y_ojo = 9;
		z_ojo = 70;

		pobjetosMoviles = &hombre1;
		pobjetosMoviles->SetColor(255, 0, 0);
		pobjetosMoviles->SetRadio(1.8f);
		pobjetosMoviles->SetPos(6, 1);

		pobjetosMoviles = &hombre2;
		pobjetosMoviles->SetColor(0, 0, 255);
		pobjetosMoviles->SetRadio(1.8f);
		pobjetosMoviles->SetPos(-6, 1);

		pobjetosMoviles = &bonusesp;
		pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom(), 30);

		pobjetosMoviles = &bonusnor;
		pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom(), 30);

		pobjetosMoviles = &balon;
		pobjetosMoviles->SetColor(255, 255, 0);
		pobjetosMoviles->SetRadio(0.75f);
		pobjetosMoviles->SetPos(0, 9);
		pobjetosMoviles->SetVel(pobjetosMoviles->VelxRandom(),9);

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

	case 'w':{

				 if (Interaccion::Rebote(hombre2, campo.suelo_i)) // para que solo pueda saltar una vez
					 hombre2.SetVel(hombre2.GetVelx(), 7.0f);  //para que salte en diagonal si arranca con velocidad	
				 ETSIDI::play("sonidos/disparo.wav");
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
						if (Interaccion::Rebote(hombre1, campo.suelo_d)) //para que solo pueda saltar una vez
							hombre1.SetVel(hombre1.GetVelx(), 7.0f);  //para que salte en diagonal si arranca con velocidad
						ETSIDI::play("sonidos/disparo.wav");
						break;
	}
	case GLUT_KEY_DOWN:
	{
						  hombre1.SetVel(0.0f, 0.0f);
						  break;
	}

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
							if (Interaccion::Rebote(hombre1, campo.suelo_d)) //para que solo pueda saltar una vez
								hombre1.SetVel(hombre1.GetVelx(), 7.0f);  //para que salte en diagonal si arranca con velocidad
							ETSIDI::play("sonidos/disparo.wav");
							break;
		}
		case GLUT_KEY_DOWN:
			hombre1.SetVel(0.0f, 0.0f);
			break;
		}

	}

}
	//Funcion que resetea los puntos cuando acaba una partida

void Mundo::SetPuntosI(){

		if (contadorPuntos_i == maxPuntos)
			contadorPuntos_i = 0;			
}


void Mundo::SetPuntosD(){

	if (contadorPuntos_d == maxPuntos)
		contadorPuntos_d = 0;
}