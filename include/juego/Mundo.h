#include "..\..\include\dominio\Bonus.h"
#include "..\..\include\dominio\Campo.h"
#include "..\..\include\dominio\Pared.h"
#include "..\..\include\dominio\Hombre.h"
#include "..\..\include\dominio\Balon.h"

class Mundo
{
<<<<<<< HEAD

private:

=======
private:
>>>>>>> refs/remotes/origin/master
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Balon balon;		//Creamos los objetos para instanciarlos en Mundo. De esta manera, cuando se instancie el objeto Mundo, 
	Campo campo;		//se instanciaran todos estos objetos.
	Hombre hombre1, hombre2;
	Bonus bonus;
<<<<<<< HEAD

public: 
	
=======
public:
>>>>>>> refs/remotes/origin/master
	//Metodos
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void SetPos(float,float,float); //Necesario??

	
};
