#include "Entrance.h"

Entrance::Entrance(int x,int y, int w, int h): Clickable(x,y,w,h)
{

}

void Entrance::Show(SDL_Renderer* renderer)
{

}

void Entrance::SetOutdoorPos(int x, int y,int w, int h)
{
    outdoorPos.x = x;
    outdoorPos.y = y;
    outdoorPos.w = w;
    outdoorPos.h = h;
}


int Entrance::GetX()
{
    return pos.x;
}

int Entrance::GetY()
{
    return pos.y;
}

int Entrance::GetHeight()
{
    return pos.h;
}


int Entrance::GetWidth()
{
    return pos.w;
}

void Entrance:: SetOutdoorX(int delta, int direction)
{

    if ( direction == 0)
    {
        outdoorPos.x+=delta;

    }
    if ( direction == 1)
    {
        outdoorPos.x-=delta;
    }
}

Entrance::~Entrance()
{

}
