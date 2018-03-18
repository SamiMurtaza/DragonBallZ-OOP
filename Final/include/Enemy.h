#pragma once
#include "GameObject.h"
#include <SDL_mixer.h>

class Enemy :public GameObject
{
protected:
    Mix_Chunk* gEAttack;
    Mix_Chunk* gEDamage;

public:
    bool dead;
    bool convert;
    Enemy(const char* textureSheet, int x, int y, int R, int G, int B);
    virtual ~Enemy();
    virtual void track(GameObject& player, bool flag) = 0;
    virtual void update(int flag, double i_angle) = 0;
    virtual void kiBlast(int) = 0;
    virtual void death(int) = 0;
    static int attacks;
    int type;
};

///int Enemy::attacks = 0;
