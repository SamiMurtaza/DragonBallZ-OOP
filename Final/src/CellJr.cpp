#include "CellJr.h"
#include <SDL_mixer.h>
#include <iostream>

using namespace std;

CellJr::CellJr(const char* textureSheet, int x, int y, int R, int G, int B) :Enemy(textureSheet, x, y, R, G, B)
{
    CellJr::type = 1;
}

void CellJr::update(int flag, double i_angle = 0.0)
{
    if (flag == 1 && xpos < 750)
    {
        xpos += 2;    //moves left
        flip = SDL_FLIP_NONE;
        srcRect.x = 95;
        srcRect.y = 95;
        srcRect.h = 38;
        srcRect.w = 33;
    }
    if (flag == 2 && xpos > 0)
    {
        xpos -= 2;    // moves right
        flip = SDL_FLIP_HORIZONTAL;
        srcRect.x = 95;
        srcRect.y = 95;
        srcRect.h = 38;
        srcRect.w = 33;
    }
    if (flag == 3 && ypos > 0)
    {
        ypos -= 2;    //moves up
        srcRect.x = 145;
        srcRect.y = 135;
        srcRect.h = 43;
        srcRect.w = 30;
    }
    if (flag == 4 && ypos < 450)
    {
        ypos += 2;    //moves down
        srcRect.x = 135;
        srcRect.y = 95;
        srcRect.h = 30;
        srcRect.w = 38;
    }
    if (flag == 6)
    {
        srcRect.x = 135;    //idle
        srcRect.y = 95;
        srcRect.h = 30;
        srcRect.w = 38;
    }



    angle = i_angle;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w ;
    destRect.h = srcRect.h ;
    //frame++;
}

void CellJr::track(GameObject& player, bool flag)
{

    int x = player.getX();
    int y = player.getY();

    if (flag)
    {

        if (this->xpos - x > 100)
        {
            if (this->ypos > y)
            {
                ypos -= 2;
                update(2);
            }
            if (this->ypos < y)
            {
                ypos += 2;
                update(2);
            }
            this->update(2);
        }

        if (this->xpos - x < -100)
        {
            if (this->ypos > y)
            {
                ypos -= 2;
                update(1);
            }
            if (this->ypos < y)
            {
                ypos += 2;
                update(1);
            }
            this->update(1);
        }

        if (this->xpos - x <= 100 || this->xpos - x >= -100)
        {
            if (this->ypos > y)
            {
                ypos -= 2;
                update(3);
            }
            if (this->ypos < y)
            {
                ypos += 2;
                update(6);
            }
        }

        if (this->xpos - x == 100 || this->xpos - x == -100)
        {
            if (this->ypos == y)
            {
                kiBlast(attackFrame);
            }
        }
    }

    else
    {
        this->death(deathFrame);
    }
}

void CellJr::kiBlast(int frame)
{
    switch (frame % 20)
    {
    case 0:
        srcRect.x = 140;
        srcRect.y = 233;
        srcRect.h = destRect.h = 42;
        destRect.w = srcRect.w = 40;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    case 1:
        break;
    case 2:
        srcRect.x = 140;
        srcRect.y = 233;
        srcRect.h = destRect.h = 42;
        destRect.w = srcRect.w = 40 + 15;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos - 15;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    case 3:
        break;
    case 4:
        srcRect.x = 140;
        srcRect.y = 233;
        srcRect.h = destRect.h = 42;
        destRect.w = srcRect.w = 40 + 30;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos - 30;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    case 5:
        break;
    case 6:
        srcRect.x = 140;
        srcRect.y = 233;
        srcRect.h = destRect.h = 42;
        destRect.w = srcRect.w = 40 + 45;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos - 45;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    case 7:
        break;
    case 8:
        srcRect.x = 140;
        srcRect.y = 233;
        srcRect.h = destRect.h = 42;
        destRect.w = srcRect.w = 40 + 60;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos - 60;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    case 9:
        break;
    case 10:
        srcRect.x = 140;
        srcRect.y = 233;
        srcRect.h = destRect.h = 42;
        destRect.w = srcRect.w = 40 + 75;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos - 75;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    }
    attackFrame++;
    if (attackFrame % 20 == 0)
    {
        Enemy::attacks += 2;
        Mix_Chunk* gDamage = Mix_LoadWAV("audio/GokDamage.wav");
        Mix_PlayChannel(-1, gDamage, 0);
        Mix_PlayChannel(-1, gEAttack, 0);
        cout << Enemy::attacks << endl;
    }
}

void CellJr::death(int frame)
{
    switch (frame % 10)
    {
    case 0:
        srcRect.x = 165;
        srcRect.y = 190;
        srcRect.h = destRect.h = 40;
        destRect.w = srcRect.w = 30;
        destRect.x = xpos;
        //	if (flip == SDL_FLIP_HORIZONTAL) { destRect.x = xpos; }
        //	else { destRect.x = xpos; }
        destRect.y = ypos;
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        Mix_PlayChannel(-1, gEDamage, 0);
    case 4:
        break;
    case 5:
        srcRect.x = 342;
        srcRect.y = 205;
        srcRect.h = destRect.h = 25;
        destRect.w = srcRect.w = 40;
        destRect.x = xpos;
        //	if (flip == SDL_FLIP_HORIZONTAL) { destRect.x = xpos; }
        //	else { destRect.x = xpos; }
        destRect.y = ypos;
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    }
    deathFrame++;
    if (deathFrame == 10)
    {
        convert = true;
    }
}
