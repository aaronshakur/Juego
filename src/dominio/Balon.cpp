#include "..\..\include\dominio\Balon.h"
#include "glut.h"

Balon::Balon():sprite("imagenes/balon.png", -1),sprite2("imagenes/balon.png") //No tocar! 
{
	// constructor de balon. Damos valores iniciales

	sprite.setCenter(1.5f,2.5f); //No tocar!
	sprite.setSize(5, 5); 

<<<<<<< HEAD
	sprite2.setCenter(5.7f, 5.25f);
=======
	sprite2.setCenter(5.70f, 5.25f);
>>>>>>> refs/remotes/origin/master
	sprite2.setSize(11.5, 11.5);

	rojo = verde = azul = 255; //blanco
	aceleracion.y = -9.8f;
}

Balon::~Balon()
{
}

void Balon::Dibuja(){
	
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

<<<<<<< HEAD
	//Antigua pelota
//	glutSolidSphere(radio, 20, 20);
	
	//gestion de direccion y animacion
	if (radio == 0.75f)
		sprite.draw();
	else if (radio==2.0f)
		sprite2.draw();

=======
	//gestion de direccion y animacion
	if (radio == 0.75f){
		sprite.draw();
	}
	else if (radio == 2.0f){
		sprite2.draw();
	}
>>>>>>> refs/remotes/origin/master
	glPopMatrix();
}

void Balon::Mueve(float t){

	posicion= posicion + velocidad*t + aceleracion*(t*t*0.5f); // usando metodos sobrecargados de Vector2d
	velocidad= velocidad+ aceleracion*t;
	if (posicion.y <= 0.5) // para que la pelota no desaparezca nunca.
		posicion.y = 0.5;
	
}
