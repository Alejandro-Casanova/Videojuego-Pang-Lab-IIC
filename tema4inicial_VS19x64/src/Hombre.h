#pragma once

#include "Vector2D.h"
class Hombre
{
public:
	Hombre();
	virtual ~Hombre();

	void dibuja();

	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void mueve(float t);
};

