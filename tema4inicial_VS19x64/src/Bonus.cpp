#include "Bonus.h"
#include "freeglut.h"
#include <stdlib.h>

Bonus::Bonus() : _lado(1.0f)
{
	_aceleracion.y = -9.8f;
}

Bonus::Bonus(Vector2D pos) : _lado(1.0f)
{
	_aceleracion.y = -9.8f;
	setPos(pos.x, pos.y);
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