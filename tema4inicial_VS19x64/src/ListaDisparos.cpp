#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = nullptr;
}

ListaDisparos::~ListaDisparos()
{
	destruirContenido();
}

bool ListaDisparos::agregar(Disparo* d)
{
	if (numero < MAX_DISPAROS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == d)
				return false; //Disparo ya incluido
		}
		lista[numero++] = d; // último puesto sin rellenar 
	}
	else
		return false; // capacidad máxima alcanzada 
	return true;
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de disparos contenidos
		delete lista[i];
	numero = 0; // inicializa lista 
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaDisparos::colision(Pared p)
{
	for (int i = 0; i < numero; i++) {
		if(Interaccion::colision(*(lista[i]), p))
			lista[i]->setVel(0.0f, 0.0f);
	}
}

void ListaDisparos::colision(Caja c)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), c)) {
			lista[i]->setVel(0.0f, 0.0f);
		}
	}
}
