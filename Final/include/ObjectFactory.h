#pragma once
#include <vector>
#include "Saibaman.h"
#include "CellJr.h"
#include "DragonBall.h"

using namespace std;

class ObjectFactory
{
private:
    vector <Enemy*> enemies;//all the objects in this array
    vector <Enemy*> erased;//all those enemies who died out
public:
    ObjectFactory();
    ObjectFactory(vector <string> &load);//overloaded for positions of the previous game
    void trackAll(GameObject* player);
    void renderAll();
    ~ObjectFactory();
    vector <Enemy*> &getList()
    {
        return enemies;
    }
    vector <Enemy*> &getErased()
    {
        return erased;
    }
    bool isTouching(GameObject* e1, Enemy* e2);//for repulsions detection
    int isTouching(GameObject* player);//for health reduction
    void setBalls(int x, int y);//so that balls do not move with the screen
};
