#pragma once

#include "Vector2D.h"

class Disparo
{
public:
	Disparo();
	virtual ~Disparo();

	void dibuja();

	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void mueve(float t);
};

