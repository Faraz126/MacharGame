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
    mosquitoes.push_back(mosquito);
}

void Scenario::LeaveMosquito(Mosquito* mosquito)
{
    mosquitoes.erase(std::remove(mosquitoes.begin(), mosquitoes.end(), mosquito), mosquitoes.end());
}
