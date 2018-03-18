#ifndef MENU_H
#define MENU_H
#include "Main_menu.h"

class Menu //:public Main_menu
{
public:
    Menu();
    ~Menu();

    Menu(SDL_Renderer* gRenderer,SDL_Surface* gScreenSurface,SDL_Window* gWindow, SDL_Texture* background, SDL_Texture* quitBg,LTexture* gTransitionTexture, LTexture* gSpriteSheetTexture,LTexture* textSheetTexture,SDL_Texture* arrow,SDL_Texture* bg2,SDL_Texture* arrowSelection,SDL_Texture* transitionBg,SDL_Texture* controlsImg,SDL_Texture* controlKeys,SDL_Texture* CreditsBg);
    int display(SDL_Renderer* gRenderer);
    int close(SDL_Window* gWindow);

protected:

private:

    SDL_Texture* arrowSelection;
    SDL_Texture* CreditsBg;
    SDL_Texture* transitionBg;
    SDL_Texture* controlsImg;
    SDL_Texture* quitBg;
    SDL_Texture* controlKeys;
    SDL_Texture* bg2;
    LTexture* gSpriteSheetTexture;
    SDL_Texture* arrow;
    LTexture* textSheetTexture;
    SDL_Window* gWindow;
    SDL_Texture* background;
    SDL_Renderer* gRenderer;
    SDL_Surface* gScreenSurface;
    LTexture* gTransitionTexture;
    int input;
};

#endif // MENU_H
