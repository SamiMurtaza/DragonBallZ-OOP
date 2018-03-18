
#ifndef Selection_menu_H
#define Selection_menu_H
#include <SDL.h>
#include <SDL_mixer.h>
#include "LTexture.h"
#include"Words.h"
#include <time.h>
#include <windows.h>

using namespace std;

class Selection_menu
{
public:
    Selection_menu(SDL_Window* gWindow,LTexture* gSpriteSheetTexture,LTexture* textSheetTexture,SDL_Texture* backgroundSelection,SDL_Texture* arrowSelection);
    int showFigs(SDL_Renderer* gRenderer);
    ~Selection_menu();
    void changeCharacter();
    int getCharacterNo();

protected:

private:
    int characterNumber ;
    Mix_Chunk* arrow;
    // for rendering images
    SDL_Rect stretchRect;
    SDL_Rect characterRect;
    //inputs
    SDL_Window* gWindow;
    LTexture* gSpriteSheetTexture;
    LTexture* textSheetTexture;
    SDL_Texture* backgroundSelection;
    SDL_Texture* arrowSelection;


};

#endif // SELECTIONPLAYERMENU_H
