#include "..\include\comun\glut.h"
#include "..\..\include\dominio\Interaccion.h"

//En esta clase no se van a generar objetos. Va a reunir todos los metodos de interaccion entre parejas de objetos.
//Ademas, todos los objetos que interaccionen, necesitaran ser amigos de esta clase, ya que estamos intentando acceder a sus
//atributos privados

Interaccion::Interaccion()    //constructor de interaccion. 
{
}

Interaccion::~Interaccion()
{
}

//Este metodo llama a cada rebote individual de los hombres con las 5 paredes.
//Posteriormente, llamaremos a este metodo desde mundo.
void Interaccion::Rebote(Hombre &h, Campo c)   
{
	Interaccion::Rebote(h, c.suelo);
	Interaccion::Rebote(h, c.techo);
	Interaccion::Rebote(h, c.pared_dcha);
	Interaccion::Rebote(h, c.pared_izq);
	Interaccion::Rebote(h, c.red);
	
}

//En este metodo, interaccionamos los hombres con las paredes, en funcion de la Distancia calculada en otro metodo de Pared.
bool Interaccion::Rebote(Hombre &h, Pared p)
{
	Vector2D dir;
	float dif = p.Distancia(h.posicion, &dir) - h.altura;
	if (dif <= 0.0f){

		h.posicion = h.posicion - dir*dif;
		return true;
	}
	return false;


}