#include "Pacman.h"

Pacman::Pacman(int _posicionX, int _posicionY, int _velocidadPatron, vector<Texture*> _pacmanTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _pacmanTexture, 0, _isClip, _frameX, _frameY, _anchoClip, _altoClip)
{
	// Inicializa propiedade de de pacman
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	pacmanTexture = _pacmanTexture;
	framesMovimiento = 2;
}


void Pacman::handleEvent(SDL_Event& e)
{
	// Si se ha precionado una tecla
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		// Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY -= velocidadPatron; frameY = 2; break;
		case SDLK_DOWN: velocidadY += velocidadPatron; frameY = 3;  break;
		case SDLK_LEFT: velocidadX -= velocidadPatron; frameY = 1;  break;
		case SDLK_RIGHT: velocidadX += velocidadPatron; frameY = 0; break;
		}
	}
	// Si se ha soltado una tecla
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		// Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY += velocidadPatron; break;
		case SDLK_DOWN: velocidadY -= velocidadPatron; break;
		case SDLK_LEFT: velocidadX += velocidadPatron; break;
		case SDLK_RIGHT: velocidadX -= velocidadPatron; break;
		}
	}
	//move();
}

void Pacman::move()
{
	// Mueve pacman a la izquierda o a la derecha
	posicionX += velocidadX;

	//Se verifica que no se sobrepasen los bordes horizontales de los margenes establecidos para la pantalla
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	{
		// mover atrás
		posicionX -= velocidadX;
	}

	// Mover pacman arriba o abajo
	posicionY += velocidadY;

	// Se verifica que no se sobrepasen los bordes verticales de los margenes establecidos para la pantalla
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		// mover atra
		posicionY -= velocidadY;
	}
}
//void Pacman::Renderizar()
//{
//	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
//	if (isClip)
//	{
//		SDL_Rect clip = { 0 + frameX * ancho, 0 + frameY * alto , ancho, alto };
//		pacmanTexture[0]->render(&renderQuad, &clip);
//	}
//	else
//	{
//		SDL_Rect* clip = NULL;
//		pacmanTexture[0]->render(&renderQuad, clip);
//	}

void Pacman::update() {
	contadorFrames++;
	if (contadorFrames >= 10)
	{
		frameX++;
		if (frameX == framesMovimiento)
		{
			frameX -= framesMovimiento;
		}
		contadorFrames = 0;
	}
}


