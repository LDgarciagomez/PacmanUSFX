#include "Moneda.h"

using namespace std;

Moneda::Moneda(int _posicionX, int _posicionY, int _tipo, int _valor, vector<Texture*> _monedaTexture) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _monedaTexture, _tipo)
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