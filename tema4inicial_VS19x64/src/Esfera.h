#pragma once

#include "Vector2D.h"

class Esfera
{
public:
	Esfera();
	virtual ~Esfera();

	void dibuja();
	void mueve(float t);

	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setRadio(float radio);
	void setPos(float x, float y);

private:
	unsigned char _r;
	unsigned char _g;
	unsigned char _b;
	float _radio;

	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

