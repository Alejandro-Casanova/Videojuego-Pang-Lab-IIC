#pragma once

#include "Vector2D.h"

class Disparo
{
public:
	Disparo();
	virtual ~Disparo();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy) { _posicion.x = _origen.x = ix; _posicion.y = _origen.y = iy; }
	void setOrigen(float ox, float oy) { _origen.x = ox; _origen.y = oy; }
	void setVel(float vx, float vy) { _velocidad.x = vx; _velocidad.y = vy; }
	float getRadio() { return _radio; }
	Vector2D getPos() { return _posicion; }

private:
	float _radio;
	Vector2D _origen;
	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

