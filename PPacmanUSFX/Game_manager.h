#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Moneda.h"
#include "Texture.h"
#include "MapGenerator.h"

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

public:

    //Dimensiones de la pantalla
    int ancho = 800;
    int alto = 600;

    //Objetos a crearse
    list<GameObject*> listObjects;
    //vector<GameObject*> objects;
    MapGenerator* generadorNivelJuego;

    //Constructor
    Game_manager();

    //Funciones varias
    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
};



 