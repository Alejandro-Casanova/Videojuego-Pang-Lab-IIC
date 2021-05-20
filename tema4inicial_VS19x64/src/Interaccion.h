#pragma once

class Hombre;
class Caja;
class Esfera;
class Pared;
class Disparo;

class Interaccion{
public:
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static bool rebote(Esfera& a, Esfera& b);
	static bool colision(Esfera e, Hombre h);

	static bool colision(Disparo d, Pared p); 
	static bool colision(Disparo d, Caja c);
};

