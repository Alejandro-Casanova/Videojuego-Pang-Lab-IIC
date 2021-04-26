#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre() : _altura(1.8f)
{
}

Hombre::~Hombre()
{
}

void Hombre::dibuja() {
	glPushMatrix();
	glTranslatef(_posicion.x, _posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(_altura, 20, 20);
	glPopMatrix();
}

void Hombre::mueve(float t)
{
	_posicion = _posicion + _velocidad * t + _aceleracion * (0.5f * t * t);
	_velocidad = _velocidad + _aceleracion * t;
}

void Hombre::setVel(float vx, float vy){
	_velocidad.x = vx;
	_velocidad.y = vy;
}