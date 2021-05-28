#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"
#include "GestorDeTeclado.h"

void Mundo::deleteBonus() {
	for (auto& b : bonus) delete b;
	bonus.clear();
}

Mundo::Mundo(){
}

Mundo::~Mundo() {
	deleteBonus();
}

void Mundo::rotarOjo()
{
	float dist=sqrtf(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2f(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cosf(ang);
	z_ojo=dist*sinf(ang);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	hombre.dibuja();
	disparos.dibuja();
	plataforma.dibuja();
	for (auto& b : bonus) b->dibuja();
	caja.dibuja();

	esferas.dibuja();
	
}

void Mundo::mueve()
{
	
	for (int i = esferas.getNumero() - 1; i >= 0; i--) {
		for (int j = disparos.getNumero() - 1; j >= 0; j--) {
			if (Interaccion::colision(*disparos[j], *esferas[i])) {
				if (ETSIDI::lanzaDado(0.0, 1.0) > 0.75) {
					bonus.push_back(new Bonus(esferas[i]->getPos()));
				}
				Esfera* e = esferas[i]->dividir();
				disparos.eliminar(j);
				if (e == 0) {//no division 
					esferas.eliminar(esferas[i]);	
				}
				else esferas.agregar(e);
				ETSIDI::play("sonidos/impacto.wav"); break;
			}
		}
	}

	hombre.mueve(0.025f); 
	for (auto& b : bonus) b->mueve(0.025f);
	esferas.mueve(0.025f); 
	disparos.mueve(0.025f);

	esferas.rebote(); 
	esferas.rebote(plataforma); 
	esferas.rebote(caja); 
	disparos.colision(plataforma);
	disparos.colision(caja);

	for (int i = bonus.size() - 1; i >= 0; i--) {
		if (Interaccion::colision(hombre, *bonus[i])) {
			delete bonus[i];
			bonus.erase(bonus.begin() + i);
			_nDisparos++;
			_nMaxDisparos++;
			_nDisparosEspeciales++;
			
		}
		else if (Interaccion::colision(*bonus[i], caja)) {
			delete bonus[i];
			bonus.erase(bonus.begin() + i);
		}
	}

	Esfera* aux = esferas.colision(hombre); 
	if (aux != 0) {//si alguna esfera ha chocado 
		esferas.eliminar(aux);
		ETSIDI::play("sonidos/impacto.wav");
		_impacto = true;
	}
	Interaccion::rebote(hombre,caja);
}

void Mundo::inicializa()
{
	x_ojo=0.0f;
	y_ojo=0.0f;
	z_ojo=30.0f;

	_nDisparos = _nMaxDisparos = 3;
	_nDisparosEspeciales = 1;
	_nivel = 0; 
	_impacto = false;
	cargarNivel();

}

void Mundo::tecla()
{
	if(GestorDeTeclado::isKeyPressed(' ') && (_nDisparos > 0)){
		Disparo* d = new Disparo();
		Vector2D pos = hombre.getPos() + Vector2D(0.0f, hombre.getAltura());
		d->setPos(pos.x, pos.y);
		d->setVel(0.0f, 5.0f);
		d->setPtr(&_nDisparos);
		disparos.agregar(d);
		ETSIDI::play("sonidos/disparo.wav");
		_nDisparos--;
	}
	if(GestorDeTeclado::isKeyPressed('z') && (_nDisparosEspeciales > 0)){
		DisparoEspecial* D = new DisparoEspecial();
		Vector2D posD = hombre.getPos() + Vector2D(0.0f, hombre.getAltura());
		D->setPos(posD.x, posD.y);
		D->setVel(0.0f, 7.5f);
		D->setPtr(&_nDisparos);
		disparos.agregar(D);
		ETSIDI::play("sonidos/disparo.wav");
		_nDisparosEspeciales--;
	}
}

void Mundo::teclaEspecial()
{
	
}

bool Mundo::cargarNivel() {
	_nivel++; 
	hombre.setPos(0, -7.5f); 
	esferas.destruirContenido(); 
	disparos.destruirContenido();
	deleteBonus();
	if (_nivel == 1) {
		plataforma.setLimites(-5.0f, 1.0f, 5.0f, 1.0f); 
		plataforma.setColor(255, 255, 255);
		Esfera* e1 = new Esfera(1.5f, 2, 4, 5, 15); 
		e1->setColor(0, 0, 255); 
		esferas.agregar(e1); //esfera 
	} 
	if(_nivel==2) { 
		plataforma.setLimites(-7.0f, 1.0f, -2.0f, 1.0f);
		plataforma.setColor(255,0,0); 
		EsferaPulsante* e3 = new EsferaPulsante; 
		e3->setPos(0.0f, 6.0f);
		e3->setVel(5.0f, 3.0f);
		esferas.agregar(e3); 
	} 
	if(_nivel==3) { 
		plataforma.setLimites(-10.0f, 3.0f, 4.0f, 1.0f);
		plataforma.setColor(255, 0, 255);;
		for(int i = 0; i < 5; i++) { 
			Esfera* aux = new Esfera(1.5f, float(-5 + i), 6.0f, float(i), 5.0f);;
			aux->setColor(i * 40, 0, 255 - i * 40);;
			esferas.agregar(aux); 
		} 
	} 
	if(_nivel<=3) 
		return true; 
	return false; 
}
