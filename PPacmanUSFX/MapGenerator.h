#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <list>

#include "GameObject.h"
#include "Texture.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Fruta.h"
#include "Muro.h"
#include "Pila.h"


using namespace std;

class MapGenerator
{
private:
	//vector<GameObject*> vectorObjetosJuego;
	Pila<GameObject*> pilaObjects = Pila<GameObject*>(10000);


	const string pathPacman = "Resources/PacMan.png";
	const string pathFantasma1 = "Resources/Blinky.png";
	const string pathFantasma2 = "Resources/Clyde.png";
	const string pathFantasma3 = "Resources/Inkey.png";
	const string pathFantasma4 = "Resources/Pinky.png";
	const string pathFruta1 = "Resources/Cherry.png";
	const string pathFruta2 = "Resources/Strawberry.png";
	const string pathFruta3 = "Resources/Apple.png";
	const string pathFruta4 = "Resources/GreenApple.png";
	const string pathFruta5 = "Resources/Orange.png";
	const string pathMoneda = "Resources/Monedas.png";
	const string pathSuperMoneda = "Resources/Monedas2.png";
	const string pathPared = "Resources/Wall.png";

	vector<Texture*> pacmanTexture;
	vector<Texture*> fantasmaTexture;
	vector<Texture*> frutaTexture;
	vector<Texture*> monedaTexture;
	vector<Texture*> superMonedaTexture;
	vector<Texture*> muroTexture;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	// Carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	//void populate(vector<GameObject*>& _vectorObjetosJuegoGM);
	void populate(list<GameObject*>& _vectorObjetosJuegoGM);
};