#include "Menu.h"
#include "Selection_menu.h"

Menu::Menu(SDL_Renderer* gRenderer,SDL_Surface* gScreenSurface1,SDL_Window* gWindow1, SDL_Texture* background1,SDL_Texture* quitBg1,LTexture* gTransitionTexture1, LTexture* gSpriteSheetTexture1,LTexture* textSheetTexture1,SDL_Texture* arrow1,SDL_Texture* bg21,SDL_Texture* arrowSelection1,SDL_Texture* transitionBg1,SDL_Texture* controlsImg1,SDL_Texture* controlKeys1,SDL_Texture* CreditsBg1)
{
    //saving the inputs
    cout<<"constructor"<<endl;
    arrowSelection = arrowSelection1;
    transitionBg = transitionBg1;
    controlKeys = controlKeys1;
    controlsImg = controlsImg1;
    arrow =  arrow1;
    textSheetTexture =  textSheetTexture1;
    gSpriteSheetTexture = gSpriteSheetTexture1;
    gWindow = gWindow1;
    background = background1;
    bg2 = bg21;
    quitBg = quitBg1;
    gScreenSurface = gScreenSurface1;
    gTransitionTexture =  gTransitionTexture1;
    CreditsBg = CreditsBg1;

    input = -1; //default main menu
}

int Menu::display( SDL_Renderer* gRenderer)
{
    /**
    -1 = main menu
    0 = selection menu
    1 = load game
    2 = controls
    3 = quit menu
    4 = full quit

    111 = goku
    222 = vegeta
    333 = picolo

    */
    bool quit=false;
    Main_menu M(gRenderer,gScreenSurface,gWindow,background,quitBg, textSheetTexture,controlsImg,controlKeys,gSpriteSheetTexture,gTransitionTexture,arrow,transitionBg,CreditsBg);
    Selection_menu S(gWindow,gSpriteSheetTexture,textSheetTexture,bg2,arrowSelection);
    while(!quit)
    {
        //depending on input
        switch (input)
        {
        case -1:
        {
            cout<<"main menu"<<endl;
            input = M.displayMenu(gRenderer);
            break;
        }
        case 0:
        {
            cout<<"selection menu"<<endl;
            input = S.showFigs(gRenderer);
            break;
        }
        case 1:
        {
            cout<<"load option"<<endl;
            return input; //goes to the game
            break;
        }
        case 2:
        {
            cout<<"controls option"<<endl;
            input = M.controls(gRenderer);
            break;
        }
        case 3:
        {
            cout<<"quit menu"<<endl;
            input = M.quitWindow(1,gRenderer);
            break;
        }
        case 4:
        {
            cout<<"quit option"<<endl;
            quit = true;
            exit(0);
            break;
        }
        case 111:
        case 222:
        case 333:
        {
            cout<<"character chosen"<<endl; ///haris' part
            return input; //goes to the game
            break;
        }
        }
    }
    Menu::close(gWindow);
    return 0; //never returns

}

int Menu::close(SDL_Window* gWindow)
{
    this->~Menu();
    //Destroy window
    SDL_Quit();
    SDL_DestroyWindow( gWindow );
    gRenderer = NULL;
    gWindow = NULL;


    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}

Menu::~Menu()
{
    cout<<"destructor"<<endl;
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

