#include "Entrance.h"


Entrance::Entrance(int x,int y)
{
    pos.x = x;
    pos.y = y;

}

void Entrance::Show(SDL_Renderer* renderer)
{

}

bool Entrance::WithinEntrance(int x, int y)
{
    return x >= pos.x && y >= pos.y && x <= pos.x + pos.w && y <= pos.h + pos.y;
}
