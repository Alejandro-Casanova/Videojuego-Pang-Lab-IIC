#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() : _radio(0.25f) 
{
	//TEMPORAL
	_origen.x = 0;
	_origen.y = 0;
}

Disparo::~Disparo()
{
}

void Disparo::dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(_posicion.x, _posicion.y, 0);
	glutSolidSphere(_radio, 20, 20);
	glPopMatrix();

	//Dibuja Estela
	glBegin(GL_LINES);
	glVertex3f(_origen.x, _origen.y, 0.0f);
	glVertex3f(_posicion.x, _posicion.y, 0.0f);
	glEnd();
}

void Disparo::mueve(float t)
{
	_posicion = _posicion + _velocidad * t + _aceleracion * (0.5f * t * t);
	_velocidad = _velocidad + _aceleracion * t;
}
