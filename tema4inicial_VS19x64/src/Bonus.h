#pragma once

#include "Vector2D.h"

class Bonus
{
public:
	Bonus();
	virtual ~Bonus();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy) { _posicion.x = ix; _posicion.y = iy; }

private:
	float _lado;
	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

