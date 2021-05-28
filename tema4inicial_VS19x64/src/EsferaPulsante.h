#pragma once

#include "Esfera.h"

class EsferaPulsante : public Esfera
{
public:
	EsferaPulsante();
	void mueve(float t);

	virtual EsferaPulsante* dividir() override;

private:
	float _pulso = 0.5f;
	float _radio_max = 2.0f;
	float _radio_min = 0.5f;
};

