#include "EsferaPulsante.h"

EsferaPulsante::EsferaPulsante() : Esfera(1.0f, 0.0f, 0.0f)
{
	_aceleracion.x = 0.0f;
	_aceleracion.y = -9.8f;
}

void EsferaPulsante::mueve(float t)
{
	Esfera::mueve(t);
	if (_radio > _radio_max) 
		_pulso = -_pulso; 
	if (_radio < _radio_min) 
		_pulso = -_pulso; 
	_radio += _pulso * t; 
	_color.r = Byte(_radio * 255); 
	_color.g = Byte(255 - _radio * 100); 
	_color.b = Byte(100 + _radio * 50);
}

EsferaPulsante* EsferaPulsante::dividir() {
	if (_radio < 1.0f)
		return 0;   //no dividimos 
	//Creamos una esfera nueva, copiando la actual 
	EsferaPulsante* aux = new EsferaPulsante(*this); //Les damos nuevas velocidades 
	aux->setVel(5.0f, 8.0f);//a la nueva mitad 
	aux->_pulso *= 2.0f;
	setVel(-5.0f, 8.0f);//a la mitad original 
	return aux;
}