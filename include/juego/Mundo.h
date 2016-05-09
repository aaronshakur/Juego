#include "..\..\include\dominio\Bonus.h"
#include "..\..\include\dominio\Campo.h"
#include "..\..\include\dominio\Pared.h"
#include "..\..\include\dominio\Hombre.h"
#include "..\..\include\dominio\Balon.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;

	//Creamos los objetos para instanciarlos en Mundo. De esta manera, cuando se instancie el objeto Mundo, 
	//se instanciaran todos estos objetos.
	Balon balon;
	Campo campo;
	Hombre hombre1, hombre2;
	Bonus bonus;
public:
	//Metodos
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void SetColor(); //Necesario??

	
};
