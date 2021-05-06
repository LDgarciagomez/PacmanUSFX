#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

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

	//Frame de la textura
	int contadorFrames;
	int framesMovimiento;

public:

	// Superficie gráfica de la moneda;
	vector<Texture*> monedaTexture;

	//Constructores y destructores
	Moneda(int _posicionX, int _posicionY, int _tipo, int _valor, vector<Texture*> _monedaTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip);
	//~Moneda();

	//Metodos accesores

	int getValor() { return valor; }
	int getTipo() { return tipo; }

	void setTipo(int _tipo) { tipo = _tipo; }
	void setValor(int _valor) { valor = _valor; }

	// Metodos varios

	//Actualizar para la animación
	void update();

};
