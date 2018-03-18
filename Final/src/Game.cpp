#include"Game.h"
#include"TextureManager.h"
#include"Menu.h"
#include<stdio.h>
#include "SDL_mixer.h"
#include "Game.h"
#include "Words.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Saibaman.h"
#include "Goku.h"
#include "Vegeta.h"
#include "Picolo.h"
#include "Health.h"
#include "Projectile.h"
#include "ObjectFactory.h"
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <sstream>

/*int stoi(string s)
{
   // string s = "12345";

    // object from the class stringstream
    stringstream geek(s);

    // The object has the value 12345 and stream
    // it to the integer x
    int x;
    geek >> x;

    // Now the variable x holds the value 12345
//    cout << "Value of x : " << x;

    return x;
}*/




ObjectFactory* all=NULL;
Character* Gamer  = NULL;
Health* healthBar;
SDL_Renderer* Game::renderer = NULL;
Projectile* p=new Projectile("images/ki1.png", 0, 0, 125, 125, 125);

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscrn)
{
//constructor

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 20480) < 0)//(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 20000) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        //			success = false;
    }
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );

    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        window = SDL_CreateWindow( "Dragon Ball Adventures", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALWAYS_ON_TOP);
        if( window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );

        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( window );

            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );

            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );

                }
            }
        }
    }

    surfaces[0].x =0 ;
    surfaces[0].y = 430;
    surfaces[0].w = 600;
    surfaces[0].h = 400;

    surfaces[1].x =600 ;
    surfaces[1].y = 500;
    surfaces[1].w = 570;
    surfaces[1].h = 250;

    safeSurfaces[0].x =550 ;
    safeSurfaces[0].y = 450;
    safeSurfaces[0].w = 70;
    safeSurfaces[0].h = 50;

    all = new ObjectFactory();
    gBall = Mix_LoadWAV("music/ball.wav");
//	all = new ObjectFactory(load);
    //return success;
}

void Game::loadMedia()
{
    music = Mix_LoadMUS( "music/ULTRA.wav" );

    bg1  = TextureManager::LoadTexture("images/background.png",renderer); //main menu background
    if (bg1 == NULL)
    {
        printf( "Failed to load background image!\n" );

    }

    bg2  = TextureManager::LoadTexture("images/bg2.png",renderer); //selection menu background
    if (bg2 == NULL)
    {
        printf( "Failed to load selection background image!\n" );

    }

    controlsImg  = TextureManager::LoadTexture("images/controls1.jpg",renderer); //controls image
    if (controlsImg == NULL)
    {
        printf( "Failed to load rules image!\n" );

    }

    //Load arrow
    arrow  = TextureManager::LoadTexture("images/arrow.png",renderer);
    if (arrow == NULL)
    {
        printf( "Failed to load arrow image!\n" );

    }

    //Load arrow
    CreditsBg  = TextureManager::LoadTexture("images/credits1.jpg",renderer);
    if (CreditsBg == NULL)
    {
        printf( "Failed to load credits image!\n" );

    }

    //Load Selection arrow
    arrowSelection  = TextureManager::LoadTexture("images/arrowSelection.png",renderer);
    if (arrowSelection == NULL)
    {
        printf( "Failed to load arrowSelection image!\n" );

    }

    //Load key 1
    controlKeys[0]  = TextureManager::LoadTexture("images/wasd.png",renderer);
    if (controlKeys[0] == NULL)
    {
        printf( "Failed to load keys controls image!\n" );

    }
    //Load key 2
    controlKeys[1]  = TextureManager::LoadTexture("images/credits.jpg",renderer);
    if (controlKeys[1] == NULL)
    {
        printf( "Failed to load keys credits image!\n" );

    }

    //Load Selection arrow
    transitionBg  = TextureManager::LoadTexture("images/transitionBackground1.jpg",renderer);
    if (transitionBg == NULL)
    {
        printf( "Failed to load transitionBackground1 image!\n" );

    }

    //Load quit background
    quitBg  = TextureManager::LoadTexture("images/quitBackground.jpg",renderer);
    if (transitionBg == NULL)
    {
        printf( "Failed to quit background image!\n" );

    }

    //character sprites
    if( !gSpriteSheetTexture[0].LoadFromFile( "images/goku.png", renderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );

    }

    if( !gSpriteSheetTexture[1].LoadFromFile( "images/vegeta.png", renderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );

    }

    if( !gSpriteSheetTexture[2].LoadFromFile( "images/picolo.png", renderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );

    }

    if( !gTransitionTexture.LoadFromFile( "images/logo.png", renderer  ) ) //transition front
    {
        printf( "Failed to load sprite sheet texture!\n" );

    }

    if( !gTransitionbackground.LoadFromFile( "images/transitionBackground1.jpg", renderer  ) ) //transition background
    {
        printf( "Failed to load sprite sheet texture!\n" );

    }

    if( !textSheetTexture.LoadFromFile( "images/fontSprite1.png", renderer  ) ) //text sprite
    {
        printf( "Failed to load sprite sheet texture!\n" );

    }

}

