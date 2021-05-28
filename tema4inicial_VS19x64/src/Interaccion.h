#pragma once

class Hombre;
class Caja;
class Esfera;
class Pared;
class Disparo;
class Bonus;

class Interaccion{
public:
	static void rebote(Hombre& h, const Caja& c);
	static bool rebote(Esfera& e, const Pared& p);
	static void rebote(Esfera& e, const Caja& c);
	static bool rebote(Esfera& a, Esfera& b);

	static bool colision(const Esfera& e, const Hombre& h);
	static bool colision(const Disparo& d, const Pared p);
	static bool colision(const Disparo& d, const Caja c);
	static bool colision(const Disparo& d, const Esfera& e);
	static bool colision(const Hombre& h, const Bonus& b);
	static bool colision(const Bonus& b, const Caja& c);
};

