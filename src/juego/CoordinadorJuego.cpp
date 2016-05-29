#include "..\include\juego\CoordinadorJuego.h"
#include "..\include\comun\ETSIDI.h"
#include "..\..\include\dominio\Interaccion.h"
#define maxBotes 3
#define maxPuntos 3

CoordinadorJuego::CoordinadorJuego()
{
	estado = INICIO;
	
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
		if (key == ' ')
			estado = INICIO; 
		if (key == 's')
			exit(0);
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

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("Bitwise.ttf", 16);
		ETSIDI::printxy("CABEZONES", -5, 8);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -e- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -s- PARA SALIR", -5, 6);
		ETSIDI::printxy("Aaron Marin & Miguel Angel Huerta", 2, 1);
	}
	else if (estado == PREPARADO)
	{
		ETSIDI::printxy("PULSE LA TECLA -ESPACIO- PARA SACAR", -5, 7);
		mundo.Inicializa();
		mundo.Dibuja();
	}
	else if (estado == JUEGO)
	{
		mundo.Dibuja();
<<<<<<< HEAD
		mundo.GetBote();
//		mundo.GetPunto();
=======
		
>>>>>>> refs/remotes/origin/RamaAaron
	}
	else if (estado == PUNTO)
	{
		mundo.Dibuja();

		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("Bitwise.ttf", 16);
		ETSIDI::printxy("PUNTO!!", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -ESPACIO- PARA VOLVER SACAR", -5, 7);
	}	
	else if (estado == FIN)
	{
		mundo.Dibuja();

		ETSIDI::setFont("Bitwise.ttf", 16);
		ETSIDI::printxy("FIN DEL PARTIDO!", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -ESPACIO- PARA LA REVANCHA!", -5, 9);
	}
}

void CoordinadorJuego::Mueve()
{
	
	if (estado == JUEGO)
	{
		mundo.Mueve();
		int botes = mundo.GetBote();
		if (botes==maxBotes)
		{
			estado = PREPARADO;
		}
<<<<<<< HEAD
		//if (mundo.GetPunto()==1)
		//{
		//	estado = FIN;
		//}
=======

		int puntos = mundo.GetPunto();
		if (puntos==maxPuntos)
		{
			mundo.SetPuntos();
			estado = FIN;

		}
>>>>>>> refs/remotes/origin/RamaAaron
	}
}