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





BreedingGround::~BreedingGround()
{

}



