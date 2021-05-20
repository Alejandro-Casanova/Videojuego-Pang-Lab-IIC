#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"

class Esfera
{
	friend class Interaccion;
public:
	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Esfera();

	void dibuja();
	void mueve(float t);

	void setColor(unsigned char r, unsigned char g, unsigned char b) { _color.set(r, g, b); }
	void setRadio(float radio) { _radio = radio; }
	void setPos(float x, float y) { _posicion.x = x; _posicion.y = y; }
	void setVel(float vx, float vy) { _velocidad.x = vx; _velocidad.y = vy; }
	Vector2D getPos() const { return _posicion; }

private:
	ColorRGB _color;
	float _radio;

	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;
	
};

