
#pragma once
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
class Muro : public GameObject
{
private:

	//Valor de puntos de la moneda
	int valor;

	//Tipo de muro
	int tipo;

public:

	// Superficie gráfica de la moneda;
	vector<Texture*> muroTexture;

	//Constructores y destructores
	Muro(int _posicionX, int _posicionY, int _tipo, vector<Texture*> _muroTexture);
	//~Muro();

	//Metodos accesores

	int getValor() { return valor; }
	int getTipo() { return tipo; }

	void setTipo(int _tipo) { tipo = _tipo; }
	void setValor(int _valor) { valor = _valor; }
};