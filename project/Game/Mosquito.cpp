#include "Scenario.h"
#include "Mosquito.h"


/*
Mosquito::Mosquito()
{

}

Mosquito::~Mosquito()
{

}

*/
void Mosquito::Bite(Human*)
{

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
        if (entrance[i]->GetDistance(x,y) < dist && entrance[i]->IsOpen())
        {
            dist = entrance[i]->GetDistance(x,y);
            temp = entrance[i];
        }
    }
    return temp;
}

void Mosquito::UpdatePositiion(int x,int y)
{
    position.x = x;
    position.y = y;
}

void Mosquito::SetScenario(Scenario* cScenario)
{
    screen = cScenario;
}
