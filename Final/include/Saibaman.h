#pragma once
#include "Enemy.h"
#include "GameObject.h"


class Saibaman : public Enemy
{
public:
    int deathFrame = 0;//frames for animations
    int attackFrame = 0;
    Saibaman(const char* textureSheet, int x, int y, int R, int G, int B);
    ~Saibaman() {};
    void update(int flag, double i_angle);//controlls all the animations
    void kiBlast(int frame);//attacking
    void track(GameObject& player, bool flag);//tracks or death
    void death(int frame);//death animations
};
