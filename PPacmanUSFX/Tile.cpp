#include "Tile.h"


Tile::Tile() {
	posicionX = 0;
	posicionY = 0;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	muro = nullptr;
}

Tile::Tile(int _x, int _y) {
	posicionX = _x;
	posicionY = _y;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	muro = nullptr;
}

//void Tile::setPosicion(int _x, int _y) {
//	posicion.x = _x;
//	posicion.y = _y;
//}