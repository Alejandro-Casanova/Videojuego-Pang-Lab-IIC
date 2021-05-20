#pragma once

#define MAX_ESFERAS 100

#include "Esfera.h"
#include "Caja.h"

class Hombre;

class ListaEsferas
{
public: 
	ListaEsferas(); 
	~ListaEsferas();

	void destruirContenido();
	bool agregar(Esfera* e);
	void eliminar(int index);
	void eliminar(Esfera* e);

	void dibuja() const;
	void mueve(float t);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(); //Entre esferas
	Esfera* colision(Hombre& h);

	Esfera* operator [](int i);

	int getNumero() { return numero; }

private: 
	Esfera* lista[MAX_ESFERAS]; 
	int numero;
};

