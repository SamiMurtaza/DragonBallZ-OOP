#pragma once
#include <vector>
#include <SDL.h>

using namespace std;

class Health
{
private:
    vector <SDL_Rect*> bar;
public:
    Health();
    void render(int health, int mana, SDL_Renderer* renderer);
};
