#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"

class Bonus : public ObjetoMovil
{
	friend class Interaccion;
public:
	Bonus();
	Bonus(Vector2D pos);
	virtual ~Bonus();

	void dibuja();

private:
	float _lado;	
};

