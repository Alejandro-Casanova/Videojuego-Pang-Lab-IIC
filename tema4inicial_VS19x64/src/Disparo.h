#pragma once

#include "Vector2D.h"

class Disparo
{
public:
	Disparo();
	virtual ~Disparo();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy) { _posicion.x = _origen.x = ix; _posicion.y = _origen.y = iy; }

private:
	float _radio;
	Vector2D _origen;
	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

