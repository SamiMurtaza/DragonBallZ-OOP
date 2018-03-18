//includes
#include "Main_menu.h"
#include "Words.h"
#include "LTexture.h"
#include <Windows.h>
//#include"MMSystem.h"

//Screen dimension constants
const int SCREEN_WIDTH = 940;
const int SCREEN_HEIGHT = 788;

using namespace std;

Main_menu::Main_menu(SDL_Renderer* gRenderer,SDL_Surface* gScreenSurface1,SDL_Window* gWindow1,SDL_Texture* background1, SDL_Texture* quitBg1,LTexture* textSheetTexture1,SDL_Texture* controlsImg1,SDL_Texture* controlKeys1,LTexture* gSpriteSheetTexture1,LTexture* gTransitionTexture1,SDL_Texture* arrow1,SDL_Texture* transitionBg1,SDL_Texture* CreditsBg1)
{
    Arrow = Mix_LoadWAV("audio/arrow.wav");
    //saving from inputs
    gScreenSurface = gScreenSurface1;
    gWindow = gWindow1;
    background = background1;
    CreditsBg =  CreditsBg1;
    textSheetTexture =  textSheetTexture1;
    controlKeys = controlKeys1;
    gTransitionTexture =  gTransitionTexture1;
    arrow = arrow1;
    transitionBg = transitionBg1;
    quitBg = quitBg1;
    controlsImg = controlsImg1;


    arrowCount = 0;
    input = -1; //default input ie main menu
    showIntroTransition = true; //intro video
}

Main_menu::~Main_menu()
{
    gScreenSurface = NULL;
    gWindow = NULL;
    background = NULL;
    CreditsBg =  NULL;
    textSheetTexture =  NULL;
    controlKeys = NULL;
    gTransitionTexture =  NULL;
    arrow = NULL;
    transitionBg = NULL;
    quitBg = NULL;
    controlsImg = NULL;


}

int Main_menu::displayMenu(  SDL_Renderer* gRenderer)
{
    Words W(textSheetTexture); // creating an instance of Words
    if (showIntroTransition == true)
    {
        Main_menu::showTransition( gRenderer); //showing the transition
    }
    showIntroTransition = false;
    int pos=0;
    bool quit = false;
    //arrow
    Main_menu::setArrow_up(&arrow_y);

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
                return 3;
            }
            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {

                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {

                case SDLK_c:
                case SDLK_d:
                case SDLK_p:
                    Main_menu::showCredits(gRenderer); //for programmers
                    break;

                case SDLK_DOWN:
                case SDLK_RIGHT:

                    if ((arrowCount<3)&&(pos<3))
                    {
                        pos++;
                        arrowCount++;
                        Main_menu::moveArrow_down(&arrow_y); //change y coordinate
                    }
                    else
                    {
                        Main_menu::setArrow_up(&arrow_y);//change y coordinate
                        arrowCount=0;
                        pos=0;
                    }
                    Mix_PlayChannel(-1, Arrow, 0);
                    //  PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC); //audio
                    break;

                case SDLK_UP:
                case SDLK_LEFT:
                    if (pos>0)
                    {
                        pos--;
                        arrowCount--;
                        Main_menu::moveArrow_up(&arrow_y);//change y coordinate
                    }
                    else
                    {

                        Main_menu::setArrow_down(&arrow_y);//change y coordinate
                        arrowCount=3;
                        pos=3;
                    }
                    Mix_PlayChannel(-1, Arrow, 0);
                    // PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    break;

                case SDLK_RETURN:
                case SDLK_SPACE: //select
                    Mix_PlayChannel(-1, Arrow, 0);
                    //  PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    cout<<"pos = "<<pos<<endl;
                    return pos;
                    break;
                }
            }
        }

        //rendering
        SDL_RenderCopy(gRenderer, background, NULL, NULL); //render background
        SDL_RenderCopy(gRenderer, arrow, NULL, &menuArrow); //render arrow
        W.Render_AllOptions(gRenderer); //render text
        SDL_RenderPresent( gRenderer );

    }
    return 0; //never returns
}

int Main_menu::controls(SDL_Renderer* gRenderer)
{
    Words W(textSheetTexture);

    //for size of keys


    bool quit = false;
    while (quit==false)
    {

        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press

                switch( e.key.keysym.sym )
                {

                case SDLK_BACKSPACE:
                case SDLK_ESCAPE: //alternate key
                    Mix_PlayChannel(-1, Arrow, 0);
                    //  PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);

                    return -1;
                    break;
                }
            }
        }


        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen/ set background color
        SDL_RenderClear( gRenderer );

        //rendering the surface
        SDL_RenderCopy(gRenderer, controlsImg, NULL, NULL); //render background
        W.RenderWord_ControlsHeading(gRenderer);
        ///SDL_RenderCopy(gRenderer,&controlKeys[0], NULL, &keysSize); //render background
        SDL_RenderPresent( gRenderer );
    }
    return 0;
}

void Main_menu::moveArrow_down(int *arrow_y)
{
    *arrow_y = *arrow_y + 75;
    menuArrow.x = 10;
    menuArrow.y = *arrow_y;
    menuArrow.w = 70;
    menuArrow.h = 70;
}

