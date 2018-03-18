#pragma once
#include "Game.h"

class GameObject
{
public:

    GameObject(const char* textureSheet, int x, int y, int R, int G, int B);
    ~GameObject();
    virtual void update(int flag,double angle = 0.0)=0;
    virtual void render();
    int getX()
    {
        return xpos;
    }
    int getY()
    {
        return ypos;
    }
    void setX(int num = 1)
    {
        this->xpos=num;
    }
    void setY(int num = 1)
    {
        this->ypos=num;
    }
    SDL_Rect* getSRect()
    {
        return &srcRect;
    }
    SDL_Rect* getDRect()
    {
        return &destRect;
    }
protected:
    int xpos, ypos;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    double angle = 0;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
//	SDL_Renderer* renderer;
};
