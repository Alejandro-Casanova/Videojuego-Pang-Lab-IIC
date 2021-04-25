#pragma once

#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"

class Mundo
{
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;

	Disparo disparo;
	Esfera esfera;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
};