void Main_menu::moveArrow_up(int *arrow_y)
{
    *arrow_y = *arrow_y - 75;
    menuArrow.x = 10;
    menuArrow.y = *arrow_y;
    menuArrow.w = 70;
    menuArrow.h = 70;
}

void Main_menu::setArrow_up(int *arrow_y)
{
    *arrow_y = 273;
    menuArrow.x = 10;
    menuArrow.y = *arrow_y;
    menuArrow.w = 70;
    menuArrow.h = 70;
}

void Main_menu::setArrow_down(int *arrow_y)
{
    *arrow_y = 504;
    menuArrow.x = 10;
    menuArrow.y = *arrow_y;
    menuArrow.w = 70;
    menuArrow.h = 70;
}

void Main_menu::showTransition( SDL_Renderer* gRenderer)
{

    //PlaySound(TEXT("audio/intro.wav"),NULL,SND_FILENAME|SND_ASYNC); //intro music
    long int frame = 0;
    int count = 0;
    int quitCount = 0;
    int transparency  = 0;
    bool inBool = true;

    //setting the coods of the front rendering image [logo]
    SDL_Rect spriteClips;

    spriteSheetTexture = gTransitionTexture;
    spriteClips.x = 0;
    spriteClips.y = 0;
    spriteClips.w = 854;
    spriteClips.h = 255;


    for (int i = 0; i<253 ; i++)                         //While application is running
    {
        if ((transparency<255)&&(inBool == true))
        {
            transparency =transparency+2 ;
            if (transparency ==254)
            {
                inBool = false;
            }
        }
        if ((inBool == false))
        {
            transparency=transparency-2  ;
        }
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen/ set background color
        SDL_RenderClear( gRenderer );

        SDL_RenderCopy(gRenderer, transitionBg, NULL, NULL); //renders background
        spriteSheetTexture->RenderTransition( 40, 240, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer,transparency); //render front

        SDL_RenderPresent( gRenderer );     //Update screen
        count++;
        quitCount++;

        if (count==2) //adjust the frame rate
        {
            count  = 0;
            ++frame;
        }
    }
}

int Main_menu::quitWindow(bool mainMenuBool,SDL_Renderer* gRenderer) //'mainMenuBool' tell if we will return to the game or main menu
{
    bool quit = false;
    int pos = 0; //position of arrow
    Words W(textSheetTexture);

    //for background image
    SDL_Rect quitScreenSize;
    quitScreenSize.x = 155+50;
    quitScreenSize.y = 197+40;
    quitScreenSize.w = 640/1.2;
    quitScreenSize.h = 360/1.2;

    //for arrow
    SDL_Rect quitArrow;
    quitArrow.x = 215; //default x
    quitArrow.y = 365;
    quitArrow.w = 60;
    quitArrow.h = 60;

    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit

            if( e.type == SDL_QUIT )
            {
                quit = true;
                return 3;
            }
            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {

                case SDLK_RIGHT:
                case SDLK_UP :
                    if (pos == 0)
                    {
                        pos = 1;
                        quitArrow.x = 530;
                    }
                    else if (pos == 1)
                    {
                        pos=0;
                        quitArrow.x = 215;
                    }
                    Mix_PlayChannel(-1, Arrow, 0);
                    // PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    break;

                case SDLK_LEFT:
                case SDLK_DOWN:
                    if (pos == 0)
                    {
                        pos++;
                        quitArrow.x = 530;
                    }
                    else if (pos == 1)
                    {
                        pos--;
                        quitArrow.x = 215;
                    }
                    Mix_PlayChannel(-1, Arrow, 0);
                    //   PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    break;

                case SDLK_RETURN:
                case SDLK_SPACE:
                    if ((pos==0)&&(mainMenuBool==1)) //yes
                    {
                        return 4;
                    }
                    else if ((pos==1)&&(mainMenuBool==1)) //no
                    {
                        return -1;
                    }
                    else if ((pos==0)&&(mainMenuBool==0)) //yes
                    {
                        return -11;
                    }
                    else if ((pos==1)&&(mainMenuBool==0)) //no
                    {
                        return -123; ///for haris
                    }
                    Mix_PlayChannel(-1, Arrow, 0);
                    //  PlaySound(TEXT("audio/arrow.wav"),NULL,SND_FILENAME|SND_ASYNC);
                    break;


                }
            }
        }

        //rendering
        SDL_RenderCopy(gRenderer, quitBg, NULL, &quitScreenSize); //render right arrow
        W.RenderWord_Yes(gRenderer);
        W.RenderWord_No(gRenderer);
        W.RenderWord_Quit(gRenderer);
        SDL_RenderCopy(gRenderer, arrow, NULL, &quitArrow); //render arrow
        SDL_RenderPresent( gRenderer );
    }
    return 0; //never returns
}

void Main_menu::showCredits( SDL_Renderer* gRenderer)
{
    SDL_RenderCopy(gRenderer, CreditsBg, NULL, NULL); //render right arrow
    SDL_RenderPresent(gRenderer);
    Sleep(2000); //time delay
}
