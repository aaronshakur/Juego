#include <stdio.h>
#include "math.h"
#include "glut.h"
#include "..\..\include\dominio\Interaccion.h"

ObjetoMovil *pobjetosmoviles;


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
//Se pasa el parametro hombre por referencia, ya que la funcion tiene que modificar los valores del hombre constantemente (posiciones, y velocidades)
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

//Se pasa el parametro hombre por referencia, ya que la funcion tiene que modificar los valores del hombre constantemente (posiciones, y velocidades)
{
	Vector2D dir;
	float dif = p.Distancia(h.posicion, &dir) - h.radio;
	if (dif <= 0.0f){

		h.posicion = h.posicion - dir*dif; 
		return true;
	}
	return false;
}

//Este metodo llama a cada rebote individual del balon con las 5 paredes.
//Posteriormente, llamaremos a este metodo desde mundo.
//Se pasa el parametro balon por referencia, ya que la funcion tiene que modificar los valores del hombre constantemente (posiciones, y velocidades)


void Interaccion::Rebote(Balon &b, Campo c)
{
	
	Interaccion::ReboteSuelo(b, c.suelo);
	Interaccion::Rebote(b, c.techo);
	Interaccion::Rebote(b, c.pared_dcha);
	Interaccion::Rebote(b, c.pared_izq);
	Interaccion::Rebote(b, c.red);

}

//En este metodo, interaccionamos el balon con las paredes, en funcion de la Distancia calculada en otro metodo de Pared.
//Se pasa el parametro balon por referencia, ya que la funcion tiene que modificar los valores del hombre constantemente (posiciones, y velocidades)

bool Interaccion::Rebote(Balon &b, Pared p)
{
	Vector2D dir;
	float dif = p.Distancia(b.posicion, &dir) - b.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = b.velocidad;
		b.velocidad = v_inicial - dir*2.0*(v_inicial*dir);
		b.posicion = b.posicion - dir*dif;
		return true;
	}
	return false;
}

//Metodo para que disminuye la velocidad de la pelota paulatinamente

bool Interaccion::ReboteSuelo(Balon &b, Pared suelo) {

	Vector2D dir;

	float dif = suelo.Distancia(b.posicion, &dir) - b.radio;
	if (dif <= 0.0f){

		Vector2D v_inicial = b.velocidad;
		b.velocidad = v_inicial - dir*2.0*(v_inicial*dir);
		b.posicion = b.posicion - dir*dif;
		b.velocidad = b.velocidad - b.velocidad*0.25f;   
		
		return true;
	}
	return false;
}

//Codigo rebote dos esferas 

bool Interaccion::Rebote(Balon &b, Hombre &h) {

	//Vector que une los centros
	Vector2D dif = h.posicion - b.posicion;
	float d = dif.modulo();
	float dentro = d - (b.radio + h.radio);

	if (dentro<0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad del balon
		float v1 = b.velocidad.modulo();
		float ang1 = b.velocidad.argumento();

		//El modulo y argumento de la velocidad del hombre
		float v2 = 0; //h.velocidad.modulo();
		float ang2 = 0;//h.velocidad.argumento();

		//el argumento del vector que une los centros
		float angd = dif.argumento();

		//Separamos las esferas, lo que se han incrustado la mitad cada una
		//Vector con dos componentes que sumo 
		Vector2D desp(dentro / 2 * (float)cos(angd), dentro / 2 * (float)sin(angd));  
		b.posicion = b.posicion + desp;
		h.posicion = h.posicion; //- desp //la posicion del hombre no debe ser modificada

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1*(float)cos(th1);
		float u1y = v1*(float)sin(th1);
		float u2x = v2*(float)cos(th2);
		float u2y = v2*(float)sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = b.radio;
		float m2 = h.radio;
		float py = m1*u1y + m2*u2y;//Cantidad de movimiento inicial ejey
		float ey = m1*u1y*u1y + m2*u2y*u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2*m2 + m1*m2;
		float bb = -2 * py*m2;
		float c = py*py - m1*ey;
		float disc = bb*bb - 4 * a*c;
		if (disc<0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-bb + (float)sqrt(disc)) / (2 * a);
		float v1y = (py - m2*v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = (float)sqrt(v1x*v1x + v1y*v1y);
		modv2 = (float)sqrt(v2x*v2x + v2y*v2y);
		fi1 = angd + (float)atan2(v1y, v1x);
		fi2 = angd + (float)atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes

		if (b.posicion.y > h.posicion.y) {

		b.velocidad.x = (modv1*(float)cos(fi1));
		b.velocidad.y = (modv1*(float)sin(fi1)) + 5;
		h.velocidad.x = h.velocidad.x; //modv2*cos(fi2); //la velocidad del hombre no tiene que cambiar, si lo dejo desaparece el hombre
		h.velocidad.y = h.velocidad.y; //modv2*sin(fi2);
		}
		else {

		b.velocidad.x = 1.1f*(modv1*(float)cos(fi1));
		b.velocidad.y = (modv1*(float)sin(fi1)) -15;
		h.velocidad.x = modv2*cos(fi2); //la velocidad del hombre no tiene que cambiar, si lo dejo desaparece el hombre
		h.velocidad.y = modv2*sin(fi2); 
		//probar mas adelante a separar h1 y h2. haciendo negativo el rebote de hombre 2
		}

		
		}
		
	return false;

}

//funcion de informacion, solo devuelven true si hay bote

bool Interaccion::Colision(Balon b, Pared suelo){

	if (Interaccion::ReboteSuelo(b, suelo))
		return true;
	else
		return false;

}
 //Este metodo solo sirve para ver si han colisionado bonus y hombres. No modifica.
bool Interaccion::Colision(Bonus bon, Hombre h){

	Vector2D pos = h.GetPos(); //la posicion del hombre 
	pos.y += h.GetRadio()/ 2.0f; //posicion del centro del hombre

	float distancia = (bon.posicion- pos).modulo();
	if (distancia < bon.lado){
		printf("\nHa habido colision");
		return true;
	}
	return false;
}

/*void Interaccion::Colision(Bonus &bon, Hombre &h){

		Vector2D pos = h.GetPos(); //la posicion del hombre 
		pos.y += h.GetRadio() / 2.0f; //posicion del centro del hombre

		float distancia = (bon.posicion - pos).modulo();

		if (distancia < bon.radio)
		{
			//Algo para que mande a la posicion inicial de cada bonus (normal o especial)
			//********************************************************
			bon.SetPos(8,30);
			//pobjetosMoviles = &bon;
			//pobjetosMoviles->bonus.SetPos(8,30);
			//********************************************************

			if (h.radio < 5.0f)
				h.radio = h.radio + 0.2f;
			else h.radio = 5.0f;
		}
		printf("Ha habido colision");
}*/
/*
void Interaccion::Colision2(Bonus &b, Hombre &h){

	float dist = ((b.posicion) - (h.posicion)).modulo();
	if (dist<h.radio)
	{
		b.posicion.y = 150.0f;
		if (h.radio>1.0f)
			h.radio = h.radio - 0.5f;
		else h.radio = 1.0f;
	}

}*/