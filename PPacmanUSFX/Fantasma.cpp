#include "Fantasma.h"

using namespace std;

Fantasma::Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla)
{
	velocidadX = 1;
	velocidadY = 1;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	posicionXf = _posicionXf;
	posicionYf = _posicionYf;
}

Fantasma::Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf, Texture* _fantasmaTexture) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla)
{
	velocidadX = 1;
	velocidadY = 1;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	fantasmaTexture = _fantasmaTexture;
	posicionXf = _posicionXf;
	posicionYf = _posicionYf;
}


void Fantasma::move()
{
	//Comprobar si debe ir hacia la izquierda o hacia la derecha 
	if (posicionXf > posicionXi) {
		//Comprobar si ya llegó al punto Xf
		if (posicionX >= posicionXf) {
			//Comprobar si debe ir  arriba o abajo
			if (posicionYf > posicionYi) {
				//Comprobar si ya llegó al punto Yf y crear un nuevo punto Xf y Yf
				if (posicionY >= posicionYf) {
					posicionXi = posicionXf;
					posicionYi = posicionYf;

					posicionXf = 1 + rand() % (anchoPantalla - 1);
					posicionYf = 1 + rand() % (altoPantalla - 1);
				}
				else {
					posicionY += velocidadY;
				}
			}
			else {
				if (posicionY <= posicionYf) {
					posicionXi = posicionXf;
					posicionYi = posicionYf;

					posicionXf = 1 + rand() % (anchoPantalla - 1);
					posicionYf = 1 + rand() % (altoPantalla - 1);
				}
				else {
					posicionY -= velocidadY;
				}

			}
		}
		else {
			posicionX += velocidadX;
		}
	}
	else {
		if (posicionX <= posicionXf) {
			if (posicionYf > posicionYi) {
				if (posicionY >= posicionYf) {
					posicionXi = posicionXf;
					posicionYi = posicionYf;

					posicionXf = 1 + rand() % (anchoPantalla - 1);
					posicionYf = 1 + rand() % (altoPantalla - 1);
				}
				else {
					posicionY += velocidadY;
				}
			}
			else {
				if (posicionY <= posicionYf) {
					posicionXi = posicionXf;
					posicionYi = posicionYf;

					posicionXf = 1 + rand() % (anchoPantalla - 1);
					posicionYf = 1 + rand() % (altoPantalla - 1);
				}
				else {
					posicionY -= velocidadY;
				}

			}
		}
		else {
			posicionX -= velocidadX;
		}
	}
}

void Fantasma::render()
{
	SDL_Rect clip{ 0, 0, ancho, alto };
	fantasmaTexture->render(posicionX, posicionY, &clip);
}