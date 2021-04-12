#pragma once

#include "Vector2D.h"

class Bonus
{
public:
	Bonus();
	virtual ~Bonus();

	void dibuja();

	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void mueve(float t);
};

