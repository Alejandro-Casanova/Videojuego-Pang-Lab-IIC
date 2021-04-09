#include "freeglut.h"
#include "Esfera.h"
#include <iostream>

#define GRAVITY_G 9.81f

void Esfera::setColor(unsigned char rojo, unsigned char verde, unsigned char azul) {
	r = rojo;
	g = verde;
	b = azul;
}

void Esfera::setRadio(float r){
	if (r < 0.1f)r = 0.1f;
	radio = r;
}

void Esfera::setPos(float ix, float iy, float iz){
	x = ix;
	y = iy;
	z = iz;
}

void Esfera::dibuja() {
	glColor3ub(r, g, b);
	glTranslatef(x, 0.0f, 0.0f);
	glTranslatef(0.0f, y, 0.0f);
	glTranslatef(0.0f, 0.0f, z);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-x, 0.0f, 0.0f);
	glTranslatef(0.0f, -y, 0.0f);
	glTranslatef(0.0f, 0.0f, -z);
}

void Esfera::mueve() {
	radio += 0.1f;
	r -= 10;
	g -= 10;
	if (radio > 3) {
		radio = 0.5f;
		r = 255;
		g = 255;
	}
}

//Animación de caída libre vertical
void Esfera::botar() {
	static float v0 = 0, t = 0, z0 = 10.0f, vmax = 1;
	float v;
	static bool flag_falling = true;

	//Caída
	if (flag_falling) {
		v = v0 - GRAVITY_G * t;
		if (v < vmax) {
			vmax = v;
			std::cout << vmax;
		}
		z = (z0 + v0 * t - 0.5f * GRAVITY_G * t * t);
		t += 0.025f;
		if (z <= 0) {
			v0 = -v;
			t = 0;
			z0 = 0;
			flag_falling = !flag_falling;
		}
	}
	//Rebote
	else {
		v = v0 - GRAVITY_G * t;
		z = z0 + (v0 * t - 0.5f * GRAVITY_G * t * t);
		t += 0.025f;
		if (v <= 0) {
			v0 = 0;
			v = 0;
			t = 0;
			z0 = z;
			flag_falling = !flag_falling;
		}
	}

	//Las bolas se vuelven de color rojo al alcanzar su energía cinética máxima
	g = 255 - (unsigned char)(255.0f * abs((v * v) / (vmax * vmax)));
	b = 255 - (unsigned char)(255.0f * abs((v * v) / (vmax * vmax)));

}