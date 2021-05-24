#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre() : _altura(1.8f)
{
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}

Hombre::~Hombre()
{
}

void Hombre::dibuja() {
	glPushMatrix();
	glTranslatef(_posicion.x, _posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	
	//glutSolidSphere(_altura, 20, 20);

	//gestion de direccion y animacion
	if (_velocidad.x > 0.01)sprite.flip(false, false);
	if (_velocidad.x < -0.01)sprite.flip(true, false);
	if ((_velocidad.x < 0.01) && (_velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();
}