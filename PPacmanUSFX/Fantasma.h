#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>

using namespace std;

class Fantasma {
private:
	//Posicion actual del fantasma en la pantalla
	int posicionX;
	int posicionY;

	//Posiciones iniciales y finales de movimiento
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

	//Ancho y alto del fantasma
	int ancho;
	int alto;

	//Ancho y alto de la pantalla
	int anchoPantalla;
	int altoPantalla;

public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Supeerficie grafica del fantasma;
	SDL_Texture* fantasmaTexture = nullptr;

public:
	//Constructores y destructores
	Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf);
	Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture);
	//~Fantasma();

	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getPosicionXi() { return posicionXi; }
	int getPosicionYi() { return posicionYi; }
	int getPosicionXf() { return posicionXf; }
	int getPosicionYf() { return posicionYf; }
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setPosicionXi(int _posicionXi) { posicionXi = _posicionXi; }
	void setPosicionYi(int _posicionYi) { posicionYi = _posicionYi; }
	void setPosicionXf(int _posicionXf) { posicionXf = _posicionXf; }
	void setPosicionYf(int _posicionYf) { posicionYf = _posicionYf; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }


	//// Metodos varios
	// Mover fantasma
	void move();
	// Renderizar imagen del fantasma
	void render();

};