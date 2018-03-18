#include "DragonBall.h"


DragonBall::DragonBall(const char* textureSheet, int x, int y, int R, int G, int B) : Enemy(textureSheet, x, y, R, G, B)
{
    DragonBall::type = 2;
    dead = false;
}

DragonBall::~DragonBall() {};

void DragonBall::update(int flag, double i_angle)
{
    flip = SDL_FLIP_NONE;
    srcRect.x = 0;
    srcRect.y = 160;
    srcRect.w = 200;
    srcRect.h = 190;

    angle = i_angle;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 0.10;
    destRect.h = srcRect.h * 0.10;
}
