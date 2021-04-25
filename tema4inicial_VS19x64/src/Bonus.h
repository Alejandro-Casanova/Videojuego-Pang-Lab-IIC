#pragma once

#include "Vector2D.h"

class Bonus
{
public:
	Bonus();
	virtual ~Bonus();

	void dibuja();
	void mueve(float t);

private:
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	
};

