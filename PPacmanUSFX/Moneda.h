#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Moneda : public GameObject
{
private:

	//Valor de puntos de la moneda
	int valor;

	//Tipo de moneda (Moneda/Supermoneda)
	int tipo;

public:

	// Superficie gráfica de la moneda;
	Texture* monedaTexture = nullptr;

	//Constructores y destructores
	Moneda(int _posicionX, int _posicionY, int _tipo, int _valor);
	Moneda(int _posicionX, int _posicionY, int _tipo, int _valor, Texture* _monedaTexture);
	//~Moneda();

	//Metodos accesores

	int getValor() { return valor; }
	int getTipo() { return tipo; }

	void setTipo(int _tipo) { tipo = _tipo; }
	void setValor(int _valor) { valor = _valor; }

	// Metodos varios

	// Renderizar imagen del fantasma
	void render();

};