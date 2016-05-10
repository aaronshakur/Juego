#pragma once

class Vector2D
{

public:
	//atributos
	float x, y;
	
	//metodos
	Vector2D(float xv = 0.0f, float yv = 0.0f); // (1)
	virtual ~Vector2D();
	float modulo(); //(2) modulo del vector
	float argumento(); //(3)argumento del vector
	Vector2D Unitario(); //(4)devuelve vector unitario
	Vector2D operator - (Vector2D&); //(5) restadevectores
	Vector2D operator + (Vector2D&); //(6)sumadevectores
	float operator *(Vector2D &); //(7) producto escalar 
	Vector2D operator * (float n); //(8) escalar por vector
	


};

