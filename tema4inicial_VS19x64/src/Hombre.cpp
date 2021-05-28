#include "Hombre.h"
#include "freeglut.h"
#include "GestorDeTeclado.h"

Hombre::Hombre() : _altura(1.8f)
{
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
	setPos(0.0f, -7.5f);
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

void Hombre::mueve(float t)
{
	if (GestorDeTeclado::isKeyPressed(GLUT_KEY_LEFT)) {
		_velocidad.x -= 5.0f;
	}
	if (GestorDeTeclado::isKeyUnPressed(GLUT_KEY_LEFT)) {
		_velocidad.x += 5.0f;
	}
	if (GestorDeTeclado::isKeyPressed(GLUT_KEY_RIGHT)) {
		_velocidad.x += 5.0f;
	}
	if (GestorDeTeclado::isKeyUnPressed(GLUT_KEY_RIGHT)) {
		_velocidad.x -= 5.0f;
	}
	ObjetoMovil::mueve(t);
	sprite.loop();
}
