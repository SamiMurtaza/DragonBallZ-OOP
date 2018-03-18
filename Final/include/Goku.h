#ifndef GOKU_H
#define GOKU_H

#include <Character.h>


class Goku : public Character
{
public:

    Goku(const char* textureSheet, int x, int y, int R, int G, int B);
    virtual ~Goku();
    void update(int flag, double angle = 0.0) {};
    void update(int flag);
    void InstantTransmission();
    void Regenerate() {}

protected:

private:
};

#endif // GOKU_H
