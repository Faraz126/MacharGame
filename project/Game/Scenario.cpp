#include "Scenario.h"
#include "BreedingGround.h"
#include <algorithm>

Scenario::Scenario()
{
    points = Score::GetInstance();
}


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

DLL<Human*>& Scenario::GetHumans(int & n)
{
    n = humans.GetLength();
    return humans;
}



DLL<Mosquito*>& Scenario::GetMosquitoes(int& n)
{
    n = mosquitoes.GetLength();
    return mosquitoes;
}

int Scenario::GetCode()
{
    return code;
}

void Scenario::SetUpScenarios()
{
    for (int i = 0; i < noOfBreedingPlaces; i++)
    {
        breedingplaces[i]->SetScenario(this);
    }

}

void Scenario::AddMosquito(Mosquito* mosquito)
{
    mosquitoes.Append(mosquito);
}

void Scenario::LeaveMosquito(Mosquito* mosquito)
{
    mosquitoes.RemoveItem(mosquito);
}


bool Scenario::AddHuman(Human* human)
{
    humans.Append(human);
    myQ.Append(human);
    return true;
}

void Scenario::LeaveHuman(Human* human)
{
    humans.RemoveItem(human);
    myQ.RemoveItem(human);
}

bool Scenario::Collides(Clickable* obj)
{
    for (int i = 0; i < myQ.GetLength(); i++)
    {
        if (myQ.GiveItem(i)->Collides(*obj) && myQ.GiveItem(i) != obj)
        {
            return true;
        }
    }
    return false;
}

bool Scenario::Collides(SDL_Rect& rect)
{
    for (int i = 0; i < myQ.GetLength(); i++)
    {
        if (myQ.GiveItem(i)->Collides(rect))
        {
            return true;
        }
    }
    return false;
}

DLL<Clickable*>& Scenario::GetQ()
{
    return myQ;
}
