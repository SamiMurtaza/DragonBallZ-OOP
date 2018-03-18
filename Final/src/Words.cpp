#include"Words.h"
#include<iostream>

using namespace std;

Words::Words()
{
    width = 44;
    height = 48;
}

Words::Words(LTexture* image)
{
    spriteSheetTexture = image;

    x1=940/2;
    y1=788/2;

    this->width = spriteClips.w;
    this->height = spriteClips.h;

    Words::getAlphahbets();
}

Words::~Words()
{
    spriteSheetTexture = NULL;
    delete spriteSheetTexture;
}

void Words::getAlphahbets() //putting every alphabet in array
{
    for (int i=0; i<26; i++)
    {
        spriteClips.x = initX;
        spriteClips.y = initY;
        spriteClips.w = 55;
        spriteClips.h = 75;

        this->width = spriteClips.w;
        this->height = spriteClips.h;

        fillRect = {spriteClips.x,spriteClips.y,spriteClips.w,spriteClips.h};
        Alphabets[i]= fillRect;
        initX = initX + 55;
        if (i==17)
        {
            initY = initY + 76;
            initX = 0;
        }
    }
}

void Words::RenderWord_Play(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,84 - width/2, 304- height/2, &Alphabets[15], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,86 - width/2+33, 304 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,84 - width/2+75, 304 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,84 - width/2+102, 300 - height/2, &Alphabets[24], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

}

void Words::RenderWord_Load(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render(0,90 - width/2+00, 379 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,90 - width/2+23, 379 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,90 - width/2+73, 379 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,90 - width/2+104, 379 - height/2, &Alphabets[3], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_Controls(SDL_Renderer* gRenderer)
{

    spriteSheetTexture->Render( 0,97 - width/2+00, 458 - height/2, &Alphabets[2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+17, 458 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+53, 458 - height/2, &Alphabets[13], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+98, 458 - height/2-4, &Alphabets[19], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+114, 458 - height/2, &Alphabets[17], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+148, 458 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+186, 458 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+225, 458 - height/2-4, &Alphabets[18], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_ControlsHeading(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 3,250 - width/2+8, 90 - height/2, &Alphabets[2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+35, 90 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+93, 90 - height/2, &Alphabets[13], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+166, 90 - height/2-5, &Alphabets[19], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+192, 90 - height/2, &Alphabets[17], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+250, 90 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+315, 90 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,250 - width/2+377, 90 - height/2-4, &Alphabets[18], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_Exit(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,97 - width/2, 538 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+30, 538 - height/2-4, &Alphabets[23], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+59, 538 - height/2, &Alphabets[8], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,97 - width/2+86, 538 - height/2-4, &Alphabets[19], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::Render_AllOptions(SDL_Renderer* gRenderer)
{
    Words::RenderWord_Play( gRenderer);
    Words::RenderWord_Load( gRenderer);
    Words::RenderWord_Controls( gRenderer);
    Words::RenderWord_Exit( gRenderer);
}

void Words::RenderWord_GOKU(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,650 - width/2+00, 718 - height/2, &Alphabets[6], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,650 - width/2+27, 718 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,650 - width/2+65, 718 - height/2, &Alphabets[10], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,650 - width/2+101, 718 - height/2-4, &Alphabets[20], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_VEGETA(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,622 - width/2+00, 718 - height/2-4, &Alphabets[21], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,622 - width/2+29, 718 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,622 - width/2+56, 718 - height/2, &Alphabets[6], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,622 - width/2+92, 718 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,622 - width/2+126, 718 - height/2-4, &Alphabets[19], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,622 - width/2+158, 718 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_PICOLO(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,620 - width/2+00, 718 - height/2, &Alphabets[15], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,620 - width/2+37, 718 - height/2, &Alphabets[8], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render(0, 620 - width/2+62, 718 - height/2, &Alphabets[2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render(0, 620 - width/2+78, 718 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,620 - width/2+116, 718 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,620 - width/2+138, 718 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_ChooseYourCharacter(SDL_Renderer* gRenderer)
{

    spriteSheetTexture->Render( 3,70 - width/2+8, 90 - height/2, &Alphabets[2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,70 - width/2+45, 90 - height/2, &Alphabets[7], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,70 - width/2+82, 90 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,70 - width/2+136, 90 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,70 - width/2+213, 90 - height/2-5, &Alphabets[18], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,70 - width/2+250, 90 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    spriteSheetTexture->Render( 3,220 - width/2+168, 90 - height/2-4, &Alphabets[24], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,220 - width/2+208, 90 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,220 - width/2+282, 90 - height/2-4, &Alphabets[20], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,220 - width/2+310, 90 - height/2, &Alphabets[17], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    spriteSheetTexture->Render( 3,425 - width/2+185, 90 - height/2, &Alphabets[15], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,425 - width/2+241, 90 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,425 - width/2+300, 90 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,425 - width/2+342, 90 - height/2-4, &Alphabets[24], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,425 - width/2+396, 90 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,425 - width/2+423, 90 - height/2, &Alphabets[17], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

}

void Words::RenderWord_GameOver(SDL_Renderer* gRenderer)
{

    spriteSheetTexture->Render( 3,170+60 - width/2+8, 320 - height/2, &Alphabets[6], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,170+60 - width/2+74, 320 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,170+60 - width/2+109, 320 - height/2, &Alphabets[12], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,170+60 - width/2+181, 320 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    spriteSheetTexture->Render( 3,220+60 - width/2+188, 320 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,220+60 - width/2+261, 320 - height/2-4, &Alphabets[21], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,220+60 - width/2+308, 320 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 3,220+60 - width/2+338, 320 - height/2, &Alphabets[17], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

}

void Words::RenderWord_ESC(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 2,30 - width/2, 45 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,30 - width/2+18, 45 - height/2-2, &Alphabets[18], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,30 - width/2+33, 45 - height/2+1, &Alphabets[2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_Mana(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 2,580 - width/2+1,    100 - height/2, &Alphabets[12], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,580 - width/2+27, 100 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,580 - width/2+38, 100 - height/2, &Alphabets[13], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,580 - width/2+64, 100 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_Health(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 2,570 - width/2,    59 - height/2, &Alphabets[7], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,570 - width/2+18, 59 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,570 - width/2+36, 59 - height/2, &Alphabets[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,570 - width/2+48, 59 - height/2, &Alphabets[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,570 - width/2+64, 59 - height/2-2, &Alphabets[19], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 2,570 - width/2+77, 59 - height/2, &Alphabets[7], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_Yes(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,110 - width/2+185, 395 - height/2-4, &Alphabets[24], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,110 - width/2+216, 395 - height/2, &Alphabets[4], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,110 - width/2+248, 395 - height/2-4, &Alphabets[18], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_No(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,425 - width/2+185, 394 - height/2, &Alphabets[13], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,425 - width/2+214, 394 - height/2, &Alphabets[14], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Words::RenderWord_Quit(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( 0,225 - width/2+185, 300 - height/2, &Alphabets[16], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,225 - width/2+232, 300 - height/2-4, &Alphabets[20], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,225 - width/2+257, 300 - height/2, &Alphabets[8], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    spriteSheetTexture->Render( 0,225 - width/2+282, 300 - height/2-4, &Alphabets[19], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

