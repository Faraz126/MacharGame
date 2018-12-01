#include "Bed.h"
#include "Texture.h"
#include <cmath>

Bed::Bed():Clickable(0,0,0,0)
{
    state= 0;
    occupied = false;

}

void Bed::HumanState(int st)
{
    state = st;
}


Bed::Bed(int x, int y): Clickable(x,y,153,174)
{
    ReduceSize(0.8);
    occupied = false;
    state= 0;
    sitting = 0;
    lying = 0;
}

void Bed::Show(SDL_Renderer* renderer)
{

    SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
    SDL_RenderDrawRect(renderer, &pos);
    if (occupied)
    {
        if (state == SITTING)
        {
            Texture::GetInstance()->Render(14, renderer, &pos);
            Texture::GetInstance()->Render(134, renderer, sitting);
        }
        else
        {
           Texture::GetInstance()->Render(123, renderer, &pos);
        }
    }
    else
    {
        Texture::GetInstance()->Render(14, renderer, &pos);
    }
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
    if (status)
    {
        sitting = new SDL_Rect(pos.x + 10, pos.y+ 10, pos.w - 10, pos.h- 10);
        lying = new SDL_Rect(pos.x + 10, pos.y+ 10, pos.w - 10, pos.h- 10);
    }
    else
    {
        delete sitting;
        delete lying;
        delete human;
    }
}

int Bed::GetX()
{
    return pos.x;
}
int Bed::GetY()
{
    return pos.y;
}
