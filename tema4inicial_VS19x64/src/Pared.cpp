#include "Pared.h"
#include "freeglut.h"

Pared::Pared(){

}

Pared::~Pared(){

}

void Pared::dibuja() {
	glDisable(GL_LIGHTING);
	_color.ponColor();
	//lColor3ub(_r, _g, _b);
	glBegin(GL_POLYGON);
	glVertex3d(_limite1.x, _limite1.y, 10);
	glVertex3d(_limite2.x, _limite2.y, 10);
	glVertex3d(_limite2.x, _limite2.y, 0);
	glVertex3d(_limite1.x, _limite1.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

float Pared::distancia(Vector2D punto, Vector2D* direccion) const
{
	Vector2D u = (punto - _limite1);
	Vector2D v = (_limite2 - _limite1).unitario();
	float longitud = (_limite1 - _limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - _limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}