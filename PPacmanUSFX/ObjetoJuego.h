#pragma once
class ObjetoJuego
{
private:
	// Posicion x
	int posicionX;
	// Posicion y
	int posicionY;

	
	//Ancho de la imagen del objeto en pixels
	int ancho;
	//Alto de la imagen del objeto en pixels
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;
	
	//Si el objeto es visible
	bool visible;



public:
	ObjetoJuego(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	
	//Metodos Accesores
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible;}

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setVisible(bool _visible) { visible = _visible; }



	// Renderizar imagen Pacman
	void render();


};

