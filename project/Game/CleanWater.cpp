#include "CleanWater.h"

CleanWater::CleanWater(int x, int y): Container(x,y, C_WATER_WIDTH, C_WATER_HEIGHT)
{
    spriteNum = 72; //position on sprite sheet
    ReduceSize(0.25);
    id = 2;
    myLid = noOflids;
    lids[noOflids++] = new Soil(pos.x, pos.y - 100);

    percentage = 5;
    delay = 0;
    breedCount = 0;

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

void CleanWater::Show(SDL_Renderer* renderer)
{
    if (delay > 1000)
    {
        return;
    }
    if (!GetCovered())
    {
        Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    }
    //lid->Show(renderer);
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
    else
    {
        delay ++;
    }
}

bool CleanWater::IsActive()
{
    if (GetCovered())
    {
        return true;
    }
    return false;
}

Mosquito* CleanWater::Breed()
{
    breedCount++;
    return factory->GetMosquito(AEDES);
}

CleanWater::~CleanWater()
{


}

void CleanWater::Write(std::ofstream&)
{

}

int CleanWater:: DelayLidTime()
{
    delay ++;
    return delay;
}

int CleanWater :: GetBreedCount()
{
    return breedCount;
}
