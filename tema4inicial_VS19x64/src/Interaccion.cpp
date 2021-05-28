#include "Interaccion.h"
#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Disparo.h"
#include "Bonus.h"
#include <math.h>

void Interaccion::rebote(Hombre& h, const Caja& c)
{
	float xmax = c._suelo._limite2.x;
	float xmin = c._suelo._limite1.x;
	if (h._posicion.x > xmax)h._posicion.x = xmax;
	if (h._posicion.x < xmin)h._posicion.x = xmin;
}

bool Interaccion::rebote(Esfera& e, const Pared& p)
{
	Vector2D dir;
	float dif = p.distancia(e._posicion, &dir) - e._radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e._velocidad;
		e._velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		e._posicion = e._posicion - dir * dif;
		return true;
	}
	return false;
}

void Interaccion::rebote(Esfera& e, const Caja& c)
{
	rebote(e, c._pared_dcha);
	rebote(e, c._pared_izq);
	rebote(e, c._suelo);
	rebote(e, c._techo);

}

bool Interaccion::rebote(Esfera& a, Esfera& b)
{
	//Ecuaciones físicas en https://www.plasmaphysics.org.uk/collision2d.htm
	float &Vx1 = a._velocidad.x, &Vx2 = b._velocidad.x, &Vy1 = a._velocidad.y, &Vy2 = b._velocidad.y;
	Vector2D distVec = b._posicion - a._posicion;
	float dist = distVec.modulo();
	float minDist = (a._radio + b._radio);

	if (dist <= minDist) {
		//Separa las esferas
		b._posicion += (distVec.unitario() * ( (minDist - dist) / 2) );
		a._posicion -= (distVec.unitario() * ( (minDist - dist) / 2) );

		//Masas proporcionales a las áreas
		float m1 = a._radio * a._radio, m2 = b._radio * b._radio;
		//Ángulo de Velocidad relativa
		float gammaV = atan2f((Vy1 - Vy2), (Vx1 - Vx2));
		//El ángulo de impacto alfa
		float alfa = asinf(dist * sinf(distVec.argumento() - gammaV) / (a._radio + b._radio));
		//Delta de la velocidad en x del cuerpo 2
		float A = tanf(gammaV + alfa);
		float deltaVx2 = 2 * (Vx1 - Vx2 + A * (Vy1 - Vy2)) / ((1 + A * A) * (1 + m2 / m1));
		
		//Nuevas velocidades
		Vx2 = Vx2 + deltaVx2;
		Vy2 = Vy2 + A * deltaVx2;
		Vx1 = Vx1 - m2 / m1 * deltaVx2;
		Vy1 = Vy1 - A * m2 / m1 * deltaVx2;

		return true;
	}

	return false;
}

bool Interaccion::colision(const Esfera& e, const Hombre& h) {
	Vector2D pos = h.getPos(); //la posicion de la base del hombre 
	pos.y+=h.getAltura()/2.0f; //posicion del centro 
	float distancia=(e.getPos()-pos).modulo(); 
	if(distancia<e._radio) 
		return true; 
	return false; 
}

bool Interaccion::colision(const Disparo& d, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(d.getPos(), &dir) - d.getRadio();
	if (dif <= 0.0f)
	{
		return true;
	}
	return false;
}

bool Interaccion::colision(const Disparo& d, Caja c)
{
	return  (colision(d, c._pared_dcha) || colision(d, c._pared_izq) || colision(d, c._suelo) || colision(d, c._techo));
}

bool Interaccion::colision(const Disparo& d, const Esfera& e) {
	Pared aux; //Creamos una pared auxiliar 
	Vector2D p1=d._posicion; 
	Vector2D p2=d._origen; 
	aux.setLimites(p1.x,p1.y,p2.x,p2.y); //Que coincida con el disparo. 
	float dist=aux.distancia(e._posicion); //para calcular su distancia 
	if(dist<e._radio) 
		return true; 
	return false; 
}

bool Interaccion::colision(const Hombre& h, const Bonus& b)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre 
	pos.y += h.getAltura() / 2.0f; //posicion del centro 
	float distancia = (b.getPos() - pos).modulo();
	if (distancia < b._lado)
		return true;
	return false;
}

bool Interaccion::colision(const Bonus& b, const Caja& c)
{
	if (b.getPos().y < -c.getAlto() / 2.0f) return true;
	return false;
}
