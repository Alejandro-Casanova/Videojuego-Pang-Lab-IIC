#pragma once

class Plano {
private:
	float x;
	float y;
	float z;
	float lado;
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	void setPos(float ix, float iy, float iz);
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void setLado(float ilado) { lado = ilado; }
	void dibuja();

private:
};