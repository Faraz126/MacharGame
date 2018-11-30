#include "Container.h"

Container::Container(int x, int y, int w, int h, bool status): BreedingGround(x,y,w,h) //initiating base class
{
    lid = 0;
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
    if (lid != 0)
    {
        lid->SetX(delta, direction);
    }

    if ( direction == 0)
    {
        pos.x+=delta;
        correctLidPos.x += delta;

    }
    if ( direction == 1)
    {
        pos.x-=delta;
        correctLidPos.x -= delta;
    }
}

bool Container::Collides(const Clickable& obj)
{

    if (!isCovered && lid != 0 && &obj != lid)
    {
        return lid->Collides(obj) || Clickable::Collides(obj);
    }

    return Clickable::Collides(obj);
}

bool Container::Collides(const SDL_Rect& rect)
{

    if (lid != 0)
    {
        return lid->Collides(rect) || Clickable::Collides(rect);
    }

    return Clickable::Collides(rect);
}




Container::~Container()
{

}



