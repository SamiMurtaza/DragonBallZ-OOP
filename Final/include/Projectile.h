#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"


class Projectile : public GameObject
{
public:
    Projectile(const char* textureSheet, int x, int y, int R, int G, int B);
    virtual ~Projectile();
    void update(int flag, double angle = 0.0);
protected:

private:
};

#endif // PROJECTILE_H
