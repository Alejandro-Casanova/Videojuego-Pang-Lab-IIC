#include "Mundo.h"
#include <math.h>



void Mundo::rotarOjo(float thetaTurn) {
	//izq, X negativo 
	//der, X positivo

	//Giro mundo
	float d = sqrtf(x * x + y * y);
	float theta = atan2f(y, x);
	theta += thetaTurn;
	x = d * cosf(theta);
	y = d * sinf(theta);
}

void Mundo::zoom(float zoomFactor) {
	
	float d = sqrtf(x * x + y * y);
	float theta = atan2f(y, x);
	d -= zoomFactor; //Acerco Mundo si zoomFactor > 0
	x = d * cosf(theta);
	y = d * sinf(theta);
}

void Mundo::inicializa() {
	x = 15.0f;
	y = 15.0f;
	z = 10.0f;

	esfera.setPos(5.0f, 0.0f, 0.0f);
	esfera.setRadio(1.0f);
	esfera.setColor(255, 255, 255);

	esfera2.setPos(0.0f, 0.0f, 0.0f);
	esfera2.setRadio(1.0f);
	esfera2.setColor(255, 255, 255);

	esfera3.setPos(-5.0f, 0.0f, 0.0f);
	esfera3.setRadio(1.0f);
	esfera3.setColor(255, 255, 255);

	plano.setPos(5.0f, 0.0f, -1.0f);
	plano.setLado(2.0f);
	plano.setColor(255, 255, 255);
	
	plano2.setPos(-5.0f, 0.0f, -1.0f);
	plano2.setLado(2.0f);
	plano2.setColor(255, 255, 255);

	toro.setPos(0.0f, 0.0f, 0.0f);
	toro.setRadio(0.2f, 3.0f);
	toro.setColor(255, 255, 255);
}

void Mundo::dibuja() {
	esfera.dibuja();
	esfera2.dibuja();
	esfera3.dibuja();
	toro.dibuja();
	plano.dibuja();
	plano2.dibuja();
}

void Mundo::mueve() {
	esfera2.mueve();
	toro.mueve();
	esfera.botar();
	esfera3.botar();
}

void Mundo::tecla(unsigned char key) {

	if (key == '+' && (esfera.getRadio() < 3))
		esfera.setRadio(esfera.getRadio() + 0.5f);
	if (key == '-' && (esfera.getRadio() > 1))
		esfera.setRadio(esfera.getRadio() - 0.5f);

	if (key == 'r') esfera.setColor(255, 0, 0);
	if (key == 'g') esfera.setColor(0, 255, 0);
	if (key == 'b') esfera.setColor(0, 0, 255);

	if (key == 'a') rotarOjo(0.1f);
	if (key == 'd') rotarOjo(-0.1f);

	if (key == 'w') zoom(0.5f);
	if (key == 's') zoom(-0.5f);
}