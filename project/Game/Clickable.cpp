#include "Clickable.h"
#include <cstdlib>
#include <cmath>
#include "Scenario.h"

Clickable::Clickable(int x, int y, int w, int h)
{
    ///the position on screen
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;
    currentScenario = 0;
}

Clickable::~Clickable()
{

}

int Clickable::GetX()
{
    return pos.x;
}

int Clickable::GetY()
{
    return pos.y;
}



bool Clickable::WithinRegion(int x, int y) //to know if mouse will be in region
{
    return (x >= pos.x && y >= pos.y && x <= pos.x + pos.w && y <= pos.y + pos.h); //if the given co-ordinates fall within the object
}

bool Clickable::WithinRegion(SDL_Rect& pos, int x, int y)
{
    return (x >= pos.x && y >= pos.y && x <= pos.x + pos.w && y <= pos.y + pos.h);
}

bool Clickable::Collides(const SDL_Rect& rect)  //collision detection
{
    ///to determine collision between two rectangles. Logic copied from LazyFoo.
    if (pos.y + pos.h <= rect.y)
    {
        return false;
    }
    if (pos.y >= rect.y + rect.h)
    {
        return false;
    }
    if (pos.x + pos.w <= rect.x)
    {
        return false;
    }
    if (pos.x >= rect.x + rect.w)
    {
        return false;
    }
    return true;
}

bool Clickable::Collides(const int x, const int y, const int w, const int h)
{
    SDL_Rect temp;
    temp.x = x;
    temp.y = y;
    temp.w = w;
    temp.h = h;
    return Collides(temp);
}

void Clickable::ReduceSize(double n)
{
    pos.w = pos.w * n;
    pos.h = pos.h * n;
}


bool Clickable::Collides(const Clickable& obj)
{
    return Collides(obj.pos);
}

void Clickable::UpdatePos(int x,int y)
{
    pos.x = x;
    pos.y = y;
}

int Clickable::GetDistance(int x, int y)
{
    return sqrt((abs(pos.x - x)*abs(pos.x - x))+(abs(pos.y - y)*abs(pos.y - y)));
}

void Clickable::GetCenter(int& x, int& y)
{
    x = pos.x + pos.w/2;
    y = pos.y + pos.h/2;
}

bool Clickable::Collides(const SDL_Rect& rect, const SDL_Rect& pos)
{
    if (pos.y + pos.h <= rect.y)
    {
        return false;
    }
    if (pos.y >= rect.y + rect.h)
    {
        return false;
    }
    if (pos.x + pos.w <= rect.x)
    {
        return false;
    }
    if (pos.x >= rect.x + rect.w)
    {
        return false;
    }
    return true;
}
void Clickable:: SetX(int delta, int direction)
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

bool Clickable::SameScenario(const Clickable* obj)
{

    return currentScenario == obj->currentScenario;
}


void Clickable::SetScenario(Scenario* scenario)
{
    ///to determine where the object is located, i.e. indoor or outdoor
    if (currentScenario == 0)
    currentScenario = scenario;
}

bool Clickable::IsActive()
{
    return false;
}

Scenario* Clickable::GetScenario()
{
    return currentScenario;
}

int Clickable :: DelayLidTime()
{
    return 0;
}
