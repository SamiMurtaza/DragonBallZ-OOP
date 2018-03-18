
#include "Enemy.h"
#include<SDL_mixer.h>

int frame = 0;
int Enemy::attacks = 0;

Enemy::Enemy(const char* textureSheet, int x, int y, int R, int G, int B) :GameObject(textureSheet, x, y, R, G, B)
{
    convert = false;
    dead = false;
    gEAttack = Mix_LoadWAV("audio/enemattack.wav");
    gEDamage = Mix_LoadWAV("audio/enemdamage.wav");
}

Enemy::~Enemy() {
    gEAttack=NULL;
    gEDamage=NULL;
    delete gEAttack;
    delete gEDamage;
};


