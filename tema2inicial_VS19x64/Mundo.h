#pragma once
#include "Esfera.h"
#include "Plano.h"
#include "Toro.h"

class Mundo {
private:
	float x;
	float y;
	float z;

	Esfera esfera, esfera2, esfera3;
	Plano plano, plano2;
	Toro toro;

public:
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }

	void rotarOjo(float thetaTurn);
	void zoom(float zoomFactor);
	void inicializa();
	void dibuja();
	void mueve();
	void tecla(unsigned char key);
};