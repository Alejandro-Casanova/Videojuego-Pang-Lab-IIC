#pragma once

#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"

class Mundo
{
public: 
	Mundo();
	~Mundo();

	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;

	Disparo disparo;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
private:
	ListaEsferas esferas;
	ListaDisparos disparos;
};
