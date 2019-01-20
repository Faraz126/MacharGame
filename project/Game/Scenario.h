#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Screens.h"
#include "Clickable.h"
#include "Entrance.h"
#include "Mosquito.h"
#include "Human.h"
#include "Score.h"

#include <vector>
#include "DoublyLinked.h"


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
    DLL<Clickable*> myQ;
    DLL<Human*> humans;
    DLL<Mosquito*> mosquitoes;
    int noOfBreedingPlaces;
    int code;
    Entrance** entrance;
    Score* points;

public:

    BreedingGround** GetBreedingGrounds(int&);
    Entrance** GetEntrance(int &);
    DLL<Clickable*>& GetQ();
    Scenario(Screens*, bool, bool = false, bool = false, int = 1);
    virtual bool AddHuman(Human*);
    virtual void LeaveHuman(Human*);
    virtual void AddMosquito(Mosquito*);
    virtual void LeaveMosquito(Mosquito*);
    DLL<Mosquito*>& GetMosquitoes(int &);
    int GetEndHeight();
    int GetStartHeight();
    int GetEndWidth();
    int GetStartWidth();
    bool Collides(Clickable*);
    bool Collides(SDL_Rect&);
    int GetCode();
    DLL<Human*>& GetHumans(int & );
    virtual ~Scenario();

};






#endif // SCENARIO_H_INCLUDED
