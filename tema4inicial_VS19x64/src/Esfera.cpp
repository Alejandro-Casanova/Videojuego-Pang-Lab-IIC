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
	_aceleracion.y=-9.8f; 
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

Esfera* Esfera::dividir() {
	if (_radio < 1.0f) 
		return 0;   //no dividimos 
	_radio /= 2.0f; //Dividimos el radio por 2 
	//Creamos una esfera nueva, copiando la actual 
	Esfera *aux = new Esfera(*this); //Les damos nuevas velocidades 
	aux->setVel(5.0f, 8.0f);//a la nueva mitad 
	setVel(-5.0f, 8.0f);//a la mitad original 
	return aux; 
}


