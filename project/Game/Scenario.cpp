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
