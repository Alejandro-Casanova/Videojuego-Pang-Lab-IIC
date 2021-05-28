#pragma once

#include "Mundo.h" 

class CoordinadorPang { 
public:
	CoordinadorPang(); 
	virtual ~CoordinadorPang(); 
	void teclaEspecial(); 
	void tecla(); 
	void mueve(); 
	void dibuja(); 
protected: 
	enum class Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA }; 
	Estado estado = Estado::INICIO;
	Mundo mundo;
};