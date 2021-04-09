#pragma once

class Esfera {
private:
	float radio;
	float x;
	float y;
	float z;
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void setRadio(float r);
	void setPos(float ix, float iy, float iz);
	void setradio(float nRadio) { radio = nRadio; }
	float getRadio(){ return radio; }
	

	void dibuja();
	void mueve();
	void botar();
};