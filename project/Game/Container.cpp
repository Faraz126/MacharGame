#include "Container.h"

Lids** Container::lids = new Lids*[50];
int Container::noOflids = 0;

Container::Container(int x, int y, int w, int h, bool status): BreedingGround(x,y,w,h) //initiating base class
{
    lid = 0;
    SetCovered(status);
}

bool Container::GetCovered()
{
    return isCovered;
}

void Container::SetScenario(Scenario* sc)
{
    Clickable::SetScenario(sc);
    for (int i = 0; i < noOflids; i++)
    {
        if (lids[i] != 0)
        {
            lids[i]->SetScenario(sc);
        }

    }
}

void Container::SetCovered(bool status)
{
    if (status && isCovered==false)
    {
        for(int i = 0; i<20; i++)
        {
            (*Score::GetInstance())++;
        }
        for(int i = 0; i<GetBreedCount(); i++)
        {
            (*Score::GetInstance())--;
        }
    }
    isCovered = status;
}

void Container:: SetX(int delta, int direction)
{
    if (lids[myLid] != 0)
    {
        lids[myLid]->SetX(delta, direction);
    }

    if ( direction == 0)
    {
        pos.x+=delta;
        correctLidPos.x += delta;

    }
    if ( direction == 1)
    {
        pos.x-=delta;
        correctLidPos.x -= delta;
    }
}

bool Container::Collides(const Clickable& obj)
{

    if (!isCovered && lid != 0 && &obj != lid)
    {
        return lid->Collides(obj) || Clickable::Collides(obj);
    }

    return Clickable::Collides(obj);
}

bool Container::Collides(const SDL_Rect& rect)
{

    if (lids[myLid] != 0)
    {
        return lids[myLid]->Collides(rect) || Clickable::Collides(rect);
    }

    return Clickable::Collides(rect);
}




Container::~Container()
{

    for (int i = 0; i < noOflids; i++)
    {
        if (lids[i] == lid)
        {
            lids[i] = 0;
        }
    }
    // delete lid;
    lid = 0;
}





