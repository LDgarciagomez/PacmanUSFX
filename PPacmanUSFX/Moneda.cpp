#include "Moneda.h"

using namespace std;

Moneda::Moneda(int _posicionX, int _posicionY, int _tipo, int _valor) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla)
{

	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 10;
	alto = 10;
	anchoPantalla = 640;
	altoPantalla = 480;
	tipo = _tipo;
}

Moneda::Moneda(int _posicionX, int _posicionY, int _tipo, int _valor, Texture* _monedaTexture) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 10;
	alto = 10;
	anchoPantalla = 640;
	altoPantalla = 480;
	tipo = _tipo;
	valor = _valor;
	monedaTexture = _monedaTexture;
}


void Moneda::render()
{
	SDL_Rect clip = { 0, 0, ancho, alto };
	monedaTexture->render(posicionX, posicionY, &clip);
}