#include "Esfera.h"
#include "freeglut.h"

Esfera::Esfera()
{
	_color.set(255, 255, 255);
	_radio = 1.0f;
	_aceleracion.y = -9.8f;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy) {
	_radio = rad; 
	_posicion.x = x; 
	_posicion.y = y; 
	_velocidad.x = vx; 
	_velocidad.y = vy; 
	_color.set(255, 255, 100);
	_aceleracion.y=-9.8; 
}

Esfera::~Esfera(){
}

void Esfera::dibuja() {
	//glColor3ub(_r, _g, _b);
	_color.ponColor();
	glTranslatef(_posicion.x, _posicion.y, 0);
	glutSolidSphere(_radio, 20, 20);
	glTranslatef(-_posicion.x, -_posicion.y, 0);
}

void Esfera::mueve(float t)
{
	_posicion = _posicion + _velocidad * t + _aceleracion * (0.5f * t * t);
	_velocidad = _velocidad + _aceleracion * t;
}

