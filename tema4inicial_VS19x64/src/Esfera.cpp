#include "Esfera.h"
#include "freeglut.h"

Esfera::Esfera()
{
	_r = _g = _b = 255; //blanco
	_radio = 1.0f;
	_aceleracion.y = -9.8f;
}

Esfera::~Esfera(){
}

void Esfera::dibuja() {
	glColor3ub(_r, _g, _b);
	glTranslatef(_posicion.x, _posicion.y, 0);
	glutSolidSphere(_radio, 20, 20);
	glTranslatef(-_posicion.x, -_posicion.y, 0);
}

void Esfera::mueve(float t)
{
	_posicion.x = _posicion.x + _velocidad.x * t + 0.5f * _aceleracion.x * t * t;
	_posicion.y = _posicion.y + _velocidad.y * t + 0.5f * _aceleracion.y * t * t;
	_velocidad.x = _velocidad.x + _aceleracion.x * t;
	_velocidad.y = _velocidad.y + _aceleracion.y * t;
}

void Esfera::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	_r = r;
	_g = g;
	_b = b;
}

void Esfera::setRadio(float radio)
{
	_radio = radio;
}

void Esfera::setPos(float x, float y)
{
	_posicion.x = x;
	_posicion.y = y;
}
