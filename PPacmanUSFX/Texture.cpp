#include "Texture.h"

SDL_Renderer* Texture::renderer = nullptr;

Texture::Texture()
{
	texture = nullptr;
	ancho = 0;
	alto = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromImage(string path, Uint8 r, Uint8 g, Uint8 b)
{
	// Free the previous texture
	free();

	// Return if the renderer was not set
	if (Texture::renderer == nullptr) {
		printf("Render no inicializado %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return false;
	}

	// Load image to a surface
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr) {
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return false;
	}

	// Set color key
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));

	// Create texture from the surface
	texture = SDL_CreateTextureFromSurface(Texture::renderer, loadedSurface);
	if (texture == nullptr) {
		printf("Unable to create texture from surface %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return false;
	}

	// Set width and height of the texture
	ancho = loadedSurface->w;
	alto = loadedSurface->h;

	// Free the surface
	SDL_FreeSurface(loadedSurface);

	return true;
}

bool Texture::loadFromRenderedText(TTF_Font* font, string text, SDL_Color textColor)
{
	// Free the previous texture
	free();

	// Return if the renderer was not set
	if (Texture::renderer == nullptr)
		return false;

	// Render the text using SDL_ttf library
	SDL_Surface* loadedSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
	if (loadedSurface == nullptr) {
		printf("Unable to render text! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	// Create a texture from generated surface
	texture = SDL_CreateTextureFromSurface(Texture::renderer, loadedSurface);
	if (texture == nullptr) {
		printf("Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	// Set width and height of the texture
	ancho = loadedSurface->w;
	alto = loadedSurface->h;

	// Free the surface
	SDL_FreeSurface(loadedSurface);

	return true;
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip renderFlip)
{
	// Return if the renderer was not set
	if (Texture::renderer == nullptr)
		return;

	SDL_Rect renderQuad = { x, y, ancho, alto };

	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(Texture::renderer, texture, clip, &renderQuad, angle, center, renderFlip);
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blendMode)
{
	SDL_SetTextureBlendMode(texture, blendMode);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::free()
{
	if (texture != nullptr) {
		// Free the texture and set its pointer to NULL
		SDL_DestroyTexture(texture);
		texture = nullptr;

		ancho = 0;
		alto = 0;
	}
}

int Texture::getAncho()
{
	return ancho;
}

int Texture::getAlto()
{
	return alto;
}