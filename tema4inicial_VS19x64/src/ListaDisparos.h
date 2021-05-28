#define MAX_DISPAROS 20 
#include "Disparo.h" 
#include "Caja.h" 

class ListaDisparos { 
public: 
	ListaDisparos(); 
	virtual ~ListaDisparos(); 

	bool agregar(Disparo* d);
	void eliminar(int index);
	void eliminar(Disparo* d);

	void destruirContenido(); 
	void mueve(float t); 
	void dibuja() const; 
	void colision(Pared p); 
	void colision(Caja c);

	Disparo* operator [](int i);
	int getNumero() const { return _numero; }
private: 
	Disparo* _lista[MAX_DISPAROS]; 
	int _numero;
};