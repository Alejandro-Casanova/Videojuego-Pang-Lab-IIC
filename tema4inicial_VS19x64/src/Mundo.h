#pragma once

#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"
#include <vector>

class Mundo
{
public: 
	
	Mundo();
	~Mundo();

	void tecla();
	void teclaEspecial();
	bool cargarNivel();
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	bool getImpacto() const { return _impacto; }
	int getNumEsferas() const { return esferas.getNumero(); }
	int getNDisparos() const { return _nDisparos; }
	int getNDisparosEspeciales() const { return _nDisparosEspeciales; }

private:
	void deleteBonus();
	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;

	Hombre hombre;
	Caja caja;
	std::vector<Bonus*> bonus;
	Pared plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;

	bool _impacto = false;
	int _nivel = 1;
	
	int _nDisparos = 3;
	int _nMaxDisparos = 3;
	int _nDisparosEspeciales = 1;
};
