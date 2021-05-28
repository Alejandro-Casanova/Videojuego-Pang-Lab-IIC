#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	_numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		_lista[i] = nullptr;
}

ListaDisparos::~ListaDisparos()
{
	destruirContenido();
}

bool ListaDisparos::agregar(Disparo* d)
{
	if (_numero < MAX_DISPAROS) {
		for (int i = 0; i < _numero; i++) {
			if (_lista[i] == d)
				return false; //Disparo ya incluido
		}
		_lista[_numero++] = d; // último puesto sin rellenar 
	}
	else
		return false; // capacidad máxima alcanzada 
	return true;
}

void ListaDisparos::eliminar(int index) {
	if ((index < 0) || (index >= _numero))
		return;
	delete _lista[index];
	_numero--;
	for (int i = index; i < _numero; i++)
		_lista[i] = _lista[i + 1];
}

void ListaDisparos::eliminar(Disparo* d) {
	for (int i = 0; i < _numero; i++)
		if (_lista[i] == d) {
			eliminar(i); 
			return;
		}
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < _numero; i++) // destrucción de disparos contenidos
		delete _lista[i];
	_numero = 0; // inicializa lista 
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < _numero; i++)
		_lista[i]->mueve(t);
}

void ListaDisparos::dibuja() const
{
	for (int i = 0; i < _numero; i++)
		_lista[i]->dibuja();
}

void ListaDisparos::colision(Pared p)
{
	for (int i = 0; i < _numero; i++) {
		if(Interaccion::colision(*(_lista[i]), p))
			_lista[i]->setVel(0.0f, 0.0f);
	}
}

void ListaDisparos::colision(Caja c)
{
	for (int i = 0; i < _numero; i++) {
		if (Interaccion::colision(*(_lista[i]), c)) {
			_lista[i]->setVel(0.0f, 0.0f);
		}
	}
}

Disparo* ListaDisparos::operator[](int i)
{
	if (i >= _numero)//si me paso, devuelvo la ultima 
		i = _numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera 
		i = 0;
	return _lista[i];
}
