#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ColorRGB.h"

class Disparo : public ObjetoMovil
{
public:
	Disparo();
	virtual ~Disparo();

	void dibuja() const;
	void setPos(float ix, float iy) { _posicion.x = _origen.x = ix; _posicion.y = _origen.y = iy; }
	//void setOrigen(float ox, float oy) { _origen.x = ox; _origen.y = oy; }
	float getRadio() const { return _radio; }

protected:
	void dibujaDisparo() const;
	void dibujaEstela(float offset) const;
	float _radio = 0.25f;
	ColorRGB _color;
	Vector2D _origen;
};

