#include <stdlib.h>
#include <iostream>
#include "..\include\juego\CoordinadorJuego.h"
#include "ETSIDI.h"
#include "..\..\include\dominio\Interaccion.h"

#define maxBotes 3
#define maxPuntos 3
using namespace std;
CoordinadorJuego::CoordinadorJuego(){
	estado = INICIO;
	mundo.SetGanadorD();
	mundo.SetGanadorI();
}

CoordinadorJuego::~CoordinadorJuego(){}

//SECUENCIA DEL DIAGRAMA DE ESTADOS SEGUN TECLA PULSADA
void CoordinadorJuego::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		//PULSAMOS EMPEZAR LA PARTIDA
		if (key == 'e')
			estado = PREPARADO;
		if (key == 's')
			exit(0);
	}
		
	else if (estado == PREPARADO){
		//ESPERAMOS HASTA QUE SE PULSE ESPACIO PARA LANZAR LA BOLA
		if (key == ' ')
			estado = JUEGO;
	}

	else if (estado == JUEGO){
		//SE EMPIEZAN A MOVER LOS OBJETOS Y SE INICIA JUEGO
		mundo.Tecla(key);
	}

	else if (estado == PUNTO)
		//SE HA MARCADO UN PUNTO, SE ESPERA A QUE SE PULSE ESPACIO PARA LANZAR OTRO BALON
	{
		if (key == ' ')
			estado = INICIO;
	}
	else if (estado == FIN)
		//SE HA ACABADO LA PARTIDA, SE ESPERA A QUE SE PULSE ESPACIO PARA REVANCHA O S PARA SALIR
	{
		if (key == ' '){
			estado = PREPARADO;
			system("cls");
		}
		if (key == 's'){
			exit(0);
			system("cls");
		}
	}
}

void CoordinadorJuego::TeclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.TeclaEspecial(key);
}

void CoordinadorJuego::Inicializa(){
	
	x_ojo = 1.5;
	y_ojo = 9;
	z_ojo = 42;

	mundo.Inicializa();
	
}
void CoordinadorJuego::Dibuja()
{
	if (estado == INICIO){
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

		DibujaPortada();
		PortadaLetras();


	}
	else if (estado == PREPARADO)
	{
		mundo.Inicializa();
		mundo.Dibuja();
		InicioPuntoLetras();
	}
	else if (estado == JUEGO)
	{
		mundo.Dibuja();
	

	}
	else if (estado == PUNTO)
	{
		mundo.Dibuja();
		InicioPuntoLetras();
		
	}	
	else if (estado == FIN)
	{

		mundo.Dibuja();
		FinJuegoLetras();
	
			
	}
}

void CoordinadorJuego::Mueve()
{
	if (estado == JUEGO)
	{
		mundo.Mueve();
		int botes_d = mundo.GetBoteD();
		int botes_i = mundo.GetBoteI();
		int puntos_d = mundo.GetPuntoD();
		int puntos_i = mundo.GetPuntoI();
		if ((botes_d == maxBotes) || (botes_i == maxBotes))
		{
			cout<<"------------------------------------MARCADOR------------------------------------ \n\t\t\t    Cristiano " <<puntos_d <<" - Messi "<< puntos_i<<"\n"<<endl;
			
			estado = PREPARADO;

		}

		if (puntos_d == maxPuntos) 
		{
			
			mundo.SetPuntosI();
			cout<<"\t     Cristiano es el ganador!!( y el mejor jugador del mundo)"<<endl;
			estado = FIN;
		}
		else if (puntos_i == maxPuntos){

			mundo.SetPuntosD();
			cout<<"\t\t\t    Messi es el ganador!!!"<<endl;
			estado = FIN;
		}
	}

}

void CoordinadorJuego::DibujaPortada(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/portada.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-20.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(20.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(20.0f, 20.0f, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(-20.0f, 20.0f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void CoordinadorJuego::PortadaLetras(){

	glTranslatef(-18.0f, 8.0f, 1.0f); //traslada posicion relativa
	ETSIDI::setTextColor(0, 0, 1);
	ETSIDI::print("Pulse (e) para empezar", "fuentes/Bitwise.ttf", 10);

	glTranslatef(28.0f, 0.0f, 1.0f);
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::print("Pulse (s) para salir", "fuentes/Bitwise.ttf");

	glTranslatef(-18.5f, -6.0f, 1.0f);
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::print("Aaron Marin   &   Miguel Angel Huerta", "fuentes/Bitwise.ttf", 16);
}

void CoordinadorJuego::InicioPuntoLetras(){

	glTranslatef(-5.0f, 18.0f, 1.0f);
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::print("Pulsa (espacio) para empezar", "fuentes/Bitwise.ttf", 12);

}

void CoordinadorJuego::FinJuegoLetras(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/FinPunto.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-20.0f, 0.0f, 0.1f);
	glTexCoord2d(1, 1); glVertex3f(20.0f, 0.0f, 0.1f);
	glTexCoord2d(1, 0); glVertex3f(20.0f, 20.0f, 0.1f);
	glTexCoord2d(0, 0); glVertex3f(-20.0f, 20.0f, 0.1f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glTranslatef(-4.0f, 18.0f, 1.0f);
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::print("Pulsa (espacio) para revancha!", "fuentes/Bitwise.ttf", 12);
	
	glTranslatef(0.0f, -2.0f, 0.0f);
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::print("Pulsa (s) para salir", "fuentes/Bitwise.ttf", 12);

	
	if (mundo.GetGanadorD()){
		glTranslatef(14.0f, -14.5f, 0.0f);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::print("Messi", "fuentes/Bitwise.ttf", 12);
	
		
		
	}

	if (mundo.GetGanadorI()){
		glTranslatef(-10.0f, -14.5f, 0.0f);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::print("Cristiano ", "fuentes/Bitwise.ttf", 12);
	
		
		
	}
}

	
