#include "Bonus.h"
#include "freeglut.h"
#include <stdlib.h>

Bonus::Bonus() : _lado(2.0f)
{
}

Bonus::~Bonus()
{
}

void Bonus::dibuja() {
	glPushMatrix();
	glTranslatef(_posicion.x, _posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(_lado);
	glPopMatrix();
}

void Bonus::mueve(float t)
{
	_posicion = _posicion + _velocidad * t + _aceleracion * (0.5f * t * t);
	_velocidad = _velocidad + _aceleracion * t;
}
