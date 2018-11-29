#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Screens.h"
#include "Clickable.h"
#include "Entrance.h"
#include "Mosquito.h"
#include "Human.h"
#include "Score.h"

#include <vector>


class BreedingGround;

class Scenario : public Screens
{
protected:

    int startHeight;
    int endHeight;
    int startWidth;
    int endWidth;
    void SetUpScenarios();
    int noOfEntrance;
    BreedingGround** breedingplaces;
    std::vector<Clickable*> myQ;
    std::vector<Human*> humans;
    std::vector<Mosquito*> mosquitoes;

    Entrance** entrance;
    int noOfBreedingPlaces;
    int code;
    Score* points;

public:

    BreedingGround** GetBreedingGrounds(int&);
    Entrance** GetEntrance(int &);

    Scenario();
    virtual void AddHuman(Human*);
    virtual void LeaveHuman(Human*);
    virtual void AddMosquito(Mosquito*);
    virtual void LeaveMosquito(Mosquito*);
    std::vector<Human*>& GetHumans(int & );
    std::vector<Mosquito*>& GetMosquitoes(int &);
    int GetEndHeight();
    int GetStartHeight();
    int GetEndWidth();
    int GetStartWidth();
    int GetCode();
    ~Scenario(){};

};





#endif // SCENARIO_H_INCLUDED
