#include "Plano.h"
#include "freeglut.h"

void Plano::setColor(unsigned char rojo, unsigned char verde, unsigned char azul) {
	r = rojo;
	g = verde;
	b = azul;
}

void Plano::setPos(float ix, float iy, float iz) {
	x = ix;
	y = iy;
	z = iz;
}

void Plano::dibuja() {
	float radio = lado / 2.0f;

	glColor3ub(r, g, b);
	glTranslatef(x, 0.0f, 0.0f);
	glTranslatef(0.0f, y, 0.0f);
	glTranslatef(0.0f, 0.0f, z);

	glDisable(GL_LIGHTING);
	glBegin(GL_QUADS);
	
	glVertex3f(-radio, -radio, 0);
	glVertex3f(-radio, radio, 0);
	glVertex3f(radio, radio, 0);
	glVertex3f(radio, -radio, 0);
	glEnd();
	glEnable(GL_LIGHTING);


	glTranslatef(-x, 0.0f, 0.0f);
	glTranslatef(0.0f, -y, 0.0f);
	glTranslatef(0.0f, 0.0f, -z);
}