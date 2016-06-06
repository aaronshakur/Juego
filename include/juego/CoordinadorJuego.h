#pragma once
#include <stdlib.h>
#include "Mundo.h"
#include "ETSIDI.h"

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
	void DibujaPortada();
	void PortadaLetras();
	void InicioPuntoLetras();
	void FinJuegoLetras();


protected:
	Mundo mundo;
	enum Estado { INICIO, PREPARADO, JUEGO, PUNTO, FIN };
	Estado estado;

private:

	float x_ojo;
	float y_ojo;
	float z_ojo;
	friend class Mundo;
};

