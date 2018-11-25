#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Screens.h"
#include "Clickable.h"
#include "Entrance.h"

#include <vector>


class BreedingGround;

class Scenario : public Screens
{
protected:
    int noOfEntrance;
    BreedingGround** breedingplaces;
    std::vector<Clickable*> myQ;
    Entrance** entrance;
    int noOfBreedingPlaces;

public:
    BreedingGround** GetBreedingGrounds(int&);
    Entrance** GetEntrance(int &);



};





#endif // SCENARIO_H_INCLUDED
