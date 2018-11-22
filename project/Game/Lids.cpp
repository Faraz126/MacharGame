#include "Lids.h"

Lids::Lids(int x, int y, int w, int h): Clickable(x,y,w,h)
{

}

Lids::~Lids()
{

}

void Lids:: Drag(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;

//    if (Lids.WithinRegion(hoverX,hoverY))
//    {
//
//    }
}

void Lids::HandleEvents(SDL_Event* e)
{

}

void Lids::SetX(int delta, int direction)
{

}

void Lids::SetPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
