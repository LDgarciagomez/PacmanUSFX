#include "Game_manager.h"

using namespace std;

Game_manager::Game_manager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	gPacmanTexture = nullptr;
	//for (int i = 0; i <= 4; i++)
	//{
	//	gFrutaTexture[i] = nullptr;
	//}
	for (int i = 0; i <= 2; i++)
	{
		gMonedaTexture[i] = nullptr;
	}
	juego_en_ejecucion = true;
	srand(time(NULL));
	for (int i = 0; i <= 4; i++)
	{
		int t = rand() % 5;
		int x = 1 + rand() % (ancho - 1);
		int y = 1 + rand() % (alto - 1);
		fruta[i] = new Fruta(x, y, t);
	}
	for (int i = 0; i <= 3; i++)
	{
		int x = 1 + rand() % (ancho - 1);
		int y = 1 + rand() % (alto - 1);
		int xf = 1 + rand() % (ancho - 1);
		int yf = 1 + rand() % (alto - 1);
		fantasma[i] = new Fantasma(x, y, xf, yf);
	}
	for (int i = 0; i <= 23; i++)
	{
		int x = 1 + rand() % (alto - 1);
		int y = 1 + rand() % (ancho - 1);
		if (i <= 19)
			moneda[i] = new Moneda(x, y, 1, 100);
		else
			moneda[i] = new Moneda(x, y, 2, 500);
	}
}

int Game_manager::onExecute() {
	if (onInit() == false) {
		return -1;
	}
	pacman = new Pacman(ancho / 2, alto / 2, 5, gPacmanTexture);
	for (int i = 0; i <= 3; i++)
	{
		int x = 1 + rand() % (ancho - 1);
		int y = 1 + rand() % (alto - 1);
		int xf = 1 + rand() % (ancho - 1);
		int yf = 1 + rand() % (alto - 1);
		fantasma[i] = new Fantasma(x, y, xf, yf, gFantasmaTexture[i]);
	}
	for (int i = 0; i <= 4; i++)
	{
		int t = rand() % 5;
		int x = 1 + rand() % (ancho - 1);
		int y = 100 + rand() % (alto - 1);
		fruta[i] = new Fruta(x, y, t, gFrutaTexture);
	}

	for (int i = 0; i <= 23; i++)
	{
		int x = 1 + rand() % (ancho - 1);
		int y = 1 + rand() % (alto - 1);
		if (i <= 19)
			moneda[i] = new Moneda(x, y, 1, 100, gMonedaTexture[i]);
		else
			moneda[i] = new Moneda(x, y, 2, 500, gMonedaTexture[i]);
	}

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			pacman->handleEvent(Event);
		}
		pacman->move();

		// Mover Fantasma
		for (int i = 0; i <= 3; i++)
		{
			fantasma[i]->move();
		}

		//Mostrar y ocultar frutas
		for (int i = 0; i <= 4; i++)
		{
			fruta[i]->mostrar();
		}

		//Limpiar pantalla
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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

			gPacmanTexture = new Texture();
			if (!gPacmanTexture->loadFromImage("Resources/PacMan_01.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture[0] = new Texture();
			if (!gFantasmaTexture[0]->loadFromImage("Resources/Fantasma.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture[1] = new Texture();
			if (!gFantasmaTexture[1]->loadFromImage("Resources/Fantasma2.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture[2] = new Texture();
			if (!gFantasmaTexture[2]->loadFromImage("Resources/Fantasma3.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			gFantasmaTexture[3] = new Texture();
			if (!gFantasmaTexture[3]->loadFromImage("Resources/Fantasma4.bmp")) {
				cout << "Fallo en la carga de la textura" << endl;
				return false;
			}
			for (int i = 0; i <= 23; i++)
			{
				switch (moneda[i]->getTipo())
				{
				case 1:
					gMonedaTexture[i] = new Texture();
					if (!gMonedaTexture[i]->loadFromImage("Resources/point.bmp")) {
						cout << "Fallo en la carga de la textura" << endl;
						return false;
					}
					break;
				case 2:
					gMonedaTexture[i] = new Texture();
					if (!gMonedaTexture[i]->loadFromImage("Resources/point2.bmp")) {
						cout << "Fallo en la carga de la textura" << endl;
						return false;
					}
					break;
				}
			}

			gFrutaTexture.push_back(new Texture());
			gFrutaTexture[0]->loadFromImage("Resources/Fruta01.png");
			gFrutaTexture.push_back(new Texture());
			gFrutaTexture[1]->loadFromImage("Resources/Fruta02.png");
			gFrutaTexture.push_back(new Texture());
			gFrutaTexture[2]->loadFromImage("Resources/Fruta03.png");
			gFrutaTexture.push_back(new Texture());
			gFrutaTexture[3]->loadFromImage("Resources/Fruta04.png");
			
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
	pacman->render();

	for (int i = 0; i <= 3; i++)
	{
		fantasma[i]->render();
	}
	for (int i = 0; i <= 23; i++)
	{
		moneda[i]->render();
	}
	for (int i = 0; i <= 3; i++)
	{
		fruta[i]->render();
	}
};

void Game_manager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	SDL_Quit();
};

SDL_Texture* Game_manager::loadTexture(string path)
{
	// Textura final generada
	SDL_Texture* newTexture = nullptr;

	// Carga una imagen de una ruta especifica
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "No se pudo cargarla imagen, SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		// Crea una textura a partir de una superficie de pixeles
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "No se pudo crear la textura, SDL Error: " << SDL_GetError() << endl;
		}

		// Libera la superficie cargada
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}