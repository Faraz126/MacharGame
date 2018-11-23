#include "Bed.h"
#include "Texture.h"
#include <cmath>

Bed::Bed():Clickable(0,0,0,0)
{

}

Bed::Bed(int x, int y): Clickable(x,y,153,174)
{
    ReduceSize(0.8);
    occupied = false;
}

void Bed::Draw(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(14, renderer, &pos);
    SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
    SDL_RenderDrawRect(renderer, &pos);
}

void Bed::SetPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
    pos.w = 153;
    pos.h = 174;
}

Bed::~Bed()
{

}

int Bed::GetDistance(int x, int y)
{
    return sqrt((abs(pos.x - x)*abs(pos.x - x))+(abs(pos.y - y)*abs(pos.y - y)));
}

bool Bed::GetOccupied()
{
    return occupied;
}

void Bed::SetOccupied(bool status)
{
    occupied = status;
}

int Bed::GetX()
{
    return pos.x;
}
int Bed::GetY()
{
    return pos.y;
}
