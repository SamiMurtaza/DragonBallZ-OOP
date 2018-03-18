#include "Health.h"

Health::Health()
{

}

void Health::render(int health, int mana, SDL_Renderer* renderer)
{

    if (health >= 8)
    {
        health = 8;
    }
    if (mana >= 8)
    {
        mana = 8;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect fillRect = { 658,24,29*8+2,36 };
    SDL_RenderDrawRect(renderer, &fillRect);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    for (int i = 0; i < health*7; i++)
    {
        SDL_Rect fillRect = { 663 + 4 * i,27,3,30 };
        SDL_RenderFillRect(renderer, &fillRect);
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect outlineRect = { 658,24+43,29 * 8+2,36 };
    SDL_RenderDrawRect(renderer, &outlineRect);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0x00);
    for (int i = 0; i < mana*7; i++)
    {
        SDL_Rect fillRect = { 663 + 4 * i,70,3,30};
        SDL_RenderFillRect(renderer, &fillRect);
    }
}
