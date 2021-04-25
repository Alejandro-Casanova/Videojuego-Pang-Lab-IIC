#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"

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
	ColorRGB _color;
	float _radio;

	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

