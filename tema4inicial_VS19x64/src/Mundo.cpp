#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"

void Mundo::rotarOjo()
{
	float dist=sqrtf(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2f(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cosf(ang);
	z_ojo=dist*sinf(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	esfera.dibuja();
	esfera2.dibuja();
	caja.dibuja();
	hombre.dibuja();
	disparo.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	esfera.mueve(0.025f);
	esfera2.mueve(0.025f);
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);

	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera, plataforma);
	Interaccion::rebote(esfera2, caja);
	Interaccion::rebote(esfera2, plataforma);
	Interaccion::rebote(esfera, esfera2);
}

void Mundo::inicializa()
{
	x_ojo=0.0f;
	y_ojo=0.0f;
	z_ojo=30.0f;

	esfera.setPos(2.0f,4.0f);
	esfera.setRadio(1.5f);
	esfera.setColor(0, 0, 255);
	esfera.setVel(5.0f, 15.0f);

	esfera2.setRadio(2.0f);
	esfera2.setPos(-2.0f, 4.0f);
	esfera2.setVel(-5.0f, 15.0f);
	
	bonus.setPos(5.0f, 5.0f);
	disparo.setPos(-5.0f, 0.0f);
	plataforma.setLimites(-7.0f, 5.0f, 7.0f, 5.0f);
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
		break;
	}
}
