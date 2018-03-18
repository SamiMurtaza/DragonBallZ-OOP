#include "Character.h"
#include<SDL_mixer.h>

Character::Character(const char* textureSheet, int x, int y, int R, int G, int B):GameObject(textureSheet, x, y, R, G, B)
{


}

Character::~Character()
{
    //dtor
}

void Character::kiBlast()
{
}

void Character::powerUP()
{
}

void Character::punch() {}
void Character::kick() {}
