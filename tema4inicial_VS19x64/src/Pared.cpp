#include "Pared.h"
#include "freeglut.h"

Pared::Pared() : r(255), g(255), b(255)
{

}

Pared::~Pared()
{
}

void Pared::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}