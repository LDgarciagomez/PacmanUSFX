#include "Fruta.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Fruta::Fruta(int _posicionX, int _posicionY, int _tipo, vector<Texture*> _frutaTexture) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _frutaTexture, _tipo)
{
	ancho = 20;
	alto = 20;
	visible = false;
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	tipo = _tipo;
	frutaTexture = _frutaTexture;
}

void Fruta::show()
{

	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % (anchoPantalla - 1);
			posicionY = 1 + rand() % (altoPantalla - 1);
			tipo = rand() % frutaTexture.size();
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;

		}
		else {
			contadorTiempoNoVisible++;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}
//void Fruta::render()
//{
//	if (visible) {
//		SDL_Rect clip = { 0, 0, ancho, alto };
//		frutaTexture[tipo]->render(posicionX, posicionY, &clip);
//
//	}
