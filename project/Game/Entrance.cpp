#include "Entrance.h"

Entrance::Entrance(int x,int y, int w, int h): Clickable(x,y,w,h)
{

}

void Entrance::Show(SDL_Renderer* renderer)
{

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

Entrance::~Entrance()
{

}
