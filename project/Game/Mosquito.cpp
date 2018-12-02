#include "Scenario.h"
#include "Mosquito.h"



Mosquito::Mosquito()
{
    indoor = true;
    IsDead = false;
}

void Mosquito::SetIndoor(bool status)
{
    indoor = status;
}

/*

Mosquito::~Mosquito()
{

}

*/

void Mosquito::Bite(Human*)
{

}



void Mosquito::UpdatePositiion(int x,int y)
{
    position.x = x;
    position.y = y;
}

void Mosquito::SetScenario(Scenario* cScenario)
{
    screen = cScenario;
    indoor = screen->GetCode();
}

void Mosquito::SetIsDead(bool dead)
{
    IsDead = true;
}

Entrance* Mosquito::GetClosestEntrance()
{
    int x = position.x;
    int y = position.y;
    double dist = 8000000;
    int noOfEntrance;
    Entrance** entrance = screen->GetEntrance(noOfEntrance);
    Entrance* temp = 0;
    for (int i = 0; i < noOfEntrance; i++)
    {
        if (indoor)
        {
            if (entrance[i]->GetDistance(x,y) < dist && entrance[i]->IsOpen())
            {
                dist = entrance[i]->GetDistance(x,y);
                temp = entrance[i];
            }
        }
        else
        {
            if (entrance[i]->GetDistanceOutside(x,y) < dist && entrance[i]->IsOpen())
            {
                dist = entrance[i]->GetDistanceOutside(x,y);
                temp = entrance[i];
            }

        }

    }
    return temp;
}

void Mosquito::SetX(int delta, int direction)
{

    if ( direction == 0)
    {
        position.x+=delta;

    }
    if ( direction == 1)
    {
        position.x-=delta;
    }
}
