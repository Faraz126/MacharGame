#include "DirtyWater.h"

DirtyWater::DirtyWater(int x, int y): Container(x,y, WATER_WIDTH, WATER_HEIGHT)
{
    spriteNum = 71;
    ReduceSize(0.25);
    id = 2;
    myLid = noOflids;
    lids[noOflids++] = new Soil(pos.x, pos.y - 90);
    percentage = 5;
    delay = 0;
    breedCount = 0;

}

void DirtyWater::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x-6,pos.y-14); //set to right ahead of trashcan.

    }

    Container::SetCovered(status);
}

bool DirtyWater :: IsActive()
{
    if (GetCovered())
    {
        return true;
    }
    return false;
}

void DirtyWater::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (!GetCovered())
    {
        for (int i =0; i < noOflids; i++)
        {

            lid = lids[i];
            if (lid != 0 && this->SameScenario(lid))
            {
                lid->HandleEvents(e, node);
            }

        }

    }

    for (int i = 0; i < noOflids; i++)
    {
        lid = lids[i];
        if (lid != 0 && this->SameScenario(lid) && lid->Collides(*this) && lid->CorrectID(this->id))
        {
            SetCovered(true);
            break;
        }
    }
}

void DirtyWater::Show(SDL_Renderer* renderer)
{
    if (!GetCovered())
    {
        Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    }

}

Mosquito* DirtyWater::Breed()
{
    breedCount++;
    return factory->GetMosquito(NORMAL);
}


void DirtyWater::Update(int)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

int DirtyWater:: DelayLidTime()
{
    delay ++;
    return delay;
}

int DirtyWater :: GetBreedCount()
{
    return breedCount;
}

DirtyWater::~DirtyWater()
{


}
