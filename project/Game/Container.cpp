#include "Container.h"
#include "Texture.h"

Container::Container(int x, int y, int w, int h, bool status): BreedingGround(x,y,w,h) //initing base class
{
    SetCovered(status);
}

bool Container::GetCovered()
{
    return isCovered;
}

void Container::SetCovered(bool status)
{
    isCovered = status;
}

void Container:: SetX(int delta, int direction)
{
    if ( direction == 0)
    {
        pos.x+=delta;
    }
    if ( direction == 1)
    {
        pos.x-=delta;
    }
}

Container::~Container()
{

}

Mosquito* Container::Breed(int n)
{

}
