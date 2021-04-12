#pragma once

#include "Vector2D.h"

class Esfera
{
public:
	Esfera();
	virtual ~Esfera();

	void dibuja();

	unsigned char r;
	unsigned char g;
	unsigned char b;
	float radio;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void mueve(float t);
};

