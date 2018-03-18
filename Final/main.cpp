#include "Game.h"
#include <time.h>
#include <SDL.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

Game* game = NULL;
using namespace std;

int main(int argc, char* args[])
{

    srand( (time(NULL)));

    const int FPS = 40;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game("Dragon Ball Adventures", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 940, 780, true);

    game->loadMedia();

    game->startGame();
    while (game->running())
    {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}

