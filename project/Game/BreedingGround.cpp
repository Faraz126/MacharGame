#include "BreedingGround.h"


BreedingGround::BreedingGround(int x, int y, int w, int h): Clickable(x,y,w,h)
{
    factory = FactoryProducer::GetFactory(0);
}

void BreedingGround::UpdatePos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void BreedingGround::AddMosquito(Mosquito* produced)
{
    int n;
    produced->SetScenario(currentScenario); //sets the scenario of the mosquito
    produced->UpdatePositiion(pos.x, pos.y);
    currentScenario->GetMosquitoes(n).Append(produced);
}

int BreedingGround :: GetBreedCount()
{
    return 0;
}

BreedingGround::~BreedingGround()
{

}



