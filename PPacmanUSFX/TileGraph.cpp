#include "TileGraph.h"

TileGraph::TileGraph()
{
	anchoTileGraph = 0;
	altoTileGraph = 0;
}

TileGraph::TileGraph(int _anchoTileGraph, int _altoTileGraph)
{
	for (int y = 0; y < _altoTileGraph; y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			listaTilesGraph.push_back(new Tile(x, y));
		}
	}
	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

void TileGraph::reconfigurar(int _anchoTileGraph, int _altoTileGraph)
{
	if (!listaTilesGraph.empty())
		listaTilesGraph.clear();

	for (int y = 0; y < _altoTileGraph; y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			listaTilesGraph.push_back(new Tile(x, y));
		}
	}
	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

TileGraph::~TileGraph()
{
	listaTilesGraph.clear();
}

Tile* TileGraph::getTileEn(int x, int y)
{
	int indice = getIndice(x, y);
	if (indice < 0)
		return nullptr;
	int c = 0;
	for (auto ilvo = listaTilesGraph.begin(); ilvo != listaTilesGraph.end(); ++ilvo) {
		if (c == indice) {
			return (*ilvo);
		}
	}
}

array<Tile*, 4> TileGraph::get4Vecinos(Tile* tile)
{
	std::array<Tile*, 4> Vecinos;

	int x = tile->getPosicionX();
	int y = tile->getPosicionY();

	Vecinos[0] = getTileEn(x, y + 1);		// N
	Vecinos[1] = getTileEn(x + 1, y);		// E
	Vecinos[2] = getTileEn(x, y - 1);		// S
	Vecinos[3] = getTileEn(x - 1, y);		// _anchoTileGraph

	return Vecinos;
}

array<Tile*, 8> TileGraph::get8Vecinos(Tile* tile)
{
	std::array<Tile*, 8> Vecinos;

	int x = tile->getPosicionX();
	int y = tile->getPosicionY();

	Vecinos[0] = getTileEn(x, y + 1);		// N
	Vecinos[1] = getTileEn(x + 1, y);		// E
	Vecinos[2] = getTileEn(x, y - 1);		// S
	Vecinos[3] = getTileEn(x - 1, y);		// _anchoTileGraph
	Vecinos[4] = getTileEn(x + 1, y + 1);	// NE
	Vecinos[5] = getTileEn(x - 1, y + 1);	// SE
	Vecinos[6] = getTileEn(x - 1, y - 1);	// SW
	Vecinos[7] = getTileEn(x + 1, y - 1);	// NW

	return Vecinos;
}

Pacman* TileGraph::getPacman()
{
	for (unsigned int i = 0; i < anchoTileGraph * altoTileGraph; i++) {
		Tile tile = Tiles[i];

		if (tile.getPacman() != nullptr)
			return tile.getPacman();
	}

	/*for (unsigned int i = 0; i < vectorTilesGraph.size(); i++) {
		Tile newTile = vectorTilesGraph[i];
		if (newTile.getPacman() != nullptr)
			return newTile.getPacman();
	}*/


	return nullptr;
}

int TileGraph::getIndice(int x, int y)
{
	if (x >= anchoTileGraph || y >= altoTileGraph)
		return -1;

	if (x < 0 || y < 0)
		return -1;

	return x + y * anchoTileGraph;
}