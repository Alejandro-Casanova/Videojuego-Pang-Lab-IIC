#include "Esfera.h"
#include "freeglut.h"

Esfera::Esfera()
{
	r = g = b = 255; //blanco
	radio = 1.0f;
	aceleracion.y = -9.8f;
}

Esfera::~Esfera(){
}

void Esfera::dibuja() {
	glColor3ub(r, g, b);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Esfera::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}
