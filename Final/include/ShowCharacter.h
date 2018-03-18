#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class ShowCharacter
{
protected:
    //for character 1
    float x1;
    float y1;
    int width1;
    int height1;

    //for character 2
    float x2;
    float y2;
    int width2;
    int height2;

    //for character 3
    float x3;
    float y3;
    int width3;
    int height3;

    //for transition
    float xT;
    float yT;
    int widthT;
    int heightT ;

    int characterNumber;
    enum ANIMATION_FRAMES {FLYING_FRAMES = 15};
    SDL_Rect spriteClips1[ FLYING_FRAMES ]; //character 1

    enum ANIMATION_FRAME1 {FLYING_FRAMES1 = 9};
    SDL_Rect spriteClips2[ FLYING_FRAMES1 ]; //character 2

    enum ANIMATION_FRAME2 {FLYING_FRAMES2 = 7};
    SDL_Rect spriteClips3[ FLYING_FRAMES2 ]; //character 3

    SDL_Rect spriteTransition[ 1 ]; //transition screen

    //3 characters
    LTexture* spriteSheetTexture1;
    LTexture* spriteSheetTexture2;
    LTexture* spriteSheetTexture3;

    //transition
    LTexture* spriteSheetTexture;

public:

    ShowCharacter(LTexture* image, float x, float y);
    ShowCharacter();
    virtual ~ShowCharacter();
    void Render(long int& frame, SDL_Renderer* gRenderer,int characterNumber);
    void RenderTransition(long int& frame, SDL_Renderer* gRenderer, int transparency);

};

