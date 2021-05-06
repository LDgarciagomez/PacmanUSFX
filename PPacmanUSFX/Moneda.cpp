#include "Moneda.h"

using namespace std;

Moneda::Moneda(int _posicionX, int _posicionY, int _tipo, int _valor, vector<Texture*> _monedaTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _monedaTexture, _tipo, _isClip, _frameX, _frameY, _anchoClip, _altoClip)
{
	monedaTexture = _monedaTexture;
	tipo = _tipo;
	valor = _valor;
	if (tipo == 0)
	{
		alto = 10;
		ancho = 10;
		framesMovimiento = 7;
	}
	else
	{
		alto = 25;
		ancho = 25;
		framesMovimiento = 6;
	}
}

void Moneda::update() {
	contadorFrames++;
	if (contadorFrames >= 5)
	{
		frameX++;
		if (frameX == framesMovimiento)
		{
			frameX -= framesMovimiento;
		}
		contadorFrames = 0;
	}
}

//void Moneda::Renderizar()
//{
//	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
//	if (isClip)
//	{
//		SDL_Rect clip = { 0 + frameX * ancho, 0 + frameY * alto , ancho, alto };
//		monedaTexture[tipo]->render(&renderQuad, &clip);
//	}
//	else
//	{
//		SDL_Rect* clip = NULL;
//		monedaTexture[tipo]->render(&renderQuad, clip);
//	}
//}