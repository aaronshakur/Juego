#include "..\..\include\dominio\Hombre.h"
#include "glut.h"
//constructor de hombre. Damos valores iniciales

<<<<<<< HEAD
Hombre::Hombre() :
spriteHombre1Grande("imagenes/jugador1.png", -1), spriteHombre2Grande("imagenes/jugador2.png", -1),
spriteHombre1Peq("imagenes/jugador1.png", -1), spriteHombre2Peq("imagenes/jugador2.png", -1),
spriteHombre1Nor("imagenes/jugador1.png", -1), spriteHombre2Nor("imagenes/jugador2.png", -1)
=======

Hombre::Hombre() :spriteHombre1Grande("imagenes/jugador1.png", -1), spriteHombre2Grande("imagenes/jugador2.png", -1), spriteHombre1Peq("imagenes/jugador1.png", -1), spriteHombre2Peq("imagenes/jugador2.png", -1), spriteHombre1Nor("imagenes/jugador1.png", -1), spriteHombre2Nor("imagenes/jugador2.png", -1) //No tocar! 
>>>>>>> refs/remotes/origin/master
{
	rojo = verde = azul = 255; //blanco
	aceleracion.y = -9.8;

<<<<<<< HEAD
	spriteHombre1Nor.setCenter(2.5f, 3.5f); //No tocar!
	spriteHombre1Nor.setSize(6.75f, 6.75f);

	spriteHombre2Nor.setCenter(3.5f, 3.5f); //No tocar!
	spriteHombre2Nor.setSize(7.5f, 7.5f);

	spriteHombre1Grande.setCenter(4.0f, 4.5f); //No tocar!
	spriteHombre1Grande.setSize(9.0f, 9.0f);

	spriteHombre2Grande.setCenter(4.0f, 4.5f); //No tocar!
	spriteHombre2Grande.setSize(10, 10);

	spriteHombre1Peq.setCenter(1.0f, 2.0f); //No tocar!
	spriteHombre1Peq.setSize(4.0f, 4.0f);

	spriteHombre2Peq.setCenter(1.5f, 2.5f); //No tocar!
	spriteHombre2Peq.setSize(5.0f, 5.0f);

=======
	spriteHombre1Grande.setCenter(4.0f, 4.5f);
	spriteHombre1Grande.setSize(9, 9);

	spriteHombre2Grande.setCenter(4.5f, 4.5f);
	spriteHombre2Grande.setSize(10, 10);

	spriteHombre1Peq.setCenter(1.0f, 2.0f);
	spriteHombre1Peq.setSize(4, 4);

	spriteHombre2Peq.setCenter(1.5f, 2.5f);
	spriteHombre2Peq.setSize(5, 5);

	spriteHombre1Nor.setCenter(2.5f, 3.5f);
	spriteHombre1Nor.setSize(6.75f, 6.75f);

	spriteHombre2Nor.setCenter(3.5f, 3.5f);
	spriteHombre2Nor.setSize(7.5f, 7.5f);
>>>>>>> refs/remotes/origin/master
}

Hombre::~Hombre()
{
}

void Hombre::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
<<<<<<< HEAD
	//antiguos jugadores
	//glutSolidSphere(radio, 20, 20);
	
	//gestion de direccion y animacion
	if (ObjetoMovil::radio == 1.8f && ObjetoMovil::GetPosx()>0.0f)
		spriteHombre1Nor.draw();

	else if (ObjetoMovil::radio == 1.8f && ObjetoMovil::GetPosx()<0.0f)
		spriteHombre2Nor.draw();
	
	else if (ObjetoMovil::radio == 1.0f && ObjetoMovil::GetPosx()>0.0f)
		spriteHombre1Peq.draw();

	else if (ObjetoMovil::radio == 1.0f && ObjetoMovil::GetPosx()<0.0f)
		spriteHombre2Peq.draw();
	
	else if (ObjetoMovil::radio == 2.5f && ObjetoMovil::GetPosx()>0.0f)
		spriteHombre1Grande.draw();
=======
	glColor3ub(rojo, verde, azul);


	if ((ObjetoMovil::radio == 1.8f) && (ObjetoMovil::GetPos_x() >=0)) {

		spriteHombre1Nor.draw();
		

	}
	else if ((ObjetoMovil::radio == 1.8f) && (ObjetoMovil::GetPos_x() <= 0)){

		spriteHombre2Nor.draw();
	}
	
	else if ((ObjetoMovil::radio == 1.0f) && (ObjetoMovil::GetPos_x() >= 0)) {

		spriteHombre1Peq.draw();
	
	}
	else if ((ObjetoMovil::radio == 1.0f) && (ObjetoMovil::GetPos_x() <= 0)) {

		spriteHombre2Peq.draw();

	}
	else if( (ObjetoMovil::radio == 2.5f) && (ObjetoMovil::GetPos_x() >= 0)) {

		spriteHombre1Grande.draw();

	}
	else if ((ObjetoMovil::radio == 2.5f) && (ObjetoMovil::GetPos_x() <= 0)) {

		spriteHombre2Grande.draw();

	}


	glPopMatrix();
>>>>>>> refs/remotes/origin/master

	else if (ObjetoMovil::radio == 2.5f && ObjetoMovil::GetPosx()<0.0f)
		spriteHombre2Grande.draw();
	

	glPopMatrix();
}

void Hombre::Mueve(float t){

	posicion = posicion + velocidad*t + aceleracion*(t*t*0.5f);   //no puede ser escalar*vector!!! debe ser Vector2D* escalar!! debido a la declaracion en Vector2D.cpp
	velocidad = velocidad + aceleracion*t;
		if (posicion.y <= 0.9) // para que el jugador no desaparezca al ponerle aceleracion negativa para el salto.
		posicion.y = 0.9;	
}


