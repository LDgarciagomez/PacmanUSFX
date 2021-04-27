#include "GameObject.h"

GameObject::GameObject(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, vector<Texture*> _texturas, int _tipo, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = 640;
	altoPantalla = 480;
	isClip = _isClip;
	frameX = _frameX;
	frameY = _frameY;
	anchoClip = _anchoClip;
	altoClip = _altoClip;
	tipo = _tipo;
	texture = _texturas;
}

void GameObject::renderObjects()
{
	//Se comprueba si el objeto es visible
	if (visible)
	{
		//Se establece el tamaño y posición de la imagen
		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		//Se revisa si habrá un recorte en la imagen
		if (isClip)
		{
			//Se establece la posición y dimención del recorte y se renderiza
			SDL_Rect clip = { 0 + frameX * anchoClip, 0 + frameY * altoClip, anchoClip, altoClip };
			texture[tipo]->render(&renderQuad, &clip);
		}
		else
		{
			//Si no hay recorte, sólo se renderiza
			texture[tipo]->render(&renderQuad);
		}
	}
};

//void GameObject::Renderizar() {};

void GameObject::handleEvent(SDL_Event& e) {};

void GameObject::move() {};

void GameObject::update() {};

void GameObject::show() {};
//void GameObject::render() {};