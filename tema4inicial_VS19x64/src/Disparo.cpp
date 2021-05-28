#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() 
{
	setColor(255, 255, 255);
	setVel(0.0f, 7.5f);
}

Disparo::~Disparo()
{
	(*_nDisparosPtr)++; //Recupera los disparos que impactan
}

void Disparo::dibuja() const {
	dibujaDisparo();
	dibujaEstela(0.0f);
}

void Disparo::dibujaDisparo() const
{
	_color.ponColor();
	glPushMatrix();
	glTranslatef(_posicion.x, _posicion.y, 0);
	glutSolidSphere(_radio, 20, 20);
	glPopMatrix();
}

void Disparo::dibujaEstela(float offset) const
{
	//Dibuja Estela
	_color.ponColor();
	glBegin(GL_LINES);
	glVertex3f(_origen.x + offset, _origen.y, 0.0f);
	glVertex3f(_posicion.x + offset, _posicion.y, 0.0f);
	glEnd();
}

