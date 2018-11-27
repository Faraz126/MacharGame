#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Screens.h"
#include "Clickable.h"
#include "Entrance.h"
#include "Mosquito.h"

#include <vector>


class BreedingGround;

class Scenario : public Screens
{
protected:
    int width;
    int height;
    int noOfEntrance;
    BreedingGround** breedingplaces;
    std::vector<Clickable*> myQ;
    std::vector<Human*> humans;
    std::vector<Mosquito*> mosquitoes;

    Entrance** entrance;
    int noOfBreedingPlaces;

public:

    BreedingGround** GetBreedingGrounds(int&);
    Entrance** GetEntrance(int &);


    virtual void AddHuman(Human*){};
    virtual void LeaveHuman(Human*){};
    virtual void AddMosquito(Mosquito*){};
    virtual void LeaveMosquito(Mosquito*){};
    std::vector<Human*>& GetHumans(int & );
    int GetWidth();
    int GetHeight();
    ~Scenario(){};

};





#endif // SCENARIO_H_INCLUDED
