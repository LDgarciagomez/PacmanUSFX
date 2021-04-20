#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Fantasma : public GameObject
{
private:

	//Posiciones iniciales y finales
	int posicionXf;
	int posicionYf;
	int posicionXi;
	int posicionYi;

	//Velocidad en eje X
	int velocidadX;

	//Velocidad en el eje Y
	int velocidadY;

	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

public:

	//Textura del fantasma;
	Texture* fantasmaTexture;

	//Constructores y destructores
	Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf);
	Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf, Texture* _fantasmaTexture);
	//~Fantasma();

	//Metodos accesores

	int getPosicionXi() { return posicionXi; }
	int getPosicionYi() { return posicionYi; }
	int getPosicionXf() { return posicionXf; }
	int getPosicionYf() { return posicionYf; }
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setPosicionXi(int _posicionXi) { posicionXi = _posicionXi; }
	void setPosicionYi(int _posicionYi) { posicionYi = _posicionYi; }
	void setPosicionXf(int _posicionXf) { posicionXf = _posicionXf; }
	void setPosicionYf(int _posicionYf) { posicionYf = _posicionYf; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }


	//// Metodos varios

	// Mover fantasma
	void move();

	// Renderizar imagen del fantasma
	void render();

};