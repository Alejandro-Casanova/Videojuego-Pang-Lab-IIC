#pragma once

#include "Pared.h"

class Caja{
	friend class Interaccion;
public:
	Caja();
	virtual ~Caja();

	void dibuja();
	float getAncho() const { return _ancho; }
	float getAlto() const { return _alto; }

private:
	Pared _suelo;
	Pared _techo;
	Pared _pared_izq;
	Pared _pared_dcha;

	float _ancho = 20.0f;
	float _alto = 15.0f;
};