#pragma once

#include "Vector2D.h"

class Disparo
{
public:
	Disparo();
	virtual ~Disparo();

	void dibuja();
	void mueve(float t);

private:
	float radio;
	Vector2D origen;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	
};

