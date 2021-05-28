#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"
using ETSIDI::SpriteSequence;

class Hombre : public ObjetoMovil
{
	friend class Interaccion;
	
public:
	Hombre();
	virtual ~Hombre();

	void dibuja();
	void mueve(float t) override;

	float getAltura() const { return _altura; }

private:
	float _altura;

	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	
};

