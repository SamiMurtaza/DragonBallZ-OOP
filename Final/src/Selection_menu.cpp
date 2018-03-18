#include <SDL.h>
#include "Selection_menu.h"
#include "ShowCharacter.h"

using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 940;
const int SCREEN_HEIGHT = 788;

Selection_menu::Selection_menu(SDL_Window* gWindow1,LTexture* gSpriteSheetTexture1,LTexture* textSheetTexture1,SDL_Texture* backgroundSelection1,SDL_Texture* arrowSelection1)
{
    arrow = Mix_LoadWAV("audio/arrow.wav");
    //saving inputs
    gWindow = gWindow1;
    gSpriteSheetTexture = gSpriteSheetTexture1;
    textSheetTexture = textSheetTexture1;
    backgroundSelection = backgroundSelection1;
    arrowSelection = arrowSelection1;

    //default character number
    characterNumber=0;

    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;

    characterRect.x = 300;
    characterRect.y = 300;
    characterRect.w = SCREEN_WIDTH/3;
    characterRect.h = SCREEN_HEIGHT/3;
}

int Selection_menu::showFigs( SDL_Renderer* gRenderer) //displays all the characters
{
    int characterReturnNumber = 0;
    int xRight=570;
    int xLeft=170;

    //for right arrow
    SDL_Rect SelectionArrow_r;
    SelectionArrow_r.x = xRight;
    SelectionArrow_r.y = 788/2;
    SelectionArrow_r.w = 170;
    SelectionArrow_r.h = 170;

    //for left arrow
    SDL_Rect SelectionArrow_l;
    SelectionArrow_l.x = 940/2 -300;
    SelectionArrow_l.y = 788/2+4;
    SelectionArrow_l.w = 170;
    SelectionArrow_l.h = 170;

    bool quit = false;                      //Main loop flag

    SDL_Event e;                            //Event handler

    long int frame = 0;                     //Current animation frame

    /* initialize random seed: */
    srand (time(NULL));
    Words W_S(textSheetTexture); //for displaying words

    ShowCharacter* character1 = new ShowCharacter(gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);

    int frameRate = 0;

    while( !quit )                          //While application is running
    {
        if(frame%2 == 0)
        {
            //random = rand() % SCREEN_WIDTH;
        }
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }

            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                case SDLK_RIGHT:
                    //    PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    Mix_PlayChannel(-1, arrow, 0);
                    Selection_menu::changeCharacter();
                    break;

                case SDLK_LEFT:
                    Mix_PlayChannel(-1, arrow, 0);
                    //    PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    Selection_menu::changeCharacter();
                    break;

                case SDLK_ESCAPE:
                    quit = true;
                    break;

                case SDLK_BACKSPACE:
                    //        PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    quit = true;
                    break;

                case SDLK_RETURN:
                    //       PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    quit = true;
                    if (Selection_menu::characterNumber == 0)
                    {
                        cout<<"goku"<<endl;
                        characterReturnNumber=111;
                    }
                    else if (Selection_menu::characterNumber == 1)
                    {
                        cout<<"vegeta"<<endl;
                        characterReturnNumber=222;
                    }
                    else if (Selection_menu::characterNumber == 2)
                    {
                        cout<<"picolo"<<endl;
                        characterReturnNumber=333;
                    }
                    return characterReturnNumber; //forwards a character number
                    break;

                }
            }
        }

        SelectionArrow_r.x = xRight; //changing x coods for right arrow
        SelectionArrow_l.x = xLeft;//changing x coods for left arrow

        //rendering
        SDL_RenderCopy(gRenderer, backgroundSelection, NULL, NULL); //render background
        SDL_RenderCopy(gRenderer, arrowSelection, NULL, &SelectionArrow_r); //render right arrow
        SDL_RenderCopyEx( gRenderer, arrowSelection, NULL, &SelectionArrow_l, 180, NULL, SDL_FLIP_NONE ); //render left arrow
        character1->Render(frame, gRenderer,Selection_menu::getCharacterNo()); //renders player

        //for movement of selection arrows
        //right arrow
        if (xRight<600)
        {
            xRight++;
        }
        if (xRight==599)
        {
            xRight=570;
        }
        //left arrow
        if (xLeft>140)
        {
            xLeft--;
        }
        if (xLeft==141)
        {
            xLeft=170;
        }

        //rendering words
        W_S.RenderWord_ChooseYourCharacter(gRenderer);
        W_S.RenderWord_ESC(gRenderer);

        //showing character name
        if ( Selection_menu::getCharacterNo()==0)
        {
            W_S.RenderWord_GOKU(gRenderer);
        }
        else if ( Selection_menu::getCharacterNo()==1)
        {
            W_S.RenderWord_VEGETA(gRenderer);
        }
        else if ( Selection_menu::getCharacterNo()==2)
        {
            W_S.RenderWord_PICOLO(gRenderer);
        }

        SDL_RenderPresent( gRenderer );     //Update screen
        frameRate++;

        if (frameRate==9) //adjust the frame rate
        {
            frameRate  = 0;
            ++frame;
        }
        //Go to next frame
    }
    return -1;
}

void Selection_menu::changeCharacter()
{
    if (characterNumber ==0)
    {
        characterNumber = 1;
    }
    else if (characterNumber ==2)
    {
        characterNumber = 0;
    }
    else
    {
        characterNumber = characterNumber+1;
    }
}

int Selection_menu::getCharacterNo()
{
    return characterNumber;
}

Selection_menu::~Selection_menu()
{
    gWindow = NULL;
    gSpriteSheetTexture = NULL;
    textSheetTexture = NULL;
    backgroundSelection = NULL;
    arrowSelection = NULL;

}
