#include "..\..\include\comun\Vector2D.h"
#include "math.h"


Vector2D::Vector2D(float xv, float yv)//constructor de Vector2D. Damos valores iniciales
{
	x = xv;
	y = yv;
}

Vector2D::~Vector2D()
{
}

float Vector2D::modulo()
{
	return (float)sqrt(x*x + y*y);
}

float Vector2D::argumento()
{
	return(float)atan2(y,x);
}

Vector2D Vector2D::Unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod>0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D &v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector2D Vector2D::operator + (Vector2D &v)
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}
Vector2D Vector2D::operator * (float n)//Produco por un escalar
{
	Vector2D resultado;
	resultado.x = x*n;
	resultado.y = y*n;
	return resultado; // devuelve vector
}

float Vector2D::operator * (Vector2D &v) //Producto escalar de vectores
{
	float resul = x*v.x + y*v.y;
	return (resul);// devuelve escalar
}