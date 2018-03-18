#pragma once
#include "Enemy.h"

class DragonBall : public Enemy
{
public:
    DragonBall(const char* textureSheet, int x, int y, int R, int G, int B);
    ~DragonBall();
    void update(int flag, double i_angle = 0.0);
    void kiBlast(int frame) {};
    void track(GameObject& player, bool)
    {
        update(1);
    }
    void death(int frame) {}
};
