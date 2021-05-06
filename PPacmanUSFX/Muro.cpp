
#include "Muro.h"

Muro::Muro(int _posicionX, int _posicionY, int _tipo, vector<Texture*> _muroTexture) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _muroTexture, _tipo)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 25;
	alto = 25;
	anchoPantalla = 640;
	altoPantalla = 480;
	tipo = _tipo;
	muroTexture = _muroTexture;
}