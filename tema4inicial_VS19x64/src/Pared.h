#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{
public:
	Pared();
	virtual ~Pared();

	void dibuja();

	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setLimites(float limite1x, float limite1y, float limite2x, float limite2y);

private:
	ColorRGB _color;
	Vector2D _limite1;
	Vector2D _limite2;
};

