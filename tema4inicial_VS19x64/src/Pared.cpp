#include "Pared.h"
#include "freeglut.h"

Pared::Pared(){

}

Pared::~Pared(){

}

void Pared::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(_r, _g, _b);
	glBegin(GL_POLYGON);
	glVertex3d(_limite1.x, _limite1.y, 10);
	glVertex3d(_limite2.x, _limite2.y, 10);
	glVertex3d(_limite2.x, _limite2.y, -10);
	glVertex3d(_limite1.x, _limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	_r = r;
	_g = g;
	_b = b;
}

void Pared::setLimites(float limite1x, float limite1y, float limite2x, float limite2y)
{
	_limite1.x = limite1x;
	_limite1.y = limite1y;
	_limite2.x = limite2x;
	_limite2.y = limite2y;
}
