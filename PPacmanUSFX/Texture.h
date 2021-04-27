#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

using namespace std;

class Texture
{
private:
	// Textura actual
	SDL_Texture* texture;

	// Dimensiones de la textura
	int ancho;
	int alto;

public:

	//Renderizador estático, se debe inicializar
	static SDL_Renderer* renderer;

	//Constructor y destructor
	Texture();
	~Texture();

	//Cargar textura de una imagen
	bool loadFromImage(string path, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);

	//Cargar textura de un texto
	bool loadFromRenderedText(TTF_Font* font, string text, SDL_Color textColor);

	//Renderizar textura
	void render(SDL_Rect* clip = NULL, SDL_Rect* renderQuad = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip renderFlip = SDL_FLIP_NONE);

	//Set color
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Set blend mode
	void setBlendMode(SDL_BlendMode blendMode);

	// Set alpha
	void setAlpha(Uint8 alpha);

	//Liberar memoria
	void free();

	//Métodos accesores
	int getAncho() { return ancho; }
	int getAlto() { return alto; }

};