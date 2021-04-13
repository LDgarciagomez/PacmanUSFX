#include "Game_manager.h"

using namespace std;

Game_manager::Game_manager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	gPacmanTexture = nullptr;
	for (int i = 0; i <= 3; i++)
	{
		gFantasmaTexture[i] = nullptr;
	}
	for (int i = 0; i <= 4; i++)
	{
		gfrutaTexture[i] = nullptr;
	}
	juego_en_ejecucion = true;
	srand(time(NULL));
	for (int i = 0; i <= 4; i++)
	{
		int t = 1 + rand() % (6 - 1);
		int x = 100 + rand() % (600 - 100);
		int y = 100 + rand() % (400 - 100);
		fruta[i] = new Fruta(x, y, t);
	}
	for (int i = 0; i <= 3; i++)
	{
		int x = 100 + rand() % (600 - 100);
		int y = 100 + rand() % (400 - 100);
		int xf = (-300 + rand() % (300 - -300));
		int yf = (-300 + rand() % (300 - -300));
		fantasma[i] = new Fantasma(x, y, xf, yf);
	}
}

int Game_manager::onExecute() {
	if (onInit() == false) {
		return -1;
	}
	pacman = new Pacman(ancho / 2, alto / 2, ancho, alto, 5, gWindow, gRenderer, gScreenSurface, gPacmanTexture);
	for (int i = 0; i <= 3; i++)
	{
		int x = 100 + rand() % (600 - 100);
		int y = 100 + rand() % (400 - 100);
		int xf = (rand() % 200 - 100);
		int yf = (rand() % 200 - 100);
		fantasma[i] = new Fantasma(x, y, xf, yf, gWindow, gRenderer, gScreenSurface, gFantasmaTexture[i]);
	}
	for (int i = 0; i <= 4; i++)
	{
		srand(time(NULL));
		int t = 1 + rand() % (6 - 1);
		int x = 100 + rand() % (600 - 100);
		int y = 100 + rand() % (400 - 100);
		fruta[i] = new Fruta(x, y, t, gWindow, gRenderer, gScreenSurface, gfrutaTexture[i]);
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
		for (int i = 0; i <= 3; i++)
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

bool Game_manager::ChangeFruta()
{
	bool success = true;
	for (int i = 0; i <= 4; i++)
	{
		switch (fruta[i]->getTipo())
		{
		case 1:
			gfrutaTexture[i] = loadTexture("Resources/Fruta01.png");
			if (gfrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 2:
			gfrutaTexture[i] = loadTexture("Resources/Fruta02.png");
			if (gfrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 3:
			gfrutaTexture[i] = loadTexture("Resources/Fruta03.png");
			if (gfrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		case 4:
			gfrutaTexture[i] = loadTexture("Resources/Fruta04.png");
			if (gfrutaTexture[i] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			break;
		
		}
	}
	return success;
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
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Inicializar color de renderizado
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}


			//Conseguir superficie de ventana
			gScreenSurface = SDL_GetWindowSurface(gWindow);


			//Cargar texturas a las superficies de los objetos
			gPacmanTexture = loadTexture("Resources/PacMan_01.bmp");
			if (gPacmanTexture == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[0] = loadTexture("Resources/Fantasma.bmp");
			if (gFantasmaTexture[0] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[1] = loadTexture("Resources/Fantasma2.bmp");
			if (gFantasmaTexture[1] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[2] = loadTexture("Resources/Fantasma3.bmp");
			if (gFantasmaTexture[2] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			gFantasmaTexture[3] = loadTexture("Resources/Fantasma4.bmp");
			if (gFantasmaTexture[3] == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			ChangeFruta();
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
	for (int i = 0; i <= 4; i++)
	{
		fruta[i]->render(gfrutaTexture[i]);
	}
	ChangeFruta();
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