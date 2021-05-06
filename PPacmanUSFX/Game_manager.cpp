#include "Game_manager.h"

using namespace std;

Game_manager::Game_manager()
{
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	juego_en_ejecucion = true;
}

int Game_manager::onExecute() {
	if (onInit() == false) {
		return -1;
	}
	generadorNivelJuego = new MapGenerator(alto, ancho);
	generadorNivelJuego->load("Resources/mapa.txt");
	generadorNivelJuego->populate(listObjects);

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			//for (int i = 0; i < objects.size(); i++)
			for (auto ilvo = listObjects.begin(); ilvo != listObjects.end(); ++ilvo)
			{
				((GameObject*)*ilvo)->handleEvent(Event);
			}
		}

		for (auto ilvo = listObjects.begin(); ilvo != listObjects.end(); ++ilvo)
		{
			((GameObject*)*ilvo)->move();
			((GameObject*)*ilvo)->show();
		}

		//Limpiar pantalla
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

		//Actualizar pantalla
		onLoop();
		onRender();
		SDL_RenderPresent(gRenderer);
	}
	onCleanup();
	return 0;
}

bool Game_manager::onInit() {
	//Inicializar flag

	bool success = true;

	//Inicializar SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Crear ventana

		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho, alto, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Crear renderizador vsynced para la ventana

			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Inicializar color de renderizado
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			}

			//Conseguir superficie de ventana
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			//Cargar texturas a las superficies de los objetos

			Texture::renderer = gRenderer;

		}

	}
	return success;
};

void Game_manager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};

void Game_manager::onLoop() {};

void Game_manager::onRender() {
	for (auto ilvo = listObjects.begin(); ilvo != listObjects.end(); ++ilvo)
	{
		((GameObject*)*ilvo)->update();
		((GameObject*)*ilvo)->renderObjects();
	}
};

void Game_manager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	SDL_Quit();
};

//SDL_Texture* GameManager::loadTexture(string path)
//{
//	// Textura final generada
//	SDL_Texture* newTexture = nullptr;
//
//	// Carga una imagen de una ruta especifica
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//	if (loadedSurface == NULL)
//	{
//		cout << "No se pudo cargarla imagen, SDL_image Error: " << IMG_GetError() << endl;
//	}
//	else
//	{
//		// Crea una textura a partir de una superficie de pixeles
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//		if (newTexture == NULL)
//		{
//			cout << "No se pudo crear la textura, SDL Error: " << SDL_GetError() << endl;
//		}
//		// Libera la superficie cargada
//		SDL_FreeSurface(loadedSurface);
//	}
//	return newTexture;
//}