#pragma once
#include "Enemy.h"

class CellJr : public Enemy
{
public:
    int deathFrame = 0;//frames for animations
    int attackFrame = 0;
    CellJr(const char* textureSheet, int x, int y, int R, int G, int B);
    ~CellJr() {};
    void update(int flag, double i_angle);//has all animations to control
    void kiBlast(int frame);//attacking
    void death(int frame);//dieing frame
    void track(GameObject& player, bool flag);//tracks the player
};
