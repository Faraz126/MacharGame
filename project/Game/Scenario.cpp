#include "Scenario.h"
#include "BreedingGround.h"

Entrance** Scenario::GetEntrance(int & n)
{
    n = noOfEntrance;
    return entrance;
}

BreedingGround** Scenario::GetBreedingGrounds(int & n)
{
    n = noOfBreedingPlaces;
    return breedingplaces;
}

int Scenario::GetWidth()
{
    return width;
}

int Scenario::GetHeight()
{
    return height;
}

std::vector<Human*>& Scenario::GetHumans(int & n)
{
    n = humans.size();
    return humans;
}


