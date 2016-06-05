#include <stdlib.h>
#include "ETSIDI.h"
#include "OpenGL.h"
#include "glut.h"
#include <math.h>
#include <iostream>
#include "..\include\juego\Mundo.h"
#include "..\..\include\dominio\Interaccion.h"
#include "..\..\include\dominio\Pared.h"
#include "..\..\include\dominio\ObjetoMovil.h"

#define maxBotes 100
#define maxPuntos 3

//Polimorfismo
ObjetoMovil  *pobjetosMoviles;

Mundo::Mundo() //:sprite2("imagenes/suelo.png", -1) //No tocar! 
{
	//sprite2.setCenter(1.5f, 2.5f);
	//sprite2.setSize(10, 10);
}

void Mundo::RotarOjo()
{
	float dist = sqrt(x_ojo*x_ojo + z_ojo*z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist*cos(ang);
	z_ojo = dist*sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	//DIBUJO FONDO 
    DibujaFondo();
//	DibujaSuelo();
	DibujaPared_D();
	DibujaPared_I();

	//aqui es donde hay que poner el codigo de dibujo
	pobjetosMoviles = &balon;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &hombre1;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &hombre2;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &bonusespgran;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &bonusesppeq;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &bonusnor;
	pobjetosMoviles->Dibuja();

	pobjetosMoviles = &bonusnorpelota;
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

	pobjetosMoviles = &bonusnorpelota;
	pobjetosMoviles->Mueve(0.009f);

	pobjetosMoviles = &bonusespgran;
	pobjetosMoviles->Mueve(0.009f);

	pobjetosMoviles = &bonusesppeq;
	pobjetosMoviles->Mueve(0.009f);

	if (Interaccion::Colision(bonusnor, hombre1)){

		campo.red.SetLim(0.0f, 0.0f, 0.0f, 8.0f);
	}

	if (Interaccion::Colision(bonusnor, hombre2)){

		campo.red.SetLim(0.0f, 0.0f, 0.0f, 8.0f);
	}
	if (Interaccion::Colision(bonusnorpelota, hombre1)){

		balon.SetRadio(2.00f);
		//sprite2.draw();
	}

	if (Interaccion::Colision(bonusnorpelota, hombre2)){

		balon.SetRadio(2.00f);
		//sprite2.draw();
		
	}

	if (Interaccion::Colision(bonusespgran, hombre2)){

		pobjetosMoviles = &hombre2;
		pobjetosMoviles->SetRadio(2.5f);
	}
	if (Interaccion::Colision(bonusespgran, hombre1)){

		pobjetosMoviles = &hombre1;
		pobjetosMoviles->SetRadio(2.50f);
	}
	if (Interaccion::Colision(bonusesppeq, hombre2)){

		pobjetosMoviles = &hombre1;
		pobjetosMoviles->SetRadio(1.0f);
	}
	if (Interaccion::Colision(bonusesppeq, hombre1)){

		pobjetosMoviles = &hombre2;
		pobjetosMoviles->SetRadio(1.0f);
	}
	
	Vector2D posbonusespgran = bonusespgran.GetPos();
	if (posbonusespgran.y < -10.0f){

		pobjetosMoviles = &bonusespgran;
		pobjetosMoviles->SetPos(-19 + (rand() % 38), -rand() % 100 + (rand() % 100));
	}

	Vector2D posbonusesppeq = bonusesppeq.GetPos();
	if (posbonusesppeq.y < -20.0f){

		pobjetosMoviles = &bonusesppeq;
		pobjetosMoviles->SetPos(-19 + (rand() % 38), -rand() % 100 + (rand() % 100));
	}

	Vector2D posbonusnor = bonusnor.GetPos();
	if (posbonusnor.y < -40.0f){

		pobjetosMoviles = &bonusnor;
		pobjetosMoviles->SetPos(-19 + (rand() % 38), -rand() % 100 + (rand() % 100));
	}

	Vector2D posbonusnorpelota = bonusnorpelota.GetPos();
	if (posbonusnorpelota.y < -30.0f){ 

		pobjetosMoviles = &bonusnorpelota;
		pobjetosMoviles->SetPos(-19 + (rand() % 38), -rand() % 100 + (rand() % 100));
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

//Para reiniciar contadores de botes si consigo pasar el balon al otro campo
	Vector2D vector_pos;
	if ((Interaccion::Colision(balon, campo.suelo_i)) && (vector_pos.x >= 0.0f)){

		contadorBotes_d = 0;
	}
	if ((Interaccion::Colision(balon, campo.suelo_d)) && (vector_pos.x <= 0.0f)){

		contadorBotes_i = 0;
	}
}

void Mundo::Inicializa()  //Inicializamos los objetos con otros valores iniciales que no sean los de por defecto.
{
	ETSIDI::playMusica("sonidos / musicafondo.mp3", true);
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

	pobjetosMoviles = &bonusespgran;
	pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom2(), pobjetosMoviles->PosyRandom2());

	pobjetosMoviles = &bonusesppeq;
	pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom4(), pobjetosMoviles->PosyRandom4());

	pobjetosMoviles = &bonusnor;
	pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom1(), pobjetosMoviles->PosyRandom1());
	pobjetosMoviles->SetColor(255, 0, 0);

	pobjetosMoviles = &bonusnorpelota;
	pobjetosMoviles->SetPos(pobjetosMoviles->PosxRandom3(), pobjetosMoviles->PosyRandom3());
	pobjetosMoviles->SetColor(255, 255, 0);

	pobjetosMoviles = &balon;
	pobjetosMoviles->SetColor(255, 255, 0);
	pobjetosMoviles->SetRadio(0.75f);
	pobjetosMoviles->SetPos(0, 9);
	pobjetosMoviles->SetVel(pobjetosMoviles->VelxRandom(), 9);

	campo.red.SetLim(0.0f, 0.0f, 0.0f, 5.0f);
		
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
						break;
	}
	case GLUT_KEY_DOWN:
	{
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

void Mundo::DibujaFondo(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-20.0f, 0.0f, -0.1f);
	glTexCoord2d(1, 1); glVertex3f(20.0f, 0.0f, -0.1f);
	glTexCoord2d(1, 0); glVertex3f(20.0f, 20.0f, -0.1f);
	glTexCoord2d(0, 0); glVertex3f(-20.0f, 20.0f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

/*void Mundo::DibujaSuelo(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/suelo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	//(x,y,z)
	glVertex3f(-20.1f, 0.1f, -0.1f);
	glVertex3f(-20.1f, 0.1f, 20.0f);
	glVertex3f(20.0f, 0.1f, 20.0f);
	glVertex3f(20.0f, 0.1f, -0.1f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}*/

void Mundo::DibujaPared_D(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/suelo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	//(x,y,z)
	glVertex3f(20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 20.0f, 20.0f);
	glVertex3f(20.0f, 20.0f, -20.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
void Mundo::DibujaPared_I(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/suelo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	//(x,y,z)
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glVertex3f(-20.0f, 20.0f, 20.0f);
	glVertex3f(-20.0f, 20.0f, -20.0f);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}