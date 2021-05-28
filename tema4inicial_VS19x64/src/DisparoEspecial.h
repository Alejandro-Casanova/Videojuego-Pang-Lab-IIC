#pragma once

#include "Disparo.h"

class DisparoEspecial : public Disparo{
public:
	DisparoEspecial() { _radio *= 2; setColor(255, 0, 0); setVel(0.0f, 25.0f); };
	virtual ~DisparoEspecial() override { (*_nDisparosPtr)--; }//No recupera los disparos que impactan
	virtual void dibuja() const override{
		Disparo::dibujaDisparo();
		Disparo::dibujaEstela(-0.1f);
		Disparo::dibujaEstela(0.1f);
	}
private:

};
