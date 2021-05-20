#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Hombre
{
	friend class Interaccion;
	
public:
	Hombre();
	virtual ~Hombre();

	void dibuja();
	void mueve(float t);

	void setVel(float vx, float vy);
	float getAltura() const { return _altura; }
	Vector2D getPos() const { return _posicion; }

private:
	float _altura;
	Vector2D _posicion;
	Vector2D _velocidad;
	Vector2D _aceleracion;

	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	
};

