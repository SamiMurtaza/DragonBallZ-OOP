#include "ObjectFactory.h"
#include <sstream>
#include <cstdlib>
#include <string>
#include "Enemy.h"
#include "Game.h"

int atoi(string s)
{
    // object from the class stringstream
    stringstream geek(s);

    // The object has the value 12345 and stream
    // it to the integer x
    int x;
    geek >> x;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << x;

    return x;
}

ObjectFactory::ObjectFactory()
{


    int x(0), y(0), type(0);

    for (int i = 0; i < 50; i++)
    {
        x = (i * 350) + 10;
        y = (i * 200) + 10;
        if (type % 2==0)
        {
            enemies.push_back(new Saibaman("saibaman.png", x, y, 130, 151, 191));
        }
        else
        {
            enemies.push_back(new CellJr("cell.png", x, y, 2, 128, 109));
        }

        type++;

    }
}

ObjectFactory::ObjectFactory(vector <string> &load)
{


    int x(0), y(0);

    for (unsigned int i = 6; i < load.size() - 2; i += 3)
    {
        x = atoi(load[i]);
        y = atoi(load[i + 1]);
        if (atoi(load[i + 2]) == 0)
        {
            enemies.push_back(new Saibaman("saibaman.png", x, y, 130, 151, 191));
        }
        else if (atoi(load[i + 2]) == 1)
        {
            enemies.push_back(new CellJr("cell.png", x, y, 2, 128, 109));
        }
        else if (atoi(load[i + 2]) == 2)
        {
            enemies.push_back(new DragonBall("ball.png", x, y, 255, 255, 255));
        }

    }
}

void ObjectFactory::trackAll(GameObject* Gameplayer)
{
    int num = enemies.size();

    if (num == 0)
    {
        return;
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (isTouching(enemies[i], enemies[j]))
            {
                if (i > j)
                {
                    if (enemies[i]->type != 2)
                    {
                        enemies[i]->setX(enemies[i]->getX() - 1);
                    }
                }
                else
                {
                    if (enemies[i]->type != 2)
                    {
                        enemies[j]->setX(enemies[j]->getX() - 1);
                    }
                }
            }
        }

        if (!enemies[i]->dead)
        {
            enemies[i]->track(*Gameplayer, 1);
        }
        else if (enemies[i]->dead)
        {
            enemies[i]->track(*Gameplayer, 0);
        }

        if (enemies[i]->convert)
        {
            erased.push_back(enemies[i]);
            enemies[i] = new DragonBall("ball.png", enemies[i]->getX(), enemies[i]->getY(), 255, 255, 255);
        }
    }
}

void ObjectFactory::renderAll()
{
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        enemies.at(i)->render();
    }
}

ObjectFactory::~ObjectFactory()
{
    for (unsigned int i = 0; i < erased.size(); i++)
    {
        delete erased[i];
    }
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
}

bool ObjectFactory::isTouching(GameObject* e1, Enemy* e2)
{
    if (e1->getX() - e2->getX() < 50 && e1->getX() - e2->getX() > -50)
    {
        if (e1->getY() == e2->getY())
        {
            return true;
        }
    }
    return false;
}

int ObjectFactory::isTouching(GameObject* player)
{
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        if (SDL_HasIntersection(player->getDRect(), enemies[i]->getDRect()))
        {
            return enemies[i]->type;
        }
    }
    return -1;
}

void ObjectFactory::setBalls(int x, int y)
{
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i]->type == 2)
        {
            enemies[i]->setX(enemies[i]->getX() + x);
            enemies[i]->setY(enemies[i]->getY() + y);
        }
    }
}
