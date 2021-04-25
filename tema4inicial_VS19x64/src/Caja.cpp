#include "Caja.h"

Caja::Caja()
{
	pared_izq.setLimites(-10.0f, -7.5f, -10.0f, 7.5f);
	pared_izq.setColor(0, 255, 0);

	pared_dcha.setLimites(10.0f, 7.5f, 10.0f, -7.5f);
	pared_dcha.setColor(0, 255, 0);

	techo.setLimites(-10.0f, 7.5f, 10.0f, 7.5f);
	techo.setColor(125, 255, 125);

	suelo.setLimites(10.0f, -7.5f, -10.0f, -7.5f);
	suelo.setColor(125, 255, 125);
}

Caja::~Caja()
{
}

void Caja::dibuja() {
	pared_dcha.dibuja();
	pared_izq.dibuja();
	techo.dibuja();
	suelo.dibuja();
}