#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Fruta
{
private:
	// Posicion actual de la fruta en la pantalla
	int posicionX;
	int posicionY;

	//Alto y ancho de la fruta
	int ancho;
	int alto;

	//Alto y ancho de la pantalla
	int anchoPantalla;
	int altoPantalla;

	//Tipo de fruta
	int tipo;

	//Recursos para la funcion "mostrar"
	bool visible;
	int tiempoVisible;
	int tiempoNoVisible;
	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Supeerficie grafica del fantasma;
	SDL_Texture* frutaTexture = nullptr;

	//Constructores y destructores

	Fruta();
	Fruta(int _posicionX, int _posicionY, int tipo);
	Fruta(int _posicionX, int _posicionY, int _tipo, SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutaTexture);
	//~Fruta();

	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	int getTipo() { return tipo; }
	bool getVisible() { return visible; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }


	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setTipo(int _tipo) { tipo = _tipo; }
	void setVisible(bool _visible) { visible = _visible; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }


	// Metodos varios

	// Mostrar u ocultar fruta
	void mostrar();

	// Renderizar imagen fruta
	void render(SDL_Texture* Textura);
};