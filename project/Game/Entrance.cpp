#include "Entrance.h"
#include <cstdlib>
#include <cmath>

Entrance::Entrance(int x,int y, int w, int h): Clickable(x,y,w,h)
{

}

void Entrance::Show(SDL_Renderer* renderer)
{

}


SDL_Rect& Entrance::GetOutdoorRect()
{
    return outdoorPos;
}

void Entrance::GetOutdoorPos(int& x, int& y)
{
    x = outdoorPos.x + outdoorPos.w/2;
    y = outdoorPos.y + outdoorPos.h/2;
}

void Entrance::SetOutdoorPos(int x, int y,int w, int h)
{
    outdoorPos.x = x;
    outdoorPos.y = y;
    outdoorPos.w = w;
    outdoorPos.h = h;
}


int Entrance::GetDistanceOutside(int x, int y)
{
    return sqrt((abs(outdoorPos.x - x)*abs(outdoorPos.x - x))+(abs(outdoorPos.y - y)*abs(outdoorPos.y - y)));
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


int Entrance::GetX(bool indoor)
{
    if (indoor)
    {
        return pos.x;
    }
    return outdoorPos.x;
}

int Entrance::GetY(bool indoor)
{
    if (indoor)
    {
        return pos.y;
    }
    return outdoorPos.y;
}


void Entrance::SetOutdoor(Scenario* outdoor)
{
    outdoorPtr = outdoor;
}

Scenario* Entrance::GetOutdoor()
{
    return outdoorPtr;
}
