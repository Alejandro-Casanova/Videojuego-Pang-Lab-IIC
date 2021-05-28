#pragma once
class Vector2D{
public:
	Vector2D(float nx = 0.0f, float ny = 0.0f);
	virtual ~Vector2D();
	float modulo() const; // (2) modulo del vector
	float argumento() const; // (3) argumento del vector
	Vector2D unitario() const; // (4) devuelve un vector unitario
	Vector2D operator - (Vector2D) const; // (5) resta de vectores
	Vector2D operator + (Vector2D) const; // (6) suma de vectores
	Vector2D operator += (Vector2D);
	Vector2D operator -= (Vector2D v);
	float operator *(Vector2D) const; // (7) producto escalar
	Vector2D operator *(float) const; // (8) producto por un escalar
//ATRIBUTOS
	float x = 0;
	float y = 0;
};

