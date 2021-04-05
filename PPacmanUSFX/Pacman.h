#pragma once
#include <SDL.h>
class Pacman
{
private:
	SDL_Point posicion;
	int color;


	SDL_Point velocidad;
	int color;

public:
	void move(float _velocidadX, float velocidadY);

	SDL_Point getPosicion() { return posicion;  }
	void  setPosicion(SDL_Point _posicion) { posicion = _posicion; }
	
	//** OTRA FORMA**
	//int getPosicionX() { return posicion.x; }
	//int getPosicionY() { return posicion.y; }
	//void setPosicionX(int _x) { posicion.x = _x; }
	//void setPosicionX(int _y) { posicion.y = _y;  }

	SDL_Point getVelocidad() { return velocidad; }
	void  setVelocidad(SDL_Point _velocidad) { velocidad = _velocidad; }
	







};

