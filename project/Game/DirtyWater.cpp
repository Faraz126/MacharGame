#include "DirtyWater.h"

DirtyWater::DirtyWater(int x, int y): Container(x,y, WATER_WIDTH, WATER_HEIGHT)
{
    spriteNum = 71;
    ReduceSize(0.25);
    lid = new Soil(pos.x, pos.y - 100);
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
}

void DirtyWater::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (!GetCovered())
    {
        lid->HandleEvents(e,node);
    }
    if (lid->Collides(*this))
    {
        SetCovered(true);
    }
}

void DirtyWater::Show(SDL_Renderer* renderer)
{
    if (!GetCovered())
    {
        Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    }
    lid->Show(renderer);
}

Mosquito* DirtyWater::Breed()
{
    breedCount++;
    return factory->GetMosquito(MALARIA);
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
    //dtor
}
