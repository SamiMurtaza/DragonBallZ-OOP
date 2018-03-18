#include "Saibaman.h"
#include <SDL_mixer.h>


Saibaman::Saibaman(const char* textureSheet, int x, int y, int R, int G, int B) :Enemy(textureSheet, x, y, R, G, B)
{
    Saibaman::type = 0;
    dead = false;
}

void Saibaman::update(int flag, double i_angle = 0.0)
{
    if (flag == 1 && xpos < 750)
    {
        xpos += 2;    //moves left
        flip = SDL_FLIP_NONE;
        srcRect.x = 60;
        srcRect.y = 65;
    }
    if (flag == 2 && xpos > 0)
    {
        xpos -= 2;    // moves right
        flip = SDL_FLIP_HORIZONTAL;
        srcRect.x = 60;
        srcRect.y = 65;
    }
    if (flag == 3 && ypos > 0)
    {
        /*xpos += 2;*/ ypos -= 2;    //moves up
        srcRect.x = 0;
        srcRect.y = 65;
    }
    if (flag == 4 && ypos < 450)
    {
        /*xpos -= 2;*/ ypos += 2;   //moves down
    }
    if (flag == 5)
    {
        if (ypos <= 450)
        {
            ypos += 1;
        }
        srcRect.x = 0;
        srcRect.y = 0;
    }
    if (flag == 6)
    {
        srcRect.x = 55;
        srcRect.y = 145;
    }

    srcRect.h = 55;
    srcRect.w = 55;

    angle = i_angle;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w ;
    destRect.h = srcRect.h ;
    //frame++;
}

void Saibaman::track(GameObject& player, bool flag)
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
                update(5);
            }
            if (this->ypos < y)
            {
                ypos += 2;
                update(5);
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

void Saibaman::kiBlast(int frame)
{
    switch (frame % 18)
    {
    case 0:
        srcRect.x = 55;
        srcRect.y = 145;
        srcRect.h = 55;
        destRect.w = srcRect.w = 55;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos + 30 -30;
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
        break;
    case 3:
        srcRect.x = 110;
        srcRect.y = 145;
        srcRect.h = 55;
        destRect.w = srcRect.w = 55;
        //destRect.x = xpos;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos + 30 - 30;
        }
        else
        {
            destRect.x = xpos;
        }
        destRect.y = ypos;
        break;
    case 4:
        srcRect.x = 110;
        srcRect.y = 145;
        destRect.w = srcRect.w = 120;
        if (flip == SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos - 40 - 25;
        }
        else
        {
            destRect.x = xpos;
        }
        srcRect.h = 55;
        //destRect.x = xpos;
        destRect.y = ypos;
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        if (flip==SDL_FLIP_HORIZONTAL)
        {
            destRect.x = xpos + 30 - 30;
        }
        else
        {
            destRect.x = xpos;
        }
        //destRect.x = xpos;
        destRect.y = ypos;
        srcRect.h = 55;
        destRect.w = srcRect.w = 55;
        //attack = false;
        break;
    }
    attackFrame++;
    if (attackFrame % 18 == 0)
    {
        Mix_Chunk* gDamage = Mix_LoadWAV("audio/GokDamage.wav");
        Mix_PlayChannel(-1, gDamage, 0);
        Mix_PlayChannel(-1, gEAttack, 0);
        cout << Enemy::attacks++ << endl;
    }
}

void Saibaman::death(int frame)
{
    switch (frame % 10)
    {
    case 0:
        srcRect.x = 195;
        srcRect.y = 0;
        srcRect.h = destRect.h = 45;
        destRect.w = srcRect.w = 50;
        destRect.x = xpos;
        destRect.y = ypos;
        break;
    case 1:
        break;
    case 2:
        Mix_PlayChannel(-1, gEDamage, 0);
        break;
    case 3:
        srcRect.x = 285;
        srcRect.y = 0;
        srcRect.h = destRect.h = 45;
        destRect.w = srcRect.w = 50;
        destRect.x = xpos;
        destRect.y = ypos;
        break;
    case 4:
        break;
    case 5:
        break;
    }
    deathFrame++;
    if (deathFrame == 10)
    {
        convert = true;
    }
}
