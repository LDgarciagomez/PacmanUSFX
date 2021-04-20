#include "GameObject.h"

GameObject::GameObject(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = 640;
	altoPantalla = 480;
}

void GameObject::render() {};