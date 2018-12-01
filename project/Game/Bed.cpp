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
           Texture::GetInstance()->Render(126, renderer, &pos);
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
        sitting = new SDL_Rect;
        sitting->x = pos.x +35;
        sitting->y = pos.y +25;
        sitting->w = pos.w -75;
        sitting->h = pos.h -75;

    }
    else
    {
        delete sitting;
    }
}


void Bed::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (occupied && state != SITTING)
    {
        int x = e->button.x;
        int y = e->button.y;
        if (WithinRegion(x,y) && e->type == SDL_MOUSEBUTTONDOWN)
        {
            bedOccupied->GoToHospital();
        }
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
