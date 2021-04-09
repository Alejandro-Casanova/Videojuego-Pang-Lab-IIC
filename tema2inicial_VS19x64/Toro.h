#pragma once

class Toro {
private:
	float r1;
	float r2;
	float x;
	float y;
	float z;
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	void setPos(float ix, float iy, float iz);
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void setRadio(float ir1, float ir2);

	void mueve();
	void dibuja();

};