int &Game::startGame()//return by reference because i am using "sel" elsewhere as well for loading
{
//   int sel;
    vector <string> loading;
    ifstream load("Save.txt");
    int i = 0;
    if (!load)
    {
        cout << 123;
    }
//loads previously save game text file
    while (load)
    {
        string strInput;
        load >> strInput;
        loading.resize(loading.size() + 1);
        loading[i++] = strInput;
        cout << strInput << endl;
    }
    cout << endl << loading.size() << endl;
//creates an instance MM for menu
    Menu MM(renderer,gScreenSurface,window,bg1,quitBg,&gTransitionTexture,gSpriteSheetTexture, &textSheetTexture,arrow,bg2,arrowSelection,transitionBg,controlsImg,*controlKeys,CreditsBg);
    sel =  MM.display(renderer);//selects to load or not to.
    if (sel==1)
    {

        Game::init("Dragon Ball Adventures", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  940,  780,  true,  loading);
    }
    else
    {
        Game::init("Dragon Ball Adventures", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  940,  780,  true,  sel);
    }
//
    return sel;
}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscrn, int sel)
{
    //makes a new game
    isRunning=true;
    cout<<"im here\n";

    bg = TextureManager::LoadTexture("images/map2.png");
    cout<<"load\n";

    if (sel==111)
    {
        //Gamer= (Goku*) Gamer;
        Gamer= new Goku("images/g0.png", 0, 200, 150, 150, 150);
    }
    else if (sel==222)
    {
        //Gamer= (Vegeta*) Gamer;
        Gamer= new Vegeta("images/v0.png", 0, 200, 0, 0, 0);
    }
    else if (sel==333)
    {
        //Gamer= (Picolo*) Gamer;
        Gamer= new Picolo("images/p1.png", 0, 200, 0, 0, 0);
    }
    if (Gamer==NULL) ///nullptr
    {
        cout<<"didnt load\n";
    }

    all = new ObjectFactory();
    camera.x = 0;
    camera.y =110;
    alive = true;
    healthBar = new Health();
    Enemy::attacks = 0;
    p->update(0);
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscrn, vector <string> load)
{
    //overloaded function for loading a previously saved game
    isRunning=true;
    alive = true;
    cout<<"im here\n";

    bg = TextureManager::LoadTexture("map.png");
    cout<<"load\n";

    sel = stoi(load[0]);
    cout<<"the value of selection is: "<<sel<<endl<<endl<<endl;
    if (sel==111)
    {
        Gamer= new Goku("g0.png", stoi(load[3]), stoi(load[4]), 150, 150, 150);
    }
    else if (sel==222)
    {
        Gamer= new Vegeta("v0.png", stoi(load[3]), stoi(load[4]), 0, 0, 0);
    }
    else if (sel==333)
    {
        Gamer= new Picolo("p1.png", stoi(load[3]), stoi(load[4]), 0, 0, 0);
    }

    all = new ObjectFactory(load);
    camera.x = stoi(load[1]);
    camera.y = stoi(load[2]);
    Enemy::attacks = stoi(load[5]);
    p->update(0);
}


