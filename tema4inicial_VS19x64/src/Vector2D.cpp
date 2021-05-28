#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(float nx, float ny) : x(nx), y(ny)
{
}

Vector2D::~Vector2D() {
}

float Vector2D::modulo() const{
	return (float)sqrtf(x * x + y * y);
}

float Vector2D::argumento() const{
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario() const
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D v) const
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector2D Vector2D::operator + (Vector2D v) const
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

Vector2D Vector2D::operator+=(Vector2D v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vector2D Vector2D::operator-=(Vector2D v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

float Vector2D::operator * (Vector2D v) const{
	return v.x * x + v.y * y;
}

Vector2D Vector2D::operator * (float escalar) const{
	Vector2D resultado;
	resultado.x = escalar * x;
	resultado.y = escalar * y;
	return resultado;
}
