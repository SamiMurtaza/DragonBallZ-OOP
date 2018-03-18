#ifndef VEGETA_H
#define VEGETA_H
#include <Character.h>

class Vegeta : public Character
{
    public:

        Vegeta(const char* textureSheet, int x, int y, int R, int G, int B);
        virtual ~Vegeta();
        void update(int flag, double angle = 0.0){}
        void update(int flag);
        //void punch(){}
        //void kick(){}
        //void kiBlast();

    protected:

    private:
};

#endif // VEGETA_H
