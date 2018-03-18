#include "Picolo.h"
#include "GameObject.h"


Picolo::Picolo(const char* textureSheet, int x, int y, int R, int G, int B):Character(textureSheet, x, y, R, G, B)
{
    gAttack = Mix_LoadWAV("audio/Pic0.wav");
    gPower = Mix_LoadWAV("audio/Pic10.wav");
    KiAttack= Mix_LoadWAV("audio/Pic4.wav");
    cout<<"xxxxxxxxxxx\n";
}



Picolo::~Picolo()
{
    delete gAttack;
    delete gPower;
    delete KiAttack;
}
void Picolo::update(int flag)
{
    if (flag==0)
    {
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.h = 105;
        srcRect.w = 70;
    }
    else if (flag == 1) //power-up

    {
        Mix_PlayChannel(-1,gAttack,0);
        srcRect.x = 880;
        srcRect.y = 25;
        srcRect.h = 80;
        srcRect.w = 90;
    }

    else if (flag==2)//punch
    {
        Mix_PlayChannel(-1,gAttack,0);
        srcRect.x = 190;
        srcRect.y = 135;
        srcRect.h = 100;
        srcRect.w = 90;
    }
    else if (flag==3)//kick
    {
        Mix_PlayChannel(-1,gPower,0);
        srcRect.x = 660;
        srcRect.y = 120;
        srcRect.h = 100;
        srcRect.w = 100;
    }
    else if (flag==4)//ki blast
    {
        Mix_PlayChannel(-1,KiAttack,0);
        srcRect.x = 735;
        srcRect.y = 375;
        srcRect.h = 80;
        srcRect.w = 90;
    }
    else if (flag==5)//right
    {
        srcRect.x = 510;
        srcRect.y = 255;
        srcRect.h = 80;
        srcRect.w = 90;
        if (xpos<1050)
        {
            xpos+=10;
        }
    }
    else if (flag==6)//left
    {
        srcRect.x = 0;
        srcRect.y = 360;
        srcRect.h = 80;
        srcRect.w = 65;
        if (xpos>0)
        {
            xpos-=10;
        }
    }
    else if (flag==7)//down
    {
        srcRect.x = 900;
        srcRect.y = 510;
        srcRect.h = 80;
        srcRect.w = 65;
        //if (ypos<750) ypos+=10;
        //if (xpos<670 && ypos>300){ypos-=10;}
    }
    else if (flag==8)//up
    {
        srcRect.x = 290;
        srcRect.y = 240;
        srcRect.h = 80;
        srcRect.w = 65;
        if (ypos>0)
        {
            ypos-=10;
        }

    }


    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*2.5;
    destRect.h = srcRect.h*2.5;
//	frame++;
}

void Picolo::Regenerate()
{
    this->setMana(this->getMana()-1);
    this->setHealth(this->getHealth()+2);
}
