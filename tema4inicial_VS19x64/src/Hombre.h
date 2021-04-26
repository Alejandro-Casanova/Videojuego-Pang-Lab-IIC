#pragma once

#include "Vector2D.h"
class Hombre
{
	friend class Interaccion;
public:
	Hombre();
	virtual ~Hombre();

	void dibuja();
	void mueve(float t);

	void setVel(float vx, float vy);

private:
	float _altura;
	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

