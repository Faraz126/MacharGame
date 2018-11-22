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


