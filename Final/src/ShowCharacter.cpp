#include "ShowCharacter.h"

ShowCharacter::ShowCharacter()
{
    widthT=470;
    heightT = 180;
    characterNumber=0;

}

ShowCharacter::ShowCharacter(LTexture* image, float x1, float y1)
{
    //all three characters
    spriteSheetTexture1 = &image[0];
    spriteSheetTexture2 = &image[1];
    spriteSheetTexture3 = &image[2];

    //transition
    spriteSheetTexture = &image[2];

    x2=x1;
    y2=y1;
    xT=x1;
    yT=y1;

    //for player 1
    int initx=4;// initial x
    for (int i=0; i<15; i++)
    {
        spriteClips1[ i ].x =   initx;
        spriteClips1[ i ].y =   4585;
        spriteClips1[ i ].w = 132.5;
        spriteClips1[ i ].h = 152;
        initx=initx+138;
    }

    //for player 2
    int initx1=3;// initial x
    for (int i=0; i<9; i++)
    {
        spriteClips2[ i ].x =   initx1;
        spriteClips2[ i ].y =   3666;
        spriteClips2[ i ].w = 124;
        spriteClips2[ i ].h = 126;
        initx1=initx1+127;
    }

    //for player 3
    int initx2=2;// initial x
    for (int i=0; i<7; i++)
    {
        spriteClips3[ i ].x =   initx2;
        spriteClips3[ i ].y =   3597;
        spriteClips3[ i ].w = 193;
        spriteClips3[ i ].h = 170;
        initx2=initx2+195;
    }

    //for intro transition
    spriteTransition[ 0 ].x = 0;
    spriteTransition[ 0 ].y = 0;
    spriteTransition[ 0 ].w = 1854;
    spriteTransition[ 0 ].h = 1155;

    //for character 1
    this->x1 = x1;
    this->y1 = y1;

    this->width1 = spriteClips1[ 0 ].w;
    this->height1 = spriteClips1[ 0 ].h;

    //for character 2
    this->x2 = x2;
    this->y2 = y2;

    this->width2 = spriteClips2[ 0 ].w;
    this->height2 = spriteClips2[ 0 ].h;

    //for character 3
    this->x3 = x3;
    this->y3 = y3;

    this->width3 = spriteClips3[ 0 ].w;
    this->height3 = spriteClips3[ 0 ].h;

    //for transition
    this->xT = xT;
    this->yT = yT;

    this->widthT = spriteTransition[ 0 ].w;
    this->heightT = spriteTransition[ 0 ].h;

}

ShowCharacter::~ShowCharacter()
{
    spriteSheetTexture1 = NULL;
    spriteSheetTexture2 = NULL;
    spriteSheetTexture3 = NULL;

    spriteSheetTexture = NULL;
}

void ShowCharacter::Render(long int& frame, SDL_Renderer* gRenderer, int characterNumber) //renders the character based on characterNumber
{
    if (characterNumber==0)
    {

        spriteSheetTexture1->Render( true, x1 - width1/2-80, 430, &spriteClips1[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }

    if (characterNumber==1)
    {
        spriteSheetTexture2->Render( true, x2 - width2/2-80,430+20, &spriteClips2[ frame % FLYING_FRAMES1 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }

    if (characterNumber==2)
    {
        spriteSheetTexture3->Render( true,x2 - width2/2 -125, 430 - 20, &spriteClips3[ frame % FLYING_FRAMES2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}

void ShowCharacter::RenderTransition(long int& frame, SDL_Renderer* gRenderer, int transparency) //for rendering intro screen
{
    spriteSheetTexture3->Render( true,x2 - width2/2 -125, 430 - 20, &spriteClips3[ frame % FLYING_FRAMES2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}





