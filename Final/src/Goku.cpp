#include "Goku.h"
#include "GameObject.h"
#include "Projectile.h"

#include <iostream>
#include <cstdlib>

using namespace std;
Goku::Goku(const char* textureSheet, int x, int y, int R, int G, int B):Character(textureSheet, x, y, R, G, B)
{
    gAttack = Mix_LoadWAV("music/GokuAttack.wav");
	gPower = Mix_LoadWAV("music/GokPow.wav");
	KiAttack= Mix_LoadWAV("audio/ki.wav");

    cout<<"--------------------\n";
}



Goku::~Goku()
{
    delete gAttack;
    delete gPower;
    delete KiAttack;
}

void Goku::InstantTransmission(){

    xpos=xpos+rand()%100;
    ypos=rand()%200;
    this->setMana(this->getMana()-1);
}
void Goku::update(int flag) //idle
{
    if (flag==0)
    {
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.h = 100;
        srcRect.w = 40;
    }
    else if (flag == 1) //power-up

    {
        Mix_PlayChannel(-1,gPower,0);
        srcRect.x = 160;
        srcRect.y = 370;
        srcRect.h = 100;
        srcRect.w = 70;
    }

    else if (flag==2)//punch
    {
        Mix_PlayChannel(-1, gAttack, 0);
        srcRect.x = 500;
        srcRect.y = 0;
        srcRect.h = 100;
        srcRect.w = 60;
    }
    else if (flag==3)//kick
    {
        Mix_PlayChannel(-1, gAttack, 0);
        srcRect.x = 220;
        srcRect.y = 0;
        srcRect.h = 100;
        srcRect.w = 85;
    }
    else if (flag==4)//ki blast
    {
        Mix_PlayChannel(-1, KiAttack, 0);
        srcRect.x = 650;
        srcRect.y = 380;
        srcRect.h = 80;
        srcRect.w = 60;

    }
    else if (flag==5)//right
    {
        srcRect.x = 350;
        srcRect.y = 100;
        srcRect.h = 80;
        srcRect.w = 70;
        if (xpos<1050)
        {
            xpos+=10;
        }
    }
    else if (flag==6)//left
    {
        srcRect.x = 235;
        srcRect.y = 100;
        srcRect.h = 80;
        srcRect.w = 65;
        if (xpos>0)
        {
            xpos-=10;
        }
    }
    else if (flag==7)//down
    {
        srcRect.x = 0;
        srcRect.y = 290;
        srcRect.h = 70;
        srcRect.w = 60;
        //if (ypos<750) ypos+=10;
        //if (xpos<670 && ypos>300){ypos-=10;}
    }
    else if (flag==8)//up
    {
        srcRect.x = 625;
        srcRect.y = 480;
        srcRect.h = 100;
        srcRect.w = 45;
        if (ypos>0)
        {
            ypos-=10;
        }

    }

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*1.8;
    destRect.h = srcRect.h*1.8;
//	frame++;
}
