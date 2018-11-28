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

int Scenario::GetStartWidth()
{
    return startWidth;
}

int Scenario::GetStartHeight()
{
    return startHeight;
}

int Scenario::GetEndWidth()
{
    return endWidth;
}

int Scenario::GetEndHeight()
{
    return endHeight;
}

std::vector<Human*>& Scenario::GetHumans(int & n)
{
    n = humans.size();
    return humans;
}


std::vector<Mosquito*>& Scenario::GetMosquitoes(int& n)
{
    n = mosquitoes.size();
    return mosquitoes;
}

