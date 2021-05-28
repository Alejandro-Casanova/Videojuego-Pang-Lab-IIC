#pragma once

#include "Vector2D.h"

class ObjetoMovil
{
public:
	virtual void mueve(float t){
		_posicion = _posicion + _velocidad * t + _aceleracion * (0.5f * t * t);
		_velocidad = _velocidad + _aceleracion * t;
	}
	void setPos(float x, float y) { _posicion.x = x; _posicion.y = y; }
	void setVel(float vx, float vy) { _velocidad.x = vx; _velocidad.y = vy; }
	Vector2D getPos() const { return _posicion; }
protected:
	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
};

