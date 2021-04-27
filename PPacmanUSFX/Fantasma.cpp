#include "Fantasma.h"

using namespace std;

Fantasma::Fantasma(int _posicionX, int _posicionY, int _posicionXf, int _posicionYf, int _tipo, vector<Texture*> _fantasmaTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _fantasmaTexture, _tipo, _isClip, _frameX, _frameY, _anchoClip, _altoClip)
{
	velocidadX = 1;
	velocidadY = 1;
	velocidadPatron = 5;
	ancho = 25;
	alto = 25;
	fantasmaTexture = _fantasmaTexture;
	posicionXf = _posicionXf;
	posicionYf = _posicionYf;
	tipo = _tipo;
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
					frameY = 0;
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
					frameY = 0;
				}

			}
		}
		else {
			posicionX += velocidadX;
			frameY = 1;
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
					frameY = 0;
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
					frameY = 0;
				}

			}
		}
		else {
			posicionX -= velocidadX;
			frameY = 1;
		}
	}
}


void Fantasma::update() {
	contadorFrames++;
	if (contadorFrames >= 10)
	{
		frameX++;
		if (frameX == framesMovimiento)
		{
			frameX -= 4;
		}
		contadorFrames = 0;
	}
}

//void Fantasma::render()
//{
//	SDL_Rect clip{ 0, 0, ancho, alto };
//	fantasmaTexture->render(posicionX, posicionY, &clip);
//}