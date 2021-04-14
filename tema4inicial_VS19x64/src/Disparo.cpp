#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() : radio(0.25f) 
{
	//TEMPORAL
	origen.x = 0;
	origen.y = 0;
}

Disparo::~Disparo()
{
}

void Disparo::dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	//Dibuja Estela
	glBegin(GL_LINES);
	glVertex3f(origen.x, origen.y, 0.0f);
	glVertex3f(posicion.x, posicion.y, 0.0f);
	glEnd();
}

void Disparo::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}
