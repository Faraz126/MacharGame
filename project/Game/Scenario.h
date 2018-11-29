#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Screens.h"
#include "Clickable.h"
#include "Entrance.h"
#include "Mosquito.h"
#include "DoublyLinked.h"


class BreedingGround;

class Scenario : public Screens
{
protected:
    int width;
    int height;
    int noOfEntrance;
    BreedingGround** breedingplaces;
    DLL<Clickable*> myQ;
    DLL<Human*> humans;
    DLL<Mosquito*> mosquitoes;

    Entrance** entrance;
    int noOfBreedingPlaces;

public:

    BreedingGround** GetBreedingGrounds(int&);
    Entrance** GetEntrance(int &);


    virtual bool AddHuman(Human*){};
    virtual void LeaveHuman(Human*){};
    virtual void AddMosquito(Mosquito*){};
    virtual void LeaveMosquito(Mosquito*){};
    DLL<Human*>& GetHumans(int & );
    int GetWidth();
    int GetHeight();
    ~Scenario(){};

};





#endif // SCENARIO_H_INCLUDED
