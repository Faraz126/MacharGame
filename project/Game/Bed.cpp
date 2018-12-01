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

void Bed::Show(SDL_Renderer* renderer)
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

bool Bed::GetOccupied()
{
    return occupied;
}

void Bed::SetOccupied(bool status, Human* human)
{
    occupied = status;
    bedOccupied = human;
}

int Bed::GetX()
{
    return pos.x;
}
int Bed::GetY()
{
    return pos.y;
}
