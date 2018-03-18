#include "Projectile.h"

Projectile::Projectile(const char* textureSheet, int x, int y, int R, int G, int B): GameObject (textureSheet, x, y, R, G, B)
{

}

Projectile::~Projectile()
{

}


void Projectile::update(int flag, double angle)
{
    if (flag==0)
    {
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.h = 67;
        srcRect.w = 200;
    }
    if (flag==1) {}

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*2.5;
    destRect.h = srcRect.h*2.5;
}
