#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Pacman : public GameObject
{
private:

	// Velocidad en eje X
	int velocidadX;

	// Velocidad en el eje Y
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	//Frame de la textura
	int frame;
	int contadorFrames;
	int conjuntoFrames;
	int framesMovimiento;

public:

	// Textura grafica de pacman;
	vector<Texture*> pacmanTexture;

	//Constructores y destructores
	Pacman(int _posicionX, int _posicionY, int _velocidadPatro, vector<Texture*> _pacmanTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip);
	//~Pacman();

	//Metodos accesores
		//int getPosicionX() { return posicionX; }
		//int getPosicionY() { return posicionY; }
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	/*int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }*/

	//void setPosicionX(int _posicionX) { posicionX = _posicionX; }
//void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	/*void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }*/
	//** OTRA FORMA**
	//int getPosicionX() { return posicion.x; }
	//int getPosicionY() { return posicion.y; }
	//void setPosicionX(int _x) { posicion.x = _x; }
	//void setPosicionX(int _y) { posicion.y = _y;  }
	// 

	// Metodos varios

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);

	// Mover pacman
	void move();

	// Renderizar imagen Pacman
	//void Renderizar();

	void update();

	// Renderizar imagen Pacman
		//void render();
};
