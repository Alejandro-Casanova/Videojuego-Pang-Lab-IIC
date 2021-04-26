#include "Caja.h"

Caja::Caja()
{
	_pared_izq.setLimites(-10.0f, -7.5f, -10.0f, 7.5f);
	_pared_izq.setColor(0, 255, 0);

	_pared_dcha.setLimites(10.0f, -7.5f, 10.0f, 7.5f);
	_pared_dcha.setColor(0, 255, 0);

	_techo.setLimites(-10.0f, 7.5f, 10.0f, 7.5f);
	_techo.setColor(125, 255, 125);

	_suelo.setLimites(-10.0f, -7.5f, 10.0f, -7.5f);
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
}