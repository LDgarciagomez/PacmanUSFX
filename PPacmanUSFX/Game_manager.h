#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Moneda.h"
#include "Texture.h"

using namespace std;



class Game_manager
{
private:

    bool juego_en_ejecucion;

    //La ventana que será renderizada
    SDL_Window* gWindow;

    //El renderizador de la pantalla
    SDL_Renderer* gRenderer;

    //La superficie en la pantalla
    SDL_Surface* gScreenSurface;

    //Imágenes que se mostrarán en la pantalla
    vector<Texture*> gPacmanTexture;
    vector<Texture*> texturas;
    vector<Texture*> gFantasmaTexture;
    vector<Texture*> gFrutaTexture;
    vector<Texture*> gMonedaTexture;
    //Texture* gPacmanTexture;
    //Texture* gFantasmaTexture[4];
    /* Texture* gMonedaTexture[24];*/


public:

    //Dimensiones de la pantalla
    int ancho = 640;
    int alto = 480;

    //Objetos a crearse
    vector<GameObject*> objects;
    //Pacman* pacman;
//Fantasma* fantasma[4];
//Fruta* fruta[5];
//Moneda* moneda[24];

    //Constructor
    Game_manager();

    //Funciones varias
    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
    SDL_Texture* loadTexture(string path);
};



 