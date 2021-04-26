#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{
	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();

	void dibuja();
	float distancia(Vector2D punto, Vector2D* direccion = 0);

	void setColor(unsigned char r, unsigned char g, unsigned char b) { _color.set(r, g, b); }
	void setLimites(float limite1x, float limite1y, float limite2x, float limite2y) {
		_limite1.x = limite1x; _limite1.y = limite1y;
		_limite2.x = limite2x; _limite2.y = limite2y;
	}

private:
	ColorRGB _color;
	Vector2D _limite1;
	Vector2D _limite2;
};

