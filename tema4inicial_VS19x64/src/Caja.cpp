#include "Caja.h"

Caja::Caja()
{
	pared_izq.limite1.x = -10.0f;
	pared_izq.limite1.y = -7.5f;
	pared_izq.limite2.x = -10.f;
	pared_izq.limite2.y = 7.5f;
	pared_izq.r = 0;
	pared_izq.g = 255;
	pared_izq.b = 0;

	pared_dcha.limite1.x = 10.0f;
	pared_dcha.limite1.y = 7.5f;
	pared_dcha.limite2.x = 10.f;
	pared_dcha.limite2.y = -7.5f;
	pared_dcha.r = 0;
	pared_dcha.g = 255;
	pared_dcha.b = 0;

	techo.limite1.x = -10.0f;
	techo.limite1.y = 7.5f;
	techo.limite2.x = 10.f;
	techo.limite2.y = 7.5f;
	techo.r = 125;
	techo.g = 255;
	techo.b = 125;

	suelo.limite1.x = 10.0f;
	suelo.limite1.y = -7.5f;
	suelo.limite2.x = -10.f;
	suelo.limite2.y = -7.5f;
	suelo.r = 125;
	suelo.g = 255;
	suelo.b = 125;
	

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