#include "Entrance.h"

Entrance::Entrance(int x,int y, int w, int h): Clickable(x,y,w,h)
{

}

void Entrance::Show(SDL_Renderer* renderer)
{

}

void Entrance::SetOutdoorPos(int x, int y,int w, int h)
{
    OutdoorPos.x = x;
    OutdoorPos.y = y;
    OutdoorPos.w = w;
    OutdoorPos.h = h;
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
        OutdoorPos.x+=delta;

    }
    if ( direction == 1)
    {
        OutdoorPos.x-=delta;
    }
}

Entrance::~Entrance()
{

}
