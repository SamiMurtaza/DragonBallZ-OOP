#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

class Words
{
private:
    int width;
    int height;
    int x1,y1;
    int initX = 0 ;
    int initY  = 0;

    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
    SDL_Rect Alphabets[26];
    SDL_Rect fillRect;


public:
    Words();
    Words(LTexture* image );
    ~Words();

    //getting alphabets in an array
    void getAlphahbets();

    //rendering words
    void RenderWord_Play(SDL_Renderer* gRenderer);
    void RenderWord_Load(SDL_Renderer* gRenderer);
    void RenderWord_Controls(SDL_Renderer* gRenderer);
    void RenderWord_ControlsHeading(SDL_Renderer* gRenderer);
    void RenderWord_Exit(SDL_Renderer* gRenderer);
    void RenderWord_GOKU(SDL_Renderer* gRenderer);
    void RenderWord_VEGETA(SDL_Renderer* gRenderer);
    void RenderWord_PICOLO(SDL_Renderer* gRenderer);
    void Render_AllOptions(SDL_Renderer* gRenderer);
    void RenderWord_ChooseYourCharacter(SDL_Renderer* gRenderer);
    void RenderWord_ESC(SDL_Renderer* gRenderer);
    void RenderWord_Health(SDL_Renderer* gRenderer);
    void RenderWord_Mana(SDL_Renderer* gRenderer);
    void RenderWord_Yes(SDL_Renderer* gRenderer);
    void RenderWord_No(SDL_Renderer* gRenderer);
    void RenderWord_Quit(SDL_Renderer* gRenderer);
    void RenderWord_GameOver(SDL_Renderer* gRenderer);

};

