#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ColorRGB.h"

class Disparo : public ObjetoMovil
{
	friend class Interaccion;
public:
	Disparo();
	virtual ~Disparo();

	virtual void dibuja() const;
	void setPos(float ix, float iy) { _posicion.x = _origen.x = ix; _posicion.y = _origen.y = iy; }
	void setColor(Byte r, Byte g, Byte b) { _color.set(r, g, b); }
	float getRadio() const { return _radio; }
	void setPtr(int* ptr) { _nDisparosPtr = ptr; }

protected:
	void dibujaDisparo() const;
	void dibujaEstela(float offset) const;
	float _radio = 0.25f;
	ColorRGB _color;
	Vector2D _origen;
	int* _nDisparosPtr = nullptr; //Puntero al contador de disparos disponibles de la clase mundo
};

