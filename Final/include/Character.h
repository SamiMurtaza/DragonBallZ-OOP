#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include <SDL_mixer.h>


//the class form which all the player characters inherit

class Character:public GameObject
{
public:

    Character(const char* textureSheet, int x, int y, int R, int G, int B);
    virtual ~Character();
    virtual void update(int)=0;  //the function that will actually change the sprites
    void punch();
    void kick();
    void kiBlast();
    void powerUP();

    //getters and setters

    int getHealth()
    {
        return health;
    }
    int getMana()
    {
        return mana;
    }
    void addMana()
    {
        mana+=1;
    }
    void setMana(int ma)
    {
        mana=ma;
    }
    void setHealth(int ha)
    {
        health=ha;
    }
    virtual void InstantTransmission()=0;
    virtual void Regenerate()=0;

protected:
    int health=8;
    int mana=2;
    Mix_Chunk *PUp;
    Mix_Chunk *KiAttack;
    Mix_Chunk *gAttack;
    Mix_Chunk *gPower;


private:


};

#endif // CHARACTER_H
