#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "LTexture.h"
#include <SDL_mixer.h>


class Main_menu
{
public:
    Main_menu(SDL_Renderer* gRenderer,SDL_Surface* gScreenSurface,SDL_Window* gWindow,SDL_Texture* background, SDL_Texture* quitBg,LTexture* textSheetTexture,SDL_Texture* controlsImg,SDL_Texture* controlKeys,LTexture* gSpriteSheetTexture,LTexture* gTransitionTexture,SDL_Texture* arrow,SDL_Texture* transitionBg,SDL_Texture* CreditsBg);
    int displayMenu( SDL_Renderer* gRenderer);
    int controls(SDL_Renderer* gRenderer);
    void showTransition( SDL_Renderer* gRenderer);
    void showCredits( SDL_Renderer* gRenderer);
    void moveArrow_up(int*arrow_y);
    void setArrow_up(int*arrow_y);
    void setArrow_down(int*arrow_y);
    void moveArrow_down(int*arrow_y);
    int quitWindow(bool menuBool,SDL_Renderer* gRenderer);
    int quit();
    ~Main_menu();

protected:

private:
    //
    SDL_Renderer* gRenderer;
    SDL_Texture* quitBg;
    LTexture* gSpriteSheetTexture;
    LTexture* gTransitionTexture;
    SDL_Texture* background;
    SDL_Surface* gScreenSurface;
    SDL_Surface* gCurrentSurface;
    LTexture* textSheetTexture;
    SDL_Texture* controlKeys;
    LTexture* spriteSheetTexture;
    SDL_Texture* controlsImg;
    SDL_Window* gWindow;
    SDL_Texture* arrow;
    SDL_Texture* transitionBg;
    SDL_Event e;
    SDL_Rect stretchRect;
    SDL_Rect menuArrow;
    SDL_Texture* gTexture;
    SDL_Texture* CreditsBg;
    Mix_Chunk* Arrow;

    //
    int arrow_x;
    int arrow_y;
    int arrowCount;
    int input;
    bool showIntroTransition;


};

#endif // MAIN_MENU_H

