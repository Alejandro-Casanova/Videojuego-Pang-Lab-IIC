#include "Caja.h"
#include "ETSIDI.h"

Caja::Caja()
{
	_pared_izq.setLimites(-_ancho / 2.0f, -_alto / 2.0f, -_ancho / 2.0f, _alto / 2.0f);
	_pared_izq.setColor(0, 255, 0);

	_pared_dcha.setLimites(_ancho / 2.0f, -_alto / 2.0f, _ancho / 2.0f, _alto / 2.0f);
	_pared_dcha.setColor(0, 255, 0);

	_techo.setLimites(-_ancho / 2.0f, _alto / 2.0f, _ancho / 2.0f, _alto / 2.0f);
	_techo.setColor(125, 255, 125);

	_suelo.setLimites(-_ancho / 2.0f, -_alto / 2.0f, _ancho / 2.0f, -_alto / 2.0f);
	_suelo.setColor(125, 255, 125);
}

Caja::~Caja()
{
}

void Caja::dibuja() {
	_pared_dcha.dibuja();
	_pared_izq.dibuja();
	_techo.dibuja();
	_suelo.dibuja();

	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-_ancho / 2.0f, -_alto / 2.0f);
	glTexCoord2d(1, 1); glVertex2f(_ancho / 2.0f, -_alto / 2.0f);
	glTexCoord2d(1, 0); glVertex2f(_ancho / 2.0f, _alto / 2.0f);
	glTexCoord2d(0, 0); glVertex2f(-_ancho / 2.0f, _alto / 2.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}