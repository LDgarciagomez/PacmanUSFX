#include "Fantasma.h"

using namespace std;

Fantasma::Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 1;
	velocidadY = 1;
	
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	
	//posicionXi = 0;
	//posicionYi = 0;

	posicionXf = posicionX + _posicionXf;
	posicionYf = posicionY + _posicionYf;
}

Fantasma::Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture)
{
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 1;
	velocidadY = 1;
	
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	fantasmaTexture = _fantasmaTexture;
	
	//posicionXi = 0;
	//posicionYi = 0;

	posicionXf = posicionX + _posicionXf;
	posicionYf = posicionY + _posicionYf;
}


void Fantasma::move()
{
	
	

	if (posicionX != posicionXf)
	{
		if (posicionX <= posicionXf)
			posicionX += velocidadX;
		else
			posicionX -= velocidadX;
		if (posicionX <= 0)
		{
			posicionX += velocidadX;
			posicionXf = posicionX;
			posicionYf = posicionY + ((rand() % 200) -100);
		}
		if (posicionX + ancho >= anchoPantalla)
		{
			posicionX -= velocidadX;
			posicionXf = posicionX;
			posicionYf = posicionY + ((rand() % 200) - 100);
		}
		if (posicionY + alto >= altoPantalla)
		{
			posicionX -= velocidadX;
			posicionXf = posicionX;
			posicionYf = posicionY + ((rand() % 200) - 100);
		}
	}
	else
	{
		if (posicionY != posicionYf)
		{
			if (posicionY < posicionYf)
				posicionY += velocidadY;
			else
				posicionY -= velocidadY;
			if (posicionY <= 0) 
			{
				posicionY += velocidadY;
				posicionYf = posicionY;
				posicionXf = posicionX + ((rand() % 200) - 100);
			}
			if (posicionY + alto > altoPantalla)
			{
				posicionY -= velocidadY;
				posicionYf = posicionY;
				posicionXf = posicionX + ((rand() % 200) - 100);
			}
			if (posicionX + ancho > anchoPantalla)
			{
				posicionY -= velocidadY;
				posicionYf = posicionY;
				posicionXf = posicionX + ((rand() % 200) - 100);
			}
		}
		else
		{
			posicionXf = posicionX + ((rand() % 200) - 100);
			posicionYf = posicionY + ((rand() % 200) - 100);
		}
	}
	
	
	/*if (posicionXi != posicionXf)
{
	if (posicionXi <= posicionXf)
		posicionXi += velocidadX;
	else
		posicionXi -= velocidadX;
	if (posicionXi <= 0)
	{
		posicionXi += velocidadX;
		posicionXf = posicionXi;
		posicionYf = posicionYi + ((rand() % 200) -100);
	}
	if (posicionX + ancho >= anchoPantalla)
	{
		posicionXi -= velocidadX;
		posicionXf = posicionXi;
		posicionYf = posicionYi + ((rand() % 200) - 100);
	}
	if (posicionYi + alto >= altoPantalla)
	{
		posicionXi -= velocidadX;
		posicionXf = posicionXi;
		posicionYf = posicionYi + ((rand() % 200) - 100);
	}
}
else
{
	if (posicionYi != posicionYf)
	{
		if (posicionYi < posicionYf)
			posicionYi += velocidadY;
		else
			posicionYi -= velocidadY;
		if (posicionYi <= 0)
		{
			posicionYi += velocidadY;
			posicionYf = posicionY;
			posicionXf = posicionXi + ((rand() % 200) - 100);
		}
		if (posicionYi + alto > altoPantalla)
		{
			posicionYi -= velocidadY;
			posicionYf = posicionYi;
			posicionXf = posicionXi + ((rand() % 200) - 100);
		}
		if (posicionXi + ancho > anchoPantalla)
		{
			posicionYi -= velocidadY;
			posicionYf = posicionY;
			posicionXf = posicionXi + ((rand() % 200) - 100);
		}
	}
	else
	{
		posicionXf = posicionXi + ((rand() % 200) - 100);
		posicionYf = posicionYi + ((rand() % 200) - 100);
	}
}


if (posicionXi <= posicionXf)
	posicionXi += velocidadX;
else
	posicionXi -= velocidadX;
if (posicionXi <= 0)
{
	posicionXi += velocidadX;
	posicionXf = posicionXi;
	posicionYf = posicionYi + ((rand() % 200) - 100);

}
if (posicionXi + ancho >= anchoPantalla)
{
	posicionXi -= velocidadX;
	posicionXf = posicionXi;
	posicionYf = posicionYi + ((rand() % 200) - 100);

}
if (posicionYi + alto >= altoPantalla)
{
	posicionXi -= velocidadX;
	posicionXf = posicionXi;
	posicionYf = posicionYi + ((rand() % 200) - 100);

}
}
	else
	{
	if (posicionYi != posicionYf)
	{
		if (posicionYi < posicionYf)
			posicionYi += velocidadY;
		else
			posicionYi -= velocidadY;
		if (posicionYi <= 0)
		{
			posicionYi += velocidadY;
			posicionYf = posicionYi;
			posicionXf = posicionXi + ((rand() % 200) - 100);
		}
		if (posicionYi + alto > altoPantalla)
		{
			posicionYi -= velocidadY;
			posicionYf = posicionYi;
			posicionXf = posicionXi + ((rand() % 200) - 100);
		}
		if (posicionXi + ancho > anchoPantalla)
		{
			posicionYi -= velocidadY;
			posicionYf = posicionYi;
			posicionXf = posicionXi + ((rand() % 200) - 100);
		}
	}
	else
	{
		posicionXf = posicionXi + ((rand() % 200) - 100);
		posicionYf = posicionYi + ((rand() % 200) - 100);
	}
	}*/


	//Mover el fantasma a la izquierda o derecha
	//posicionX += velocidadX;

	//// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
	//if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	//{
	//	// Mover fantasma atras
	//	posicionX -= velocidadX;
	//}

	//// Mover el fantasma arriba o abajo
	////posicionY += velocidadY;

	//// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
	//if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	//{
	//	// Mover fantasma atras
	//	posicionY -= velocidadY;
	//}


}

void Fantasma::render()
{
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
	SDL_RenderCopyEx(renderer, fantasmaTexture, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}
