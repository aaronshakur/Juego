#pragma once
#include "Mundo.h"

class CoordinadorJuego
{
public:
	CoordinadorJuego();
	virtual ~CoordinadorJuego();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Inicializa();
	
protected:
	Mundo mundo;
	enum Estado { INICIO, PREPARADO, JUEGO, PUNTO, FIN };
	Estado estado;
private:

	float x_ojo;
	float y_ojo;
	float z_ojo;

	
};

