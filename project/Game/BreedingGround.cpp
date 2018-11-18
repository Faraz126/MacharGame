#include "BreedingGround.h"


BreedingGround::BreedingGround(int x, int y, int w, int h)
{
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;
    //factory = new FactoryProducer::GetFactory(0);
}

void BreedingGround::UpdatePos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void BreedingGround::Show(SDL_Renderer* renderer)
{

}

Mosquito* BreedingGround::Breed(int n)
{

}

BreedingGround::~BreedingGround()
{

}



