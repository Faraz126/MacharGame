#include "CleanWater.h"

CleanWater::CleanWater(int x, int y): Container(x,y, C_WATER_WIDTH, C_WATER_HEIGHT)
{
    spriteNum = 72;
    ReduceSize(0.25);
    lid = new Soil(pos.x, pos.y - 100);
    percentage = 5;
}

void CleanWater::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x-6,pos.y-14); //set to right ahead of trashcan.

    }

    Container::SetCovered(status);
}

void CleanWater::HandleEvents(SDL_Event* e, Screens_Node& node)
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

void CleanWater::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    lid->Show(renderer);
}

void CleanWater::Update(int)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}


Mosquito* CleanWater::Breed()
{
    return factory->GetMosquito(AEDES);
}

CleanWater::~CleanWater()
{
    //dtor
}

