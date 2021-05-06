#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Fruta : public GameObject
{
private:

	//Tipo de fruta
	int tipo;

	//Recursos para la funcion "mostrar"
	int tiempoVisible;
	int tiempoNoVisible;
	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

	//Frame de la textura
	int contadorFrames;
	int framesMovimiento = 4;

public:

	// Supeerficie grafica del fantasma;
	vector<Texture*> frutaTexture;

	//Constructores y destructores

	Fruta(int _posicionX, int _posicionY, int _tipo, vector<Texture*> _frutaTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip);
	//~Fruta();

	//Metodos accesores

	int getTipo() { return tipo; }
	bool getVisible() { return visible; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }

	void setTipo(int _tipo) { tipo = _tipo; }
	void setVisible(bool _visible) { visible = _visible; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }


	// Metodos varios

	// Mostrar u ocultar fruta
	void show();

	//Actualizar para la animación
	void update();

};

	// Renderizar imagen fruta
	//void render();
	


