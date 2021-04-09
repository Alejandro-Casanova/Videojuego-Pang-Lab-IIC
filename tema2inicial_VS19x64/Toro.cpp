#include "Toro.h"
#include "freeglut.h"

void Toro::setColor(unsigned char rojo, unsigned char verde, unsigned char azul) {
	r = rojo;
	g = verde;
	b = azul;
}

void Toro::setRadio(float ir1, float ir2) {
	r1 = ir1;
	r2 = ir2;
}

void Toro::setPos(float ix, float iy, float iz) {
	x = ix;
	y = iy;
	z = iz;
}

void Toro::mueve() {
	z += 0.1f;
	if (z > 3.0f)
		z = -3.0f;
}

void Toro::dibuja() {
	glColor3ub(r, g, b);
	glTranslatef(x, 0.0f, 0.0f);
	glTranslatef(0.0f, y, 0.0f);
	glTranslatef(0.0f, 0.0f, z);
	glutSolidTorus(r1, r2, 20, 20);
	glTranslatef(-x, 0.0f, 0.0f);
	glTranslatef(0.0f, -y, 0.0f);
	glTranslatef(0.0f, 0.0f, -z);
}