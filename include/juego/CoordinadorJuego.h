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
	enum Estado { INICIO, JUEGO, PUNTO, FIN };
	Estado estado;
};

