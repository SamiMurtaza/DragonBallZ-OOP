#ifndef PICOLO_H
#define PICOLO_H

#include <Character.h>


class Picolo : public Character
{
public:

    Picolo(const char* textureSheet, int x, int y, int R, int G, int B);
    virtual ~Picolo();
    void update(int flag, double angle = 0.0) {}
    void update(int flag);
    void InstantTransmission() {}
    void Regenerate();

protected:

private:
};

#endif // PICOLO_H
