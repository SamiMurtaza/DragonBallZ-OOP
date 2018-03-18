#include"LTexture.h"

using namespace std;

LTexture::LTexture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

LTexture::~LTexture()
{
    Free();
}

bool LTexture::LoadFromFile( std::string path, SDL_Renderer* gRenderer)
{
    //Get rid of preexisting texture
    Free();
    cout<<path<<endl;
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 80 ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

        }
        else
        {
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    texture = newTexture;
    return texture != NULL;
}

void LTexture::Free()
{
    //Free texture if it exists
    if( texture != NULL )
    {
        SDL_DestroyTexture( texture );
        texture = NULL;
        width = 0;
        height = 0;
    }
}



void LTexture::SetAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( texture, alpha );
}

void LTexture::Render( int enlarge,int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Renderer* gRenderer)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };
    //Set clip rendering dimensions
    if(( clip != NULL )&&(enlarge==0)) //normal size
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    if(( clip != NULL )&&(enlarge==1)) //two times larger
    {
        renderQuad.w = clip->w*2;
        renderQuad.h = clip->h*2;

    }
    if(( clip != NULL )&&(enlarge==2)) //two times smaller
    {
        renderQuad.w = clip->w/1.8;
        renderQuad.h = clip->h/1.8;

    }
    if(( clip != NULL )&&(enlarge==3)) // times larger
    {
        renderQuad.w = clip->w*1.7;
        renderQuad.h = clip->h*1.7;
    }
    //Render to screen
    SDL_RenderCopyEx( gRenderer, texture, clip, &renderQuad, angle, center, flip );
}

void LTexture::RenderTransition( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Renderer* gRenderer, int transparency)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };

    //Set clip rendering dimensions

    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    LTexture::SetAlpha( transparency );
    SDL_RenderCopyEx( gRenderer, texture, clip, &renderQuad, angle, center, flip );
}


