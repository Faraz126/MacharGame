#include "Container.h"

Container::Container(int x, int y, int w, int h, bool status): BreedingGround(x,y,w,h) //initiating base class
{
    SetCovered(status);
    if (!status)
    {
        lid = new TrashCanLid(x + 50, y + 50);
    }
    else
    {
        lid = 0;
    }
}

bool Container::GetCovered()
{
    return isCovered;
}

void Container::SetCovered(bool status)
{
    if (status)
    {
        //delete lid;
        lid = 0;
    }
    else
    {
        lid = new TrashCanLid(pos.x + 50, pos.y + 50);
    }
    isCovered = status;
}

void Container:: SetX(int delta, int direction)
{
    lid->SetX(delta, direction);
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