void Game::handleEvents()
{
    //if (Gamer == NULL) {exit(0);}

    if (Mix_PausedMusic() == 1)
    {
        //Resume the music
        Mix_ResumeMusic();
    }
    if (all->getErased().size() >= 50)
    {
        cout<<"YOU WIN!!\n";
        Words W(&textSheetTexture);
        W.RenderWord_GameOver(renderer);
        SDL_RenderPresent(renderer);
        Sleep(3000); //time delay
        //isRunning = false;
        alive=false; //death of player, so don't save this moment
        if (Mix_PausedMusic() == 0)
        {
            Mix_PauseMusic();
        }
        Game::startGame();
    }
    if (Enemy::attacks > 8)
    {
        Enemy::attacks = 8;   //if health not in bounds make it in bounds
    }
    if (Enemy::attacks < 0)
    {
        Enemy::attacks = 0;
    }

    if (Mix_PlayingMusic() == 0)
    {
        //Play the music
        Mix_PlayMusic(music, -1);
    }

    if (!SDL_HasIntersection(Gamer->getDRect(),&surfaces[0])&& !SDL_HasIntersection(Gamer->getDRect(),&surfaces[1])
            && !SDL_HasIntersection(Gamer->getDRect(),&surfaces[2]) && !SDL_HasIntersection(Gamer->getDRect(),&surfaces[3])&& !SDL_HasIntersection(Gamer->getDRect(),&surfaces[4]))
    {
        Gamer->setY(Gamer->getY()+1);
    }

    if (SDL_HasIntersection(Gamer->getDRect(), &safeSurfaces[1]))
    {
        Gamer->setX((Gamer->getX())-10);
    }

    if (SDL_HasIntersection(Gamer->getDRect(), &safeSurfaces[2]))
    {
        Gamer->setX((Gamer->getX())-10);
    }


    if (SDL_HasIntersection(Gamer->getDRect(), &safeSurfaces[0]))
    {
        Gamer->setX((Gamer->getX())+10);
    }

    if (SDL_HasIntersection(Gamer->getDRect(), &safeSurfaces[3]))
    {
        Gamer->setX((Gamer->getX())+10);
    }

    if (SDL_HasIntersection(Gamer->getDRect(), &safeSurfaces[4]))
    {
        Gamer->setX((Gamer->getX())+10);
    }



    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;


    default:
        break;
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (!currentKeyStates[SDL_SCANCODE_LSHIFT])
    {
        kam=false;
    }

    if (currentKeyStates[SDL_SCANCODE_Q])
    {

        Gamer->powerUP();
        if (ss)
        {
            Gamer->update(-2);
        }
        else
        {
            Gamer->update(1);
        }

        ma+=0.05;
        if (ma>3.0 && Gamer->getMana()<8)
        {
            ma=0;
            Gamer->addMana();
        }
    }

    else if (currentKeyStates[SDL_SCANCODE_0])
    {
        //If the music is paused
        if (Mix_PausedMusic() == 1)
        {
            //Resume the music
            Mix_ResumeMusic();
        }
        //If the music is playing
        else
        {
            //Pause the music
            Mix_PauseMusic();
        }
    }
    else if(currentKeyStates[SDL_SCANCODE_LCTRL])
    {


        for (unsigned int i = 0; i < all->getList().size(); i++)
        {
            if (SDL_HasIntersection(Gamer->getDRect(), all->getList()[i]->getDRect()))
            {
                all->getList()[i]->dead = true;
            }
        }

        if (ss)
        {
            Gamer->update(-3);
        }
        else
        {
            Gamer->update(2);
        }
    }

    else if(currentKeyStates[SDL_SCANCODE_T])
    {
        if (ss)
        {
            return;
        }


        if (sel==222 && Gamer->getMana()==8)
        {
            ss=true;
            Gamer= new Vegeta("images/vss.png",Gamer->getY(), Gamer->getY(), 255, 0, 255);
        }
    }


    else if(currentKeyStates[SDL_SCANCODE_LALT])
    {


        for (unsigned int i = 0; i < all->getList().size(); i++)
        {
            if (SDL_HasIntersection(Gamer->getDRect(), all->getList()[i]->getDRect()))
            {
                all->getList()[i]->dead = true;
            }
        }

        Gamer->update(3);
    }
    else if(currentKeyStates[SDL_SCANCODE_F])
    {
        cout<<sel<<endl;
        if (sel==111 && Gamer->getMana()>0)
        {
            Gamer->InstantTransmission();
        }
        else if (sel==333 && Gamer->getMana()>0)
        {
            Gamer->Regenerate();
            Enemy::attacks-=1;
        }
    }
    else if(currentKeyStates[SDL_SCANCODE_E])
    {
        if (Gamer->getMana()>0)
        {

            Gamer->kiBlast();

            if (!kam)
            {
                kam=true;
                attlen+=1;
                if (attlen>3.0 && Gamer->getMana()<9)
                {
                    attlen=0;
                    Gamer->setMana(Gamer->getMana()-1);
                }
                if  (ss)
                {
                    Gamer->update(-4);
                }
                else
                {
                    Gamer->update(4);
                }

            }
            //attlen=0;
        }
    }

    else if((currentKeyStates[SDL_SCANCODE_D])||(currentKeyStates[SDL_SCANCODE_RIGHT]))
    {


        if (camera.x==60)
        {
            surfaces[2].x =930 ;
            surfaces[2].y = 440;
            surfaces[2].w = 120;
            surfaces[2].h = 450;

            safeSurfaces[1].x =900 ;
            safeSurfaces[1].y = 450;
            safeSurfaces[1].w = 30;
            safeSurfaces[1].h = 60;

            safeSurfaces[2].x =1030 ;
            safeSurfaces[2].y = 250;
            safeSurfaces[2].w = 30;
            safeSurfaces[2].h = 250;
        }

        if (camera.x==90)
        {
            surfaces[3].x =930 ;
            surfaces[3].y = 300;
            surfaces[3].w = 220;
            surfaces[3].h = 450;

            safeSurfaces[3].x =1150 ;
            safeSurfaces[3].y = 300;
            safeSurfaces[3].w = 30;
            safeSurfaces[3].h = 450;
        }

        if (camera.x==150)
        {
            surfaces[4].x =1200 ;
            surfaces[4].y = 300;
            surfaces[4].w = 1020;
            surfaces[4].h = 550;

        }


        Gamer->update(5);
        if (Gamer->getX()>500 && camera.x<450)
        {
            camera.x+=5;
            all->setBalls(-10,0);//balls do not move with the screen
            surfaces[0].x-=20;
            surfaces[1].x-=20;
            surfaces[2].x-=20;
            surfaces[3].x-=20;
            surfaces[4].x-=20;
            safeSurfaces[0].x -=20 ;
            safeSurfaces[1].x -=20 ;
            safeSurfaces[2].x -=20 ;
            safeSurfaces[3].x -=20 ;
        }




    }
    else if((currentKeyStates[SDL_SCANCODE_A])||(currentKeyStates[SDL_SCANCODE_LEFT]))
    {
        Gamer->update(6);
    }
    else if((currentKeyStates[SDL_SCANCODE_S])||(currentKeyStates[SDL_SCANCODE_DOWN]))
    {
        Gamer->update(7);


        Gamer->update(7);
        if (!SDL_HasIntersection(Gamer->getDRect(),&surfaces[0])&& !SDL_HasIntersection(Gamer->getDRect(),&surfaces[1])
                && !SDL_HasIntersection(Gamer->getDRect(),&surfaces[2]) && !SDL_HasIntersection(Gamer->getDRect(),&surfaces[3])&& !SDL_HasIntersection(Gamer->getDRect(),&surfaces[4]))
        {
            Gamer->setY(Gamer->getY()+10);
        }


    }
    else if((currentKeyStates[SDL_SCANCODE_W])||(currentKeyStates[SDL_SCANCODE_UP]))
    {
        Gamer->update(8);
    }
    else if(currentKeyStates[SDL_SCANCODE_P])
    {
        cout<<Gamer->getX()<<"   "<<Gamer->getY()<<"+++++"<<camera.x<<"     "<<camera.y<<endl;
    }
    else if (Enemy::attacks >= 8)
    {
        Words W(&textSheetTexture);
        W.RenderWord_GameOver(renderer);
        SDL_RenderPresent(renderer);
        Sleep(3000); //time delay
        //isRunning = false;
        alive=false; //death of player, so don't save this moment
        if (Mix_PausedMusic() == 0)
        {
            Mix_PauseMusic();
        }
        Game::startGame();
    }
    else if (currentKeyStates[SDL_SCANCODE_ESCAPE])
    {
        cout<<"game paused"<<endl;
        int input1;
        Main_menu M(renderer,gScreenSurface,window,bg1,quitBg, &textSheetTexture,controlsImg,*controlKeys,gSpriteSheetTexture,&gTransitionTexture,arrow,transitionBg,CreditsBg);
        input1 = M.quitWindow(false,renderer);
        if (input1==-11)
        {

//saves the game

            ofstream save("Save.txt");
            isRunning = false;
            cout << "saving"<<endl;
            save << sel << endl;
            save << camera.x << endl << camera.y << endl;
            save << Gamer->getX() << endl << Gamer->getY() << endl;
            save << Enemy::attacks << endl;
            vector <Enemy*> list = all->getList();
            for (auto element : list)
            {
                save << element->getX() << endl << element->getY() << endl << element->type << endl;
            }

            if (Mix_PausedMusic() == 0)
            {
                Mix_PauseMusic();
            }

            Game::startGame();
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_L])
    {
        for (auto element : all->getList())
        {
            cout<<"death\n";
            element->dead = true;
        }
    }
    else
    {
        if (ss)
        {
            Gamer->update(-1);
        }
        else
        {
            Gamer->update(0);
        }



    }


    all->trackAll(Gamer);

    for (unsigned int i = 0; i < all->getList().size(); i++)
    {
        if (all->getList()[i]->type == 2)
        {
            if (SDL_HasIntersection(Gamer->getDRect(), all->getList()[i]->getDRect()))
            {
                cout << "dragon ball" << endl;
                all->getErased().push_back(all->getList()[i]);
                all->getList().erase(all->getList().begin() + i);//takes dragon balls for health
                Enemy::attacks -= 1;
                Mix_PlayChannel(-1, gBall, 0);
                break;
            }
        }
    }

    if (all->isTouching(Gamer) == 0 || all->isTouching(Gamer) == 1)
    {
        touches++;
    }
    else if (all->isTouching(Gamer) == 2)
    {
        Enemy::attacks -= 2;//increase in health
    }

    if (touches % 30 == 0 && touches > 0)//if player collides with the enemies then its health should decrease
    {
        cout << Enemy::attacks++ << endl;
    }
    if (kam)
    {

        for (unsigned int i = 0; i < all->getList().size(); i++)
        {
            if (SDL_HasIntersection(p->getDRect(), all->getList()[i]->getDRect()))
            {
                all->getList()[i]->dead = true;
            }
        }
    }

}
void Game::update()
{
    updateCount++;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bg, &camera,NULL);
    Gamer->render();
    Words W(&textSheetTexture);
    W.RenderWord_Health(renderer);
    W.RenderWord_Mana(renderer);
    if (kam)
    {
        Projectile* p=new Projectile("images/ki1.png", Gamer->getX()+150, Gamer->getY(), 192, 192, 192);
        p->update(0);
        p->render();
        delete p;
    }

    /*SDL_RenderDrawRect(renderer,&surfaces[0]);
    SDL_RenderDrawRect(renderer,&surfaces[1]);
    SDL_RenderDrawRect(renderer,&surfaces[2]);
    SDL_RenderDrawRect(renderer,&surfaces[3]);
    SDL_RenderDrawRect(renderer,&safeSurfaces[0]);
    SDL_RenderDrawRect(renderer,&safeSurfaces[1]);
    SDL_RenderDrawRect(renderer,&safeSurfaces[2]);
    SDL_RenderDrawRect(renderer,&safeSurfaces[3]);
    SDL_RenderDrawRect(renderer,&surfaces[4]);*/

    all->renderAll();
    healthBar->render(8 - Enemy::attacks,Gamer->getMana(), renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    Gamer=NULL;
    delete Gamer;
    all=NULL;
    delete all;
    healthBar=NULL;
    delete healthBar;
    Mix_FreeMusic( music );
    Mix_CloseAudio();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

Game::~Game() {}
