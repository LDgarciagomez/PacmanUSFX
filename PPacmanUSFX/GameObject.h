#pragma once
#include <SDL.h>
#include <string>
#include <vector>

#include "Texture.h"

class GameObject
{
protected:
	// Posicion en el eje X y Y
	int posicionX;
	int posicionY;

	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;

	//Tipo de objeto
	int tipo;

	// Si el objeto es visible
	bool visible = true;

	//Textura
	vector<Texture*> texture;

	//Recortes y frames
	int frameX;
	int frameY;
	int anchoClip;
	int altoClip;
	bool isClip;

public:
	//Constructores y destructores
	GameObject(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, vector<Texture*> _textures, int _tipo, bool _isClip = false, int _frameX = 0, int _frameY = 0, int _anchoClip = 0, int _altoClip = 0);

	//Metodos accesores
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setVisible(bool _visible) { visible = _visible; }

	// Metodos varios

	// Renderizar imagen
	void renderObjects();

	//virtual void Renderizar();

	virtual void handleEvent(SDL_Event& e);

	//Movimiento
	virtual void move();

	virtual void update();

	virtual void show();
};