#include "Scenario.h"
#include "BreedingGround.h"

Scenario::Scenario(Screens* prevScreen, bool back, bool show, bool update, int factor): Screens(prevScreen, back, show, update, factor)
{
    points = Score::GetInstance(); //getting singleton
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
    int to_remove = -1;
    for (int i = 0; i < humans.GetLength(); i++)
    {
        if (humans.GiveItem(i) == human)
        {
            to_remove = i;
            break;
        }
    }
    if (to_remove != -1)
    {
        humans.Pop(to_remove);
        to_remove = -1;
    }

    for (int i = 0; i < myQ.GetLength(); i++)
    {
        if (myQ.GiveItem(i) == human)
        {
            to_remove = i;
            break;
        }
    }
    if (to_remove != -1)
    {
        myQ.Pop(to_remove);
        to_remove = -1;
    }
}

bool Scenario::Collides(Clickable* obj)
{
    ///returns if the obj collides with any object in the scenario.
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

Scenario::~Scenario()
{




}

