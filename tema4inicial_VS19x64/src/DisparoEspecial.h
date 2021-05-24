#pragma once

#include "Disparo.h"

class DisparoEspecial : public Disparo{
public:
	DisparoEspecial() { _radio *= 2; _color.set(255, 0, 0); };
	void dibuja() const {
		Disparo::dibujaDisparo();
		Disparo::dibujaEstela(-0.1f);
		Disparo::dibujaEstela(0.1f);
	}
private:

};
