#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"

Mundo::Mundo()
{
}

Mundo::~Mundo() {
}

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

	hombre.dibuja();
	disparos.dibuja();
	disparo.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	caja.dibuja();

	esferas.dibuja();
	
}

void Mundo::mueve()
{
	hombre.mueve(0.025f); 
	bonus.mueve(0.025f); 
	disparo.mueve(0.025f);
	esferas.mueve(0.025f); 
	disparos.mueve(0.025f);

	esferas.rebote(); 
	esferas.rebote(plataforma); 
	esferas.rebote(caja); 
	disparos.colision(plataforma);
	disparos.colision(caja);

	Esfera* aux = esferas.colision(hombre); 
	if (aux != 0)//si alguna esfera ha chocado 
		esferas.eliminar(aux); 

	Interaccion::rebote(hombre,caja);
}

void Mundo::inicializa()
{
	x_ojo=0.0f;
	y_ojo=0.0f;
	z_ojo=30.0f;

	Esfera* esfera = new Esfera(1.5f, 2.0f, 4.0f, 5.0f, 15.0f);;
	esfera->setColor(0, 0, 255);
	esferas.agregar(esfera);

	Esfera* esfera2 = new Esfera(2.0f, -2.0f, 4.0f, -5.0f, 15.0f);;
	esfera->setColor(255, 255, 255);
	esferas.agregar(esfera);
	
	bonus.setPos(5.0f, 5.0f);
	disparo.setPos(-5.0f, 0.0f);
	plataforma.setLimites(-7.0f, 5.0f, 7.0f, 5.0f);

	for (int i = 0; i < 3; i++) { 
		Esfera* aux = new Esfera(0.75 + i * 0.25, i, 1 + i, i, i); 
		esferas.agregar(aux); 
	}
}

void Mundo::tecla(unsigned char key)
{
	switch (key) { 
	case '1': esferas.agregar(new Esfera(0.5f, 10, 0)); 
		break; 
	case '2': esferas.agregar(new Esfera(1.0f, 0, 10)); 
		break; 
	case '3': esferas.agregar(new Esfera(1.5f, 0, 10)); 
		break; 
	case '4': esferas.agregar(new Esfera(2.0f, 0, 10)); 
		break; 
	case ' ':
		Disparo* d = new Disparo(); 
		Vector2D pos = hombre.getPos(); 
		d->setPos(pos.x, pos.y); 
		d->setOrigen(pos.x, pos.y);
		d->setVel(0.0f, 5.0f);
		disparos.agregar(d); 
		break; 
	}
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
