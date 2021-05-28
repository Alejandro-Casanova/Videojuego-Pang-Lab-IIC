#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"

class Esfera : public ObjetoMovil
{
	friend class Interaccion;
public:
	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Esfera();

	void dibuja();
	virtual Esfera* dividir();

	void setColor(unsigned char r, unsigned char g, unsigned char b) { _color.set(r, g, b); }
	void setRadio(float radio) { _radio = radio; }
	

protected:
	ColorRGB _color;
	float _radio;
};

