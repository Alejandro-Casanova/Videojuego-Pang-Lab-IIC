#pragma once

#include "Pared.h"

class Caja{
	friend class Interaccion;
public:
	Caja();
	virtual ~Caja();

	void dibuja();

private:
	Pared _suelo;
	Pared _techo;
	Pared _pared_izq;
	Pared _pared_dcha;
};