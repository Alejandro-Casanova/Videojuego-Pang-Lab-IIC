#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

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
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);
}

void Mundo::inicializa()
{
	x_ojo=0.0f;
	y_ojo=0.0f;
	z_ojo=30.0f;

	esfera.setPos(2.0f,4.0f);
	esfera.setRadio(1.5f);
	esfera.setColor(0, 0, 255);
	
	bonus.posicion.x = 5.0f;
	bonus.posicion.y = 5.0f;
	disparo.posicion.x = -5.0f;
	disparo.posicion.y = 0.0f;
	plataforma.setLimites(-7.0f, 5.0f, 7.0f, 5.0f);
}

void Mundo::tecla(unsigned char key)
{

}
