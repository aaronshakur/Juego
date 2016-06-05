#include "..\..\include\dominio\Balon.h"
#include "glut.h"

Balon::Balon():sprite("imagenes/balon.png", -1)//,sprite2("imagenes/balon.png") //No tocar! 
{
	// constructor de balon. Damos valores iniciales

	sprite.setCenter(1.5f,2.5f); //No tocar!
	sprite.setSize(5, 5); 

	//sprite2.setCenter(1.5f, 2.5f);
	//sprite2.setSize(10, 10);

	rojo = verde = azul = 255; //blanco
	aceleracion.y = -9.8f;
}

Balon::~Balon()
{
}

void Balon::Dibuja(){
	
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

	//gestion de direccion y animacion
	sprite.draw();
	glPopMatrix();
}

void Balon::Mueve(float t){

	posicion= posicion + velocidad*t + aceleracion*(t*t*0.5f); // usando metodos sobrecargados de Vector2d
	velocidad= velocidad+ aceleracion*t;
	if (posicion.y <= 0.5) // para que la pelota no desaparezca nunca.
		posicion.y = 0.5;
	
}
