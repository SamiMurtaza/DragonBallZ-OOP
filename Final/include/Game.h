#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "LTexture.h"
#include <vector>
#include <iostream>


using namespace std;

class Game
{
public:
    Game(const char* title, int xpos, int ypos, int width, int height, bool fullscrn);

    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscrn, int sel);
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscrn, vector <string> loading);

    void handleEvents();
    void update();
    void render();
    void clean();
    void loadMedia();
    //void startGame();
    int &startGame();

    bool running()
    {
        return isRunning;
    }

    static SDL_Renderer* renderer;



private:

    Mix_Music *music = NULL;
    float ma=0.0;
    float attlen=0.0;
    bool ss=false;
    int sel;
    bool kam=false;
    int touches=0;
    bool alive=true;
    int input = 0;
    int updateCount = 0;
    bool isRunning = 1;
    ///SDL_Renderer* renderer = NULL;//renderer
    SDL_Window* window = NULL;//The window we'll be rendering to
    SDL_Surface* gScreenSurface = NULL;//The surface contained by the window
    SDL_Rect surfaces[5];
    SDL_Rect safeSurfaces[4];
    //loaded images


    LTexture gSpriteSheetTexture[4];//character sprites
    LTexture textSheetTexture;//Text sprites
    LTexture introImageTexture;//intro transition image
    LTexture gTransitionTexture;//intro transition image
    LTexture gTransitionbackground;//intro transition image
    SDL_Texture* bg1 = NULL;//mainMenu background image
    SDL_Texture* bg2 = NULL;//selectionMenu background image
    SDL_Texture* arrow = NULL;//arrow image
    SDL_Texture* arrowSelection = NULL;//selection arrow image
    SDL_Texture* transitionBg = NULL;//transition background image
    SDL_Texture* quitBg = NULL;//quit background image
    SDL_Texture* controlsImg = NULL;//controls image
    SDL_Texture* controlKeys[5];//controls image
    SDL_Texture* CreditsBg = NULL;//controls image

    SDL_Rect camera= {0,110,220,236};
    SDL_Texture* bg = NULL;
    Mix_Chunk* gBall;


    //
};
