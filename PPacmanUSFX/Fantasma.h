#pragma once
#include <SDL.h>
#include "Movimiento.h"
class Fantasma
{
private: 
	DireccionMovimiento direccionActual;
	DireccionMovimiento direccionSiguiente;
public:
	DireccionMovimiento getDireccionActual() { return direccionActual; }
	void setDireccionActual(DireccionMovimiento _direccionActual) { direccionActual = _direccionActual; }
	

	DireccionMovimiento getDireccionSiguiente() { return direccionActual; }
	void setDireccionSiguiente(DireccionMovimiento _direccionSiguiente) { direccionSiguiente = _direccionSiguiente; }

};

