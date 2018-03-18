#include "Vegeta.h"
#include "GameObject.h"


Vegeta::Vegeta(const char* textureSheet, int x, int y, int R, int G, int B):Character(textureSheet, x, y, R, G, B)
{
    cout<<"xxxxxxxxxxx\n";
}

Vegeta::~Vegeta()
{
    //dtor
}

void Vegeta::update(int flag)
{
    if (flag==0){
        srcRect.y = 210;
        srcRect.h = 100;
        srcRect.w = 40;
    }
    else if (flag == 1) //power-up

    {
        srcRect.x = 430;
        srcRect.y = 90;
        srcRect.h = 115;
        srcRect.w = 70;
    }

    else if (flag==2)//punch
    {
        srcRect.x = 100;
        srcRect.y = 0;
        srcRect.h = 100;
        srcRect.w = 80;
    }
    else if (flag==3)//kick
    {
        srcRect.x = 220;
        srcRect.y = 0;
        srcRect.h = 100;
        srcRect.w = 65;
    }
    else if (flag==4)//ki blast
    {
        srcRect.x = 117;
        srcRect.y = 190;
        srcRect.h = 80;
        srcRect.w = 50;
    }
    else if (flag==-4)//ki blast
    {
        srcRect.x = 854;
        srcRect.y = 365;
        srcRect.h = 80;
        srcRect.w = 70;
    }

    else if (flag==5)//right
    {
        srcRect.x = 290;
        srcRect.y = 92;
        srcRect.h = 80;
        srcRect.w = 70;
        if (xpos<1050){xpos+=10;}
    }
    else if (flag==6)//left
    {
        srcRect.x = 368;
        srcRect.y = 90;
        srcRect.h = 80;
        srcRect.w = 65;
        if (xpos>0){
        xpos-=10;}
    }
    else if (flag==7)//down
    {
        srcRect.x = 0;
        srcRect.y = 92;
        srcRect.h = 70;
        srcRect.w = 60;
      // if (ypos<750) ypos+=10;
       //if (xpos<670 && ypos>300){ypos-=10;}
    }
    else if (flag==8)//up
    {
        srcRect.x = 500;
        srcRect.y = 120;
        srcRect.h = 80;
        srcRect.w = 45;
        if (ypos>0){ypos-=10;}

    }

    else if (flag==-1)//idle2
    {
        srcRect.x = 25;
        srcRect.y = 0;
        srcRect.h = 90;
        srcRect.w = 45;

    }
    else if (flag==-2)//powerup2
    {
        srcRect.x = 920;
        srcRect.y = 360;
        srcRect.h = 90;
        srcRect.w = 65;

    }

    else if (flag==-3)//powerup2
    {
        srcRect.x = 180;
        srcRect.y = 85;
        srcRect.h = 90;
        srcRect.w = 75;
    }

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*1.8;
    destRect.h = srcRect.h*1.8;
//	frame++;
}

