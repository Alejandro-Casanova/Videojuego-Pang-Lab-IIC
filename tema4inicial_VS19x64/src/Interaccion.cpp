#include "Interaccion.h"
#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include <math.h>

void Interaccion::rebote(Hombre& h, Caja c)
{
	float xmax = c._suelo._limite2.x;
	float xmin = c._suelo._limite1.x;
	if (h._posicion.x > xmax)h._posicion.x = xmax;
	if (h._posicion.x < xmin)h._posicion.x = xmin;
}

bool Interaccion::rebote(Esfera& e, Pared p)
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

void Interaccion::rebote(Esfera& e, Caja c)
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

	if (dist <= (a._radio + b._radio)) {
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
