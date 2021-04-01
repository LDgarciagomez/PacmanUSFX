#pragma once
#include <SDL.h>
class Pacman
{
private:
	SDL_Point posicion;
	int color;
	float velocidadX;
	float velocidadY;
public:
	void move(float _velocidadX, float velocidadY);

	SDL_Point getPosicion() { return posicion;  }
	void  setPosicionX(SDL_Point _posicion) { posicion = _posicion; }
	

	float getVelocidadX() { return velocidadX ; }
	void  setVelocidadX(float _velocidadX) { posicionX = _velocidadX; }
	float getVelocidadY() { return velocidadY; }
	void  setVelocidadY(float _velocidadY) { posicionY = _velocidadY; }







};

