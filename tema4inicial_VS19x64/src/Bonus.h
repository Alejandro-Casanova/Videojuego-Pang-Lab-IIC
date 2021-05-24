#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"

class Bonus : public ObjetoMovil
{
public:
	Bonus();
	virtual ~Bonus();

	void dibuja();

private:
	float _lado;	
};

