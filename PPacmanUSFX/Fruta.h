
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
	/*bool visible;*/
	int tiempoVisible;
	int tiempoNoVisible;
	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

public:

	// Supeerficie grafica del fantasma;
	vector<Texture*> frutaTexture;

	//Constructores y destructores

	Fruta(int _posicionX, int _posicionY, int _tipo, vector<Texture*> _frutaTexture);
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

	// Renderizar imagen fruta
	//void render();
	
};

