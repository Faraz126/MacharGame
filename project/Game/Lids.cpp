#include "Lids.h"

Lids::Lids(int x, int y, int w, int h): Clickable(x,y,w,h)
{
    mouseClick = false;
}

Lids::~Lids()
{

}


void Lids::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int x = e->button.x;
    int y = e->button.y;
    if ((e->type == SDL_MOUSEBUTTONDOWN) && (e->button.button == SDL_BUTTON_LEFT) && WithinRegion(x,y))
    {
        mouseClick = true;
    }

    if ((e->type == SDL_MOUSEBUTTONUP))
    {
        mouseClick = false;
    }


    if (mouseClick == true)
    {
        pos.x = x;
        pos.y = y;
    }
//
//        if ((e->type == SDL_MOUSEBUTTONUP) && (e->button.button == SDL_BUTTON_LEFT))
//        {
//            mouseClick = false;
//        }
}


void Lids::SetPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void Lids:: SetX(int delta, int direction)
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
