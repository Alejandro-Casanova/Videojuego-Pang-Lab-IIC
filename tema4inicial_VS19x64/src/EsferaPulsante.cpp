#include "EsferaPulsante.h"

EsferaPulsante::EsferaPulsante() : Esfera(1.0f, 0.0f, 0.0f)
{
	_aceleracion.x = 0;
	_aceleracion.y = 0;
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
