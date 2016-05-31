#include "..\..\include\dominio\Bonus.h"
#include "..\..\include\dominio\Campo.h"
#include "..\..\include\dominio\Pared.h"
#include "..\..\include\dominio\Hombre.h"
#include "..\..\include\dominio\Balon.h"
#include "..\..\include\dominio\BonusEspecial.h"
#include "..\..\include\dominio\BonusNormal.h"

class Mundo
{
private:

	float x_ojo;
	float y_ojo;
	float z_ojo;
	Balon balon;		//Creamos los objetos para instanciarlos en Mundo. De esta manera, cuando se instancie el objeto Mundo, 
	Campo campo;		//se instanciaran todos estos objetos.
	Hombre hombre1, hombre2;//Hombre1 es el de las teclas de control. Hombre2 teclas "WASD"
	BonusEspecial bonusesp;
	BonusNormal bonusnor;
	Pared suelo;

	int contadorBotes_d;
	int contadorPuntos_d;
	int contadorBotes_i;
	int contadorPuntos_i;
	bool punto;
	bool bote;
	bool mivariable;

	friend class campo;
	friend class interaccion;
	

public: 

	//Metodos
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	int GetBoteD(){ return contadorBotes_d; }
	int GetBoteI(){ return contadorBotes_i; }
	int GetPuntoD(){ return contadorPuntos_i;  }
	int GetPuntoI(){  return contadorPuntos_d; }
	void SetPuntosD();
	void SetPuntosI();

};
