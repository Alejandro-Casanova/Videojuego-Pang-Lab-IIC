#pragma once

class Hombre;
class Caja;
class Esfera;
class Pared;

class Interaccion{
public:
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static bool rebote(Esfera& a, Esfera& b);
};

