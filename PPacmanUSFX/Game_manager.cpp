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
	srand(time(NULL));
	objects.push_back(new Pacman(ancho / 2, alto / 2, 5, gPacmanTexture, true, 0, 0, 25, 25));
	for (int i = 0; i <= 3; i++)
	{
		int x = 1 + rand() % (ancho - 1);
		int y = 1 + rand() % (alto - 1);
		int xf = 1 + rand() % (ancho - 1);
		int yf = 1 + rand() % (alto - 1);
		objects.push_back(new Fantasma(x, y, xf, yf, i, gFantasmaTexture, true, 0, 0, 25, 25));
	}
	for (int i = 0; i <= 4; i++)
	{
		int t = rand() % 5;
		int x = 1 + rand() % (ancho - 1);
		int y = 100 + rand() % (alto - 1);
		objects.push_back(new Fruta(x, y, t, gFrutaTexture));
	}

	for (int i = 0; i <= 23; i++)
	{
		int x = 1 + rand() % (ancho - 1);
		int y = 1 + rand() % (alto - 1);
		if (i <= 19)
			objects.push_back(new Moneda(x, y, 0, 100, gMonedaTexture));
		else
			objects.push_back(new Moneda(x, y, 1, 500, gMonedaTexture));
	}

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			for (int i = 0; i < objects.size(); i++)
			{
				objects[i]->handleEvent(Event);
			}
		}
		/*Mover Fantasma*/
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->move();
		}
		//Mostrar y ocultar frutas
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->show();
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

			gPacmanTexture.push_back(new Texture());
			if (!gPacmanTexture[0]->loadFromImage("Resources/PacMan.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture.push_back(new Texture());
			if (!gFantasmaTexture[0]->loadFromImage("Resources/Blinky.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture.push_back(new Texture());
			if (!gFantasmaTexture[1]->loadFromImage("Resources/Clyde.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture.push_back(new Texture());
			if (!gFantasmaTexture[2]->loadFromImage("Resources/Inkey.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture.push_back(new Texture());
			if (!gFantasmaTexture[3]->loadFromImage("Resources/Pinky.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gMonedaTexture.push_back(new Texture());
			if (!gMonedaTexture[0]->loadFromImage("Resources/point.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gMonedaTexture.push_back(new Texture());
			if (!gMonedaTexture[1]->loadFromImage("Resources/point2.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFrutaTexture.push_back(new Texture());
			if (!gFrutaTexture[0]->loadFromImage("Resources/Fruta01.png")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFrutaTexture.push_back(new Texture());
			if (!gFrutaTexture[1]->loadFromImage("Resources/Fruta02.png")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFrutaTexture.push_back(new Texture());
			if (!gFrutaTexture[2]->loadFromImage("Resources/Fruta03.png")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFrutaTexture.push_back(new Texture());
			if (!gFrutaTexture[3]->loadFromImage("Resources/Fruta04.png")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			
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
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->update();
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->renderObjects();
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